/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 May 2019
AIM    : write a recursive function to test if a given array is palindrome or not
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool checkPalindrome(int arr[], int start, int end){
	// check palindrome reursively

	if(arr[start]==arr[end]){  	// if first and last elements match
		if(start+1<=end-1) 		// if more elements are remaining
			return checkPalindrome(arr, start+1, end-1); 	//then go forward
		else return true;		// else success
	}
	else	return false;		// first and last elements not equal, then failure
}

int main(){

int n; 		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++){ 		// input the array
	cin>>arr[i];
}

checkPalindrome(arr, 0, n-1)?cout<<"true"<<endl:cout<<"false"<<endl; 	// check palindrome

return 0;
}