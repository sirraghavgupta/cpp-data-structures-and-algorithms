/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : binary search on array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
	int start=0, end=n-1;
	int mid;

	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid] == key)		return mid;
		else if(arr[mid]>key)	end=mid-1;
		else 	start=mid+1;
	}
	return -1;
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];		// get the array elements
for(int i=0; i<n; i++)
	cin>>arr[i];

int key;	// get the search key
cin>>key;

int searchIndex = binarySearch(arr, n, key);
if(searchIndex<0)
	cout<<"value not found"<<endl;
else
	cout<<"value found at "<<searchIndex<<endl;

return 0;
}