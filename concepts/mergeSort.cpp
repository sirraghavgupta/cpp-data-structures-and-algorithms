/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 june 2019
AIM    : to implement merge sort algorithm using recursion
STATUS : !!! success !!!
TIME   : O(NlogN)
##############################################################################*/

#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h){
  // merges 2 sorted arrays
	int i=l, j=mid, k=l;
	int mergedArr[h];

	// normal merging of both arrays based on comparison
	while(i<mid && j<h){
		if(arr[i]<=arr[j]){
			mergedArr[k]=arr[i];
			i++;
		}
		else{
			mergedArr[k]=arr[j];
			j++;
		}
		k++;
	}

	// if first half finished earlier, copy remaining right half
	if(i==mid){
		for(int p=j; p<h; p++){
			mergedArr[k]=arr[p];
			k++;
		}
	}

	// if second half finished earlier, copy remaining left half
	if(j==h){
		for(int p=i; p<mid; p++){
			mergedArr[k]=arr[p];	
			k++;
		}
	}

	// after completing merging
	for(int k=l; k<h; k++)
		arr[k] = mergedArr[k];
}

void mergeSort(int arr[], int l, int h){
  // applies merge sort recurively on the array
	// base case
	if(l==(h-1))
		return;

	// rec case
	int mid = (l+h)/2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid, h);
	merge(arr, l, mid, h);
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

mergeSort(arr, 0, n);

for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}