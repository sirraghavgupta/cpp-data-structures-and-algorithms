/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 june 2019
AIM    : bubble sort by using recursion
STATUS : !!! success !!!

APPROACH : we will bubble up the biggest element in the array and call bubble 
		   sort on smaller array
##############################################################################*/

#include <iostream>
using namespace std;

/*void bubbleSort(int arr[], int n){	// half recursive
	// base case
	if(n==1)		
		return;

	// sort one element and call for remaining n-1 elements.
	for(int j=0; j<n-1; j++){		 
		if(arr[j]>arr[j+1])	
			swap(arr[j], arr[j+1]);		
	}
	bubbleSort(arr, n-1);
}*/


void bubbleSort(int arr[], int j, int n){	// fully recursive
	// base case
	if(n==1)		// if array finished, then return, no soring required
		return;
	if(j==n-1)		// if one iteration complete, begin next on smaller array
		return bubbleSort(arr, 0, n-1);	

	// rec case
	if(arr[j]>arr[j+1])	
		swap(arr[j], arr[j+1]);
	return bubbleSort(arr, j+1, n);
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++)		// read array
	cin>>arr[i];

bubbleSort(arr, 0, n);

for(int i=0; i<n; i++)		// print the elements
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}