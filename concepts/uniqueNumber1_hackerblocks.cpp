/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : We are given an array containg n numbers. All the numbers are present 
		 twice except for one number which is only present once. Find the unique 
		 number without taking any extra spaces and in linear time. 
		 ( Hint - Use Bitwise )
STATUS : !!! success !!! ---- not running on 4.-- version of gcc
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int arr[n];		// read the numbers
for(int i=0; i<n; i++)
	cin>>arr[i];

int i;
for(i=0; i<n; i+=2){	// check for the consecutive numbers
						// bitwise and of 2 equal numbers is the number itself  
	int num1, num2;
	num1 = arr[i];
	num2 = arr[i+1];
	int num3 = num1&num2;
    
	if(num3 != num1){
			cout<<num1<<endl;
			return 0;	
	}
}

return 0;
}