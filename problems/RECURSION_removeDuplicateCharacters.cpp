/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 july 2019
AIM    : Take as input S, a string. Write a function that removes all consecutive 
		 duplicates. Print the value returned.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

char* removeDuplicates(char *inp, int i, char*out, int j){
	// base case
	if(inp[i]=='\0'){
		out[j]='\0';
		return out;
	}

	// Rec case
	if(inp[i]==out[j-1]){		// if same character is already there in output
		i++;					// skip tat character
	}
	else{						// if different character is there
		out[j++]=inp[i++];
	}
	return removeDuplicates(inp, i, out, j);	// next rec call
}

int main(){

char inp[1001];
cin>>inp;

char out[1001];
	
cout<<removeDuplicates(inp, 0, out, 0)<<endl;

return 0;
}