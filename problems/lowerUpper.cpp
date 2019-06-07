/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : Print "lowercase" if user enters a character between 'a-z' , Print 
		 "UPPERCASE" is character lies between 'A-Z' and print "Invalid" for all  
		  other characters like $,.^# etc.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

char ch;
cin>>ch;

int ascii=int(ch);		// typecast into integer

if(ascii>=97 && ascii<=122)		cout<<"lowercase"<<endl;
else if(ascii>=65 && ascii<=90)		cout<<"UPPERCASE"<<endl;
else 	cout<<"Invalid"<<endl;

return 0;
}