/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : One of the important aspect of object oriented programming is 
		 readability of the code. To enhance the readability of code, developers 
		 write function and variable names in Camel Case. You are given a string, 
		 S, written in Camel Case. FindAllTheWordsContainedInI
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

char str[1001];		// get string
cin>>str;

int length = strlen(str);

for(int i=0; i<length; i++){
	cout<<str[i];
	if( int(str[i+1])>=65 && int(str[i+1])<=90 )
		cout<<endl;
	}
cout<<endl;

return 0;	
}