/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : insertion sort
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


void insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){		// iterate n-1 times to sort n-1 elements
		int pickedVal = arr[i];
		int j=i-1;

		while(j>=0 && arr[j]>pickedVal){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = pickedVal;
	}
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++)		// read array
	cin>>arr[i];

insertionSort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}