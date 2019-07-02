/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 july 2019
AIM    : to generate all the subsequences of a string by using recursion.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <string.h>
using namespace std;

void generateSubsequences(char *input, char *output, int i, int j, int *count){
	// base case
	if(input[i]=='\0'){  // input string is finished 
		output[j]='\0';  // terminate the output string also
		cout<<output<<endl;		// and print and move back 
		*count+=1;
		return;
	}

	// Rec case
	// 1.character included
	output[j] = input[i];
	generateSubsequences(input, output, i+1, j+1, count);

	// 2.character not included
	generateSubsequences(input, output, i+1, j, count);

}

int main(){

char input[100];
cin>>input;

char output[100];
int count=0;
generateSubsequences(input, output, 0, 0, &count);
cout<<count<<endl;

return 0;
}