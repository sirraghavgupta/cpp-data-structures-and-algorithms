/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : to check for palindrome of any kind of input RECURSIVELY
		 -- me: for any input - string will do 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool isPalindrome(char *str, int left, int right){
	
	if(left>=right)
		return true;
	else
		if(str[left] == str[right])
			return isPalindrome(str, left+1, right-1);
		else return false;	
}

int main(){

char str[100];		// get string
int size;
cin>>size;

for(int i=0; i<size; i++){
	cin>>str[i];
}

isPalindrome(str, 0, size-1)?cout<<"true"<<endl:cout<<"false"<<endl;	

return 0;	
}