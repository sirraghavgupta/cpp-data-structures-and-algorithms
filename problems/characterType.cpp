/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : A character (ch) Write a function that returns ‘U’, if it is uppercase;
		 ‘L’ if it is lowercase and ‘I’ otherwise. Print the value returned.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

char charType(char ch){
	int ascii=int(ch);		// typecast into integer

	if(ascii>=97 && ascii<=122)		return 'L';
	else if(ascii>=65 && ascii<=90)		return 'U';
	else 	return 'I';
}

int main(){

char ch;
cin>>ch;
cout<<charType(ch)<<endl;

return 0;
}