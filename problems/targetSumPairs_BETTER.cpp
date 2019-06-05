/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : print all the pairs in an array whosesum is equal to a particular number
		 target
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

int l=0;		// left pointer
int r=size-1;	// right pointer

sort(arr, arr+size);


/* 
	we first sort the array ----------- MAIN THING 
	then two pointers are there,
		left = points to the beginning of the array
		right = points to the end of the array
	if sum of corresponding elements is equal to targte, then print them, 
		increment l and decrement r for next iteration
	
	if sum is smaller than the target, then increment l

	if sum is greater than the target, then decrement r

*/
while(l<r){
	if(arr[l]+arr[r]==target){
		cout<<arr[l]<<" and "<<arr[r]<<endl;
		r--;
		l++;
	}
	else if(arr[l]+arr[r]<target)
		l++;
	else
		r--;

}

return 0;
}