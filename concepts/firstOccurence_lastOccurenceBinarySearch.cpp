/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : june 2019
AIM    : to find the first occurence index of a key in a sorted array using 
		 binary search
		 example - 1 2 2 2 2 2 5
		 	lowerbound = 1
		 	upperbound = 6
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key){
	int start=0, end=n-1;
	int mid, ans=-1;		// initially element not found, so ans=-1

	while(start<=end){	
		mid = (start+end)/2;
		if(arr[mid]==key){		// if element is found, then reject the right half and 
								// search for occurences BEFORE that as we want lower bound
			ans = mid;
			end = mid-1;
		}
		else if(arr[mid]<key)	// rest all is same as binar search
			start = mid+1;
		else
			end = mid-1;
	}
	return ans;
}
// ------------------------------------------------
int lastOccurence(int arr[], int n, int key){
	int start=0, end=n-1;
	int mid, ans=-1;

	while(start<=end){	
		mid = (start+end)/2;
		if(arr[mid]==key){		// if element is found, then reject the right half and 
								// search for occurences AFTER that as we want upper bound
			ans = mid;
			start = mid+1;
		}
		else if(arr[mid]<key)
			start = mid+1;
		else
			end = mid-1;
	}
	return ans;
}
// -------------------------------------------------


int main(){

int n;		// size of array
cin>>n;

int arr[n];		// get the array elements
for(int i=0; i<n; i++)
	cin>>arr[i];

int key;	// get the search key
cin>>key;

// for lower bound and upper bound
int lowerBound = firstOccurence(arr, n, key);
int upperBound = lastOccurence(arr, n, key);

if(lowerBound<0)
	cout<<"value not found"<<endl;
else
	cout<<"value found in range "<<lowerBound<<", "<<upperBound<<endl;

return 0;
}