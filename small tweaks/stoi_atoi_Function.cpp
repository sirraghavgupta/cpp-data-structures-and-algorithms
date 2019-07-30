/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : use stoi and atoi function
		 - Work only if compiler supports C++11 or above. 
STATUS : !!! success !!!
##############################################################################*/

/*
-----  stoi() vs atoi()  -----
- atoi() is a legacy C-style function. stoi() is added in C++ 11.
- atoi() works only for C-style strings (character array and string literal), stoi() 
  works for both C++ strings and C style strings
- atoi() takes only one parameter and returns integer value.
- stoi() can take upto three parameters, the second parameter is for starting index 
  and third parameter is for base of input number.
*/

#include <iostream>
using namespace std;

int main(){

	string str1 = "45"; 
	string str2 = "3.14159"; 
	string str3 = "331337 geek"; 
	// string str3 = "raghav 31337 geek"; --- gives runtime error

	// The stoi() function takes a string as an argument and returns its value
	int myint1 = stoi(str1); 
	int myint2 = stoi(str2); 
	int myint3 = stoi(str3); 

	cout<<"conversion of "<<str1<<" is "<<myint1<<endl;
	cout<<"conversion of "<<str2<<" is "<<myint2<<endl;
	cout<<"conversion of "<<str3<<" is "<<myint3<<endl;

	// The atoi() function takes a character array or string literal as an 
	// argument and returns its value
	const char *str4 = "42"; 
    const char *str5 = "3.14159"; 
    const char *str6 = "31337 geek"; 
     
    int num1 = atoi(str4); 
    int num2 = atoi(str5); 
    int num3 = atoi(str6); 

	cout<<"conversion of "<<str4<<" is "<<num1<<endl;
	cout<<"conversion of "<<str5<<" is "<<num2<<endl;
	cout<<"conversion of "<<str6<<" is "<<num3<<endl;    

	return 0; 
} 