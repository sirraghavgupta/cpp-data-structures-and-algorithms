/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : wave sort
		 sort the elements in the form of a wave starting from maxima
		 multiple answers possible for multiple approaches 
		 example - 1 3 4 2 7 8
		 answer  - 3 1 4 2 8 7
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


void waveSort(int arr[], int n){
  // go to every second element and try to make a peak.
	for(int i=0; i<n; i+=2){
		if(i>0 && arr[i]<arr[i-1])
			swap(arr[i], arr[i-1]);
	
		if(i<n-1 && arr[i]<arr[i+1])
			swap(arr[i], arr[i+1]);
	}
}

int main(){

int n;		// size of array
cin>>n;

int arr[n];
for(int i=0; i<n; i++)		// read array
	cin>>arr[i];

waveSort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}