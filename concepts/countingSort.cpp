/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 june 2019
AIM    : counting sort
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void countingSort(int arr[], int n){
	int *freq;
	freq = new int[1000005];

	for(int i=0; i<1000005; i++)	// initialise the freq array to 0
		freq[i]=0;

	for(int i=0; i<n; i++){		// build the frequency array
		int index = arr[i];
		freq[index]++;
	}	

	int j=0;    // pointer to main array
	for(int i=0; i<1000005; i++){	// overwrite the sorted array
		if(freq[i]!=0){
			int count=freq[i];
			while(count>0){
				arr[j]=i;
				j++;
			count--;
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

countingSort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}