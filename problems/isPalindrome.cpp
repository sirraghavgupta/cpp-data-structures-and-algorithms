/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : Take as input N, a number. Take N more inputs and store that in an array. 
		 Write a recursive function which tests if the array is a palindrome and 
		 returns a Boolean value. Print the value returned.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool isPalindrome(int *arr, int size){
	
	for(int i=0; i<size/2; i++){
		if(arr[i]!=arr[size-i-1]) 
			return false;
	}
	return true;	
}

int main(){

int arr[1000];		// get string
int size;
cin>>size;

for(int i=0; i<size; i++)	// read array
	cin>>arr[i];

isPalindrome(arr, size)?cout<<"true"<<endl:cout<<"false"<<endl;	

return 0;	
}