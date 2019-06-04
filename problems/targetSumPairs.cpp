/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 june 2019
AIM    : print all the pairs in an array whosesum is equal to a particular number
		 target
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
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

for(int i=0; i<size-1; i++){	    // find first num of pair
	for(int j=i+1; j<size; j++){	// find second number of pair
		if(arr[i]+arr[j] == target){	
			if(arr[i]<arr[j])	// print smaller number first
				cout<<arr[i]<<" and "<<arr[j]<<endl;
			else
				cout<<arr[j]<<" and "<<arr[i]<<endl;
		}
	}
}

return 0;
}