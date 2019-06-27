/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : binary search on array - recursive
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int key){
	
	if(s>e)	return -1;

	int mid = (s+e)/2;
	if(arr[mid] == key)		return mid;
	if(arr[mid]>key)	return binarySearch(arr, s, mid-1, key);
	return binarySearch(arr, mid+1, e, key);
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];		// get the array elements
for(int i=0; i<n; i++)
	cin>>arr[i];

int key;	// get the search key
cin>>key;

cout<<binarySearch(arr, 0, n-1, key)<<endl;

return 0;
}