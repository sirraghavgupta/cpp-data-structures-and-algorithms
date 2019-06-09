/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : bubble sort
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){
	for(int i=0; i<n-1; i++){		// iterate n-1 times to sort n-1 elements
		for(int j=0; j<n-i-1; j++){		 // find the ith greatest element in ith iteration
			int temp;
			if(arr[j]>arr[j+1]){	// if swapping required
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++)		// read array
	cin>>arr[i];

bubbleSort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}