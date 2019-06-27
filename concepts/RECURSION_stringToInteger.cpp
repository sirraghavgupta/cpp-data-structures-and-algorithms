/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to convert a string to integer using recursion
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <string.h>
using namespace std;

int stoi(char *s, int len){
	if(len==1){		// if length of string is 1
		return *s - '0';	// return the only digit
	}
	int ans = s[len-1]-'0' + 10*stoi(s, len-1);
	return ans;
}	

int main(){

char s[10];
cin>>s;
int num=stoi(s, strlen(s));
cout<<num<<endl;

return 0;
}	