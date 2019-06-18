/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to generate all the subsequences of a string by using bitmasking.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <string.h>
using namespace std;

void printSubset(char*a, int mask){	
	// print the string given the mask
	// note that we are printing in reverse order according to mask, for ease.
	for(int i=0; i<strlen(a); i++){
		(mask&1)?cout<<a[i]:cout<<"";	
		mask = mask>>1;
	}
	cout<<endl;
}

void generateSubsets(char *a){
	int length = strlen(a);
	int range = (1<<length)-1;	// number of subsequences possible - power(2,n)
	
	for(int i=0; i<=range; i++){	// treat every number as a mask for the string
		printSubset(a, i);
	}
}

int main(){

char str[100];
cin>>str;

generateSubsets(str);

return 0;
}