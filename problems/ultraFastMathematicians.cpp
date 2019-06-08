/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : to find the xor of two numbers given in binaru form
		 dont omit the leading zeros
		  --- refer to string challenges section in course 
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int t;
cin>>t;

while(t>0){

	char num1[65];
	char num2[65];
	char res[65];

	cin>>num1;		// read binary numbers in the form of strings
	cin>>num2;

	int length=strlen(num1);
	for(int i=0; i<length; i++){
		if(num1[i]==num2[i])
			res[i]='0';
		else
			res[i]='1';
	}
	res[length]='\0';		// terminate the output string
	cout<<res<<endl;

t--;
}

return 0;
}