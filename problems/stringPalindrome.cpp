/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : to check for string palindrome
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool isPalindrome(char *str){
	int length = strlen(str);
	
	for(int i=0; i<length/2; i++){
		if(str[i]!=str[length-i-1]) 
			return false;
	}
	return true;	
}

int main(){

char str[1001];		// get string
cin>>str;

cout<<isPalindrome(str)<<endl;

return 0;	
}