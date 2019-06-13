/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 june 2019
AIM    : to find the pivot element in a sorted rotated array by usingbinary search
STATUS : !!! success !!!
NOTE   : pivot is always the greatest element in a sorted rotated array
		 its the turning breakpoint in the pattern 
##############################################################################*/

#include <iostream>
using namespace std;


int findPivot(int arr[], int n){
	int start=0, end=n-1;

	while(start<=end){		
		int mid=(start+end)/2;

		if( mid<end && arr[mid]>arr[mid+1])		// if pivot lies at mid
			return mid;

		if( mid>start && arr[mid]<arr[mid-1])	// if pivot lies just before mid
			return mid-1;

	// lookup in the left unsorted part
		if(arr[start]>=arr[mid]) 	// left part is unsorted
			end=mid-1;
			
		else						// right part is unsorted
			start=mid+1;
	}	
	if(start>end)
		return -1;
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

cout<<findPivot(arr, n)<<endl;

return 0;
}