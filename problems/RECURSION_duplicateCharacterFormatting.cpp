/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 july 2019
AIM    : Take as input str, a string. Write a recursive function which returns 
		 a new string in which all duplicate consecutive characters are separated 
		 by a '' * '. E.g. for "hello" return "hel*lo". Print the value returned.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

char* formatDuplicates(char *inp, int i, char*out, int j){
	// base case
	if(inp[i]=='\0'){
		out[j]='\0';
		return out;
	}

	// Rec case
	if(inp[i]==inp[i+1]){		// if same character is there
		out[j++]=inp[i++];
		out[j++]='*';
	}
	else{						// if different character is there
		out[j++]=inp[i++];
	}
	return formatDuplicates(inp, i, out, j);	// next rec call
}

int main(){

char inp[100];
cin>>inp;

char out[100];
	
cout<<formatDuplicates(inp, 0, out, 0)<<endl;

return 0;
}