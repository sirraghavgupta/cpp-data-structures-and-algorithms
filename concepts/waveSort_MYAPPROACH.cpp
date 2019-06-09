/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : wave sort
		 sort the elements in the form of a wave starting from maxima
		 multiple answers possible for multiple approaches 
		 example - 1 3 4 2 7 8
		 answer  - 3 1 4 2 8 7
STATUS : !!! success !!!
NOTE ------ this approach is not preferrable becuase it is based on sorting and
		    takes more tim
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
	for(int i=0; i<n; i++){
		if(i%2==0){
			int maxI=i;
			for(int j=i+1; j<n; j++){
				if(arr[j]>arr[maxI])
					maxI=j;
			}
			swap(arr[i], arr[maxI]);
		}
		else{
			int minI=i;
			for(int j=i+1; j<n; j++){
				if(arr[j]<arr[minI])
					minI=j;
			}
			swap(arr[i], arr[minI]);
		}
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