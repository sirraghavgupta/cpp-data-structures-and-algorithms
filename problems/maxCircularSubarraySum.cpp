/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 june 2019
AIM    : You are provided n numbers (both +ve and -ve). Numbers are arranged in 
         a circular form. You need to find the maximum sum of consecutive number.
         -- u can go circular also
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int kadanesAlgo(int arr[], int n){
	int cs=0, ms=0;	// maxLsum is the sum of the linear max Sum sub-array
	for(int i=0; i<n; i++){
  		cs+=arr[i];
  		if(cs<0)   cs=0;
  		ms=max(ms, cs);
	}
return ms;
}


int main(){

int arr[100];

int n;		// size of array
cin>>n;
int totsum=0;

for(int i=0; i<n; i++){		// read the array
	cin>>arr[i];
	totsum+=arr[i];
}

// find the maximum linear subarray sum by kadane's algo
int maxLsum =kadanesAlgo(arr, n);	

//inverting the array
for(int i=0; i<n; i++){
	arr[i] = -arr[i];
}

// kadane's algo on inverted array
// here i calculate the minimum subarray sum of the main array
int maxIsum=kadanesAlgo(arr, n);


// find the maximum circular sum 
/* 
	here, we remove the minimum subarray from the main array and hence the remaining array will
	be the circular array with some sum.
	here, i have the ability to go circular, but not compulsory, so the maximum circular
	sum to be returned will be the greater one out of the linear sum and the circular sum.

	note that the max circular subarray can be the whole array itself with totSum as the sum.
	in that case, nothing is special, that would be counted in the linear subarray itself.
*/

int maxCsum;
maxCsum = totsum + maxIsum;						// only circular max sum
maxCsum = (maxCsum>maxLsum)?maxCsum:maxLsum;	// overall maximum sum


cout<<maxCsum<<endl;
return 0;
}