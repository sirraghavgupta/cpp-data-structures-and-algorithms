/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 july 2019
AIM    : to implement randomised quick sort 
STATUS : !!! success !!!
NOTE   : - we need this to reduce the worst case complexity of quick sort when 
	       the array is completely sorted.
	     - the complexity of randomised quick sort is always NlogN
	     - we should always use quick sort with randomisation
TIME   : O(nlogn) always unlike normal quick sort
##############################################################################*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void shuffleArray(int arr[], int s, int e){

	srand(time(NULL));		// initialise the random function

	for(int i=e; i>0; i--){	// strategy discussed in notebook
		int index = rand()%(i+1);
		swap(arr[index], arr[i]);
	}
}

int partition(int arr[], int s, int e){

	int pivot = arr[e];		//take last element to be pivot
	int i=s-1;		// intially points to -1 index
					// holds the index of the last element in the sorted part of array
					// initially the sorted part is empty.

	for(int j=s; j<=e-1; j++){	//separate the sorted and unsorted part
		if(arr[j]<pivot){
			i++;
			swap(arr[j], arr[i]);
		}
	}
	swap(arr[e], arr[i+1]);  	//bring pivot to its actual position
	return i+1;		// return the index of pivot element
}


void quickSort(int arr[], int s, int e){
	//base case
	if(s>=e)
		return;
	// recursive case
	int pivot = partition(arr, s, e);
	quickSort(arr, s, pivot-1);
	quickSort(arr, pivot+1, e);
}


int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

shuffleArray(arr, 0, n-1);
// print the shuffled array
// for(int i=0; i<n; i++)
// 	cout<<arr[i]<<" ";
// cout<<endl;	

quickSort(arr, 0, n-1);

for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
cout<<endl;	

return 0;
}