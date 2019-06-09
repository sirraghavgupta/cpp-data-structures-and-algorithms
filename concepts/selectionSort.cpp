/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : selection sort
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int temp;
		temp = *a;
		*a = *b;
		*b = temp;
}

void selectionSort(int arr[], int n){
	for(int i=0; i<n-1; i++){		// iterate n-1 times to sort n-1 elements
		int minIndex=i;
		for(int j=i+1; j<n; j++){		 // find the perfect element for ith position
			if(arr[j]<arr[minIndex])	// if swapping required
				minIndex=j;
		}
		swap(arr[i], arr[minIndex]);
	}
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++)		// read array
	cin>>arr[i];

selectionSort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}