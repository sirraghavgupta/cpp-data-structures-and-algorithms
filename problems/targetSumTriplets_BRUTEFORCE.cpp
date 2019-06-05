/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : write a function which prints all triplets of numbers which sum to target.
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

int size;			// size of array
cin>>size;
 
int arr[size];		// read the numbers into an array
for(int i=0; i<size; i++){
	cin>>arr[i];
}

int target;			// target sum
cin>>target;

sort(arr, arr+size);	// sorting is done just because i want to display the triplets
						// ascending order

// check for all possile combinations 
for(int i=0; i<size-2; i++){	// choose first element 
			// two elements should be remaining to choose from, so take upto size-2			
	for(int j=i+1; j<size-1; j++){		// choose second element
				// two elements should be remaining to choose from, so take upto size-1
		for(int k=j+1; k<size; k++){		// choose third element
			if(arr[i]+arr[j]+arr[k]==target)	
				cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
		}
	}
}
return 0;
}