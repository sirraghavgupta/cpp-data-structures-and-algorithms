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

sort(arr, arr+size);

for(int i=0; i<size-2; i++){	// choose first number
	
// now, generate required pairs from the remaining part of array using the targetSumPairs program
  int l=i+1, r=size-1;
	while(l<r){
	if(arr[l]+arr[r]==(target-arr[i])){
		cout<<arr[i]<<", "<<arr[l]<<" and "<<arr[r]<<endl;
		r--;
		l++;
	}
	else if(arr[l]+arr[r]<target-arr[i])
		l++;
	else
		r--;

}
}

return 0;
}