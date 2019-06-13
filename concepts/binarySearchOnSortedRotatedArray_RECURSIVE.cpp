/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 11 june 2019
AIM    : to apply binary search on sorted rotated array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int binSearchRotated(int arr[], int start, int end, int key){
	// base case
	if(start>end)	return -1;

// ------------ RECURSIVE CASES --------------
	// direct found
	int mid=(start+end)/2;
	if(arr[mid]==key)
		return mid;

	// if left branch is big
	else if(arr[start]<=arr[mid]){	// if key lies in sorted part
		if(key>=arr[start] && key<=arr[mid])	
			return binSearchRotated(arr, start, mid-1,key);
		return binSearchRotated(arr, mid+1, end, key);
	}
	// if right branch is big
	if(key<=arr[end] && key>=arr[mid])	// if key lies in sorted part
		return binSearchRotated(arr, mid+1, end, key);
	return binSearchRotated(arr, start, mid-1, key);
}


int main(){

int n;		// number of elements
cin>>n;
int arr[n];		// read the array
for(int i=0; i<n; i++)
	cin>>arr[i];

int key;	// element to be searched
cin>>key;

int index = binSearchRotated(arr, 0, n-1, key);
(index>=0)?cout<<"element found at "<<index<<endl:cout<<"element not found"<<endl;

return 0;
}