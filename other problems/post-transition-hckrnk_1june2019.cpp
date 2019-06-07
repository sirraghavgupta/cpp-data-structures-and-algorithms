/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 june 2019
AIM    : hackerrank post transition problem
STATUS : !!! success !!! 

LEARNINGS : ------------------------ SEE IN COMMENTS -------------------------
##############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;		// just a pointer, and then allocate memory to it dynamically
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages; 	// a pointer of an array of package type objects
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;		// pointer for name, allocate memory dynamically later on
	post_office* offices;
	int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {

		printf("%s:\n", t.name);		
		for(int j=0; j<t.offices_count; j++){ 	// go inside the offices of this town
			printf("\t%d:\n", j);
			for(int k=0; k<t.offices[j].packages_count; k++){  // get the pkgs of each office
				printf("\t\t%s\n", t.offices[j].packages[k].id);

/* 
here, i first wrote %c and used *t.offices[j].packages[k].id to print the id of the package.
but, it could print only single character ids, because i used %c.

now, i again tried with %s, but then it created the problem, because %s demands and address and
i am giving a value by *t.offices[j].packages[k].id which lead to a run time error

now what i tried %s without * and it worked fine because i am giving an adress and it works for
single character ids also because string includes that also. 
*/
			}
		}
	}



void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {	

// for easy reference, get the min amd max weight of the target
// and the initial pckgs in the source and the target
	int min_weight = target->offices[target_office_index].min_weight;
	int max_weight = target->offices[target_office_index].max_weight;
	int loop_count = source->offices[source_office_index].packages_count;
	int initial_pcks_with_target = target->offices[target_office_index].packages_count;

// create separate source and target array for packages 
	package *source_package = (package*)malloc(sizeof(package));
	int source_package_size = 0;

	package *target_package = (package*)malloc(initial_pcks_with_target*sizeof(package));
	int target_package_size = initial_pcks_with_target;


// copy the initial contents in the target package array
	for(int i=0; i<initial_pcks_with_target; i++){
		target_package[i] = target->offices[target_office_index].packages[i];
	}

/* loop through the orignal source package array and look.. 
	if the package is valid, add it to the new target array and update its own count
	else add it to the new source array and update its own count

	finally , after loop, free the original pkg arrays with the new ones by reassigning the 
	pointer and also update the corresponding packages_count of the source and target offices.
*/
	for(int i=0; i<loop_count; i++){

		if((source->offices[source_office_index].packages[i].weight <= max_weight) && (source->offices[source_office_index].packages[i].weight >= min_weight)){
				target_package_size++;
				target_package = (package*)realloc(target_package, target_package_size*sizeof(package));
				target_package[target_package_size-1]=source->offices[source_office_index].packages[i];
		}

		else{
				source_package_size++;
				source_package = (package*)realloc(source_package, source_package_size*sizeof(package));
				source_package[source_package_size-1]=source->offices[source_office_index].packages[i];
		}
	}

	free(source->offices[source_office_index].packages);
	free(target->offices[target_office_index].packages);

	// replacement 
	source->offices[source_office_index].packages = source_package;
	source->offices[source_office_index].packages_count = source_package_size;

	target->offices[target_office_index].packages = target_package;
	target->offices[target_office_index].packages_count = target_package_size;

}

town town_with_most_packages(town* towns, int towns_count) {
	int max=-1, max_index=-1;
	
	for(int i=0; i<towns_count; i++){
		int count=0;
		for(int j=0; j<towns[i].offices_count; j++){
			count+=towns[i].offices[j].packages_count;
		}
	
		if(count>max){
			max=count;
			max_index=i;
		}
	}
	// printf("max value found is %d at %d\n",count,max_index);
	return towns[max_index];
}

town* find_town(town* towns, int towns_count, char* name) {

	int i;
	for(i=0; i<towns_count; i++){
		if(!strcmp(towns[i].name, name)){
			break;
		}
	}
	return towns+i;		// return the pointer to the town object
}

int main()
{
	int towns_count;		// get total number of towns
	scanf("%d", &towns_count);

	town* towns = (town*)malloc(sizeof(town)*towns_count);		// data of towns

	// read the complete data of towns with offices and packages 
	for (int i = 0; i < towns_count; i++) { 	// for all towns

		towns[i].name = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);		// get name of town	

		scanf("%d", &towns[i].offices_count);		// get total offices in town

		towns[i].offices = (post_office*)malloc(sizeof(post_office)*towns[i].offices_count);


		for (int j = 0; j < towns[i].offices_count; j++) {

			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			
			towns[i].offices[j].packages = (package*)malloc(sizeof(package)*towns[i].offices[j].packages_count);
			
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}



	int queries;
	scanf("%d", &queries);
	
	char town_name[MAX_STRING_LENGTH];
	
	while (queries--) {
		int type;
		scanf("%d", &type);

		switch (type) {

		case 1:
			scanf("%s", town_name);
			town* t;
			t=find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		
		case 2:
			scanf("%s", town_name);
			town* source;
			source= find_town(towns, towns_count, town_name);

			int source_index;
			scanf("%d", &source_index);
			
			scanf("%s", town_name);
			town* target;
			target=find_town(towns, towns_count, town_name);
			
			int target_index;
			scanf("%d", &target_index);
			
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}



	// free up all memory of the program
	for(int i=0; i<towns_count; i++){
		// free the contents of town
		free(towns[i].name);
		for(int j=0; j<towns[i].offices_count; j++){
			// free the contents of offices
			for(int k=0; k<towns[i].offices[j].packages_count; k++){
				// free the contents of packages
				free(towns[i].offices[j].packages[k].id);
			}
			free(towns[i].offices[j].packages);
		}
		free(towns[i].offices);
	}
	free(towns);
	return 0;
}
