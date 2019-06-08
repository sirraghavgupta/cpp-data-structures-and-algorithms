/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : You are provided n numbers of array. You need to find the maximum 
		 length of bitonic subarray. A subarray A[i … j] is biotonic if there is 
		 a k with i <= k <= j such that 
		 A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] 
		 i.e subarray is first increasing and then decreasing or entirely increasing
		 or decreasing.
STATUS :
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int *arr;
arr = new int[n];

for(int i=0; i<n; i++)
	cin>>arr[i];

int length=1, flag=1;
for(int i=1; i<n; i++){
	if(arr[i]>=arr[i-1]){
		length++;
	}
	if(arr[i]<=arr[i-1]){
		length++;
	}
}

return 0;
}