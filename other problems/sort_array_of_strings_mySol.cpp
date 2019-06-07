/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : hackerrank "sort array of strings" problem 
		 to write a sorting function which takes pointer to a comparison function
		 which determines the type of sorting. 
		 just like the inbuilt sorting function in algorithm header
		 -------- see the problem page in the folder ---------
STATUS : !!! success !!!
##############################################################################*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lexicographic_sort(const char* a, const char* b) {
	return strcmp(a,b)>0; 
}

int lexicographic_sort_reverse(const char* a, const char* b) {
	return strcmp(a,b)<0; 	
}

int sort_by_number_of_distinct_characters(const char* a, const char* b){
    
	int sizeA=strlen(a);
	int sizeB=strlen(b);

	int freqA[26];				// frequency array of string a
	for(int i=0; i<26; i++){
		freqA[i]=0;
	}

	int freqB[26];				// frequency array of string b
	for(int i=0; i<26; i++){
		freqB[i]=0;
	}

	int countA=0;				// count of distinct characters
	int countB=0;

	for(int i=0; i<sizeA; i++){		// counting for string a
		int index = a[i] - 'a';
		if(freqA[index]==0){
			freqA[index]=1;
			countA++;
		}
	}
	for(int i=0; i<sizeB; i++){		// counting for string b
		int index = b[i] - 'a';
		if(freqB[index]==0){
			freqB[index]=1;
			countB++;
		}
	}

	if(countA==countB)
		return strcmp(a,b)>0;
	else 
		return countA>countB;
}	

int sort_by_length(const char* a, const char* b) {
	if(strlen(a)!=strlen(b))
		return strlen(a)>strlen(b);
	else
		return lexicographic_sort(a,b);
}


void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
	for(int i=0; i<len-1; i++){
     for(int j=i+1; j<len; j++){
      // char temp[1024];
     	char *temp;
      if(cmp_func(arr[i],arr[j])){
      	temp=arr[i];
      	arr[i]=arr[j];
      	arr[j]=temp;
        // strcpy(temp,arr[j]);
        // strcpy(arr[j],arr[i]);
        // strcpy(arr[i],temp);

 // ------------------------------------------------------------------------------------------
 // ---------- ===========  never swap strings like this ============ -------------------------
 //     	the best method to swap strings is by playing with the pointers, not by copying 
 ///     	and pasting string values
 // ------------------------------------------------------------------------------------------

      }
    }
  }	
}


int main() 
{
    int n;					// number of strings
    scanf("%d", &n);
  
    char** arr;				// string array
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));	// allocate memory for each string
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);// reallocate the strings space
    }
  	// printf("\n\n");
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)		// printing the string
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}