/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 may 2019
AIM    : to find out the biggest even number possible by swapping only 2 digits
		 in an odd number whose length can be from 2 to 2*100000
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cstring>
using namespace std;

void charSwap(char *str, int i){
	// swap char the ith location in string with the last char of the string
	int length = strlen(str); 	// get length of string
	char temp;
	temp=str[length-1];
	str[length-1]=str[i];
	str[i]=temp;
}

int main(){

char number[200000];
char currResult[200000]; 		//numcopy initially
char max[200000]="0";
cin>>number;
strcpy(currResult,number);

// cout<<number<<endl;
// cout<<max<<endl;
// return 0;

int length = strlen(number);
// cout<<length<<endl;
for(int i=0; i<length; i++){
	if(number[i]=='0' || number[i]=='2' || number[i]=='4' || number[i]=='6' || number[i]=='8'){			// if number is even
		charSwap(currResult,i); 
		if(strcmp(currResult, max)>0){
			strcpy(max,currResult);
			strcpy(currResult,number);
		}
	}
}

if(strcmp(max,"0")==0)	cout<<"-1"<<endl;
else	cout<<max<<endl;

return 0;
}
