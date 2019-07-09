/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 4 july 2019
AIM    : chech if any subset of array sums up to 0
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
#include <string.h>
using namespace std;

void checkSubsets(int arr[], int s, int e){
	// base case
	if(s>e){ 
		return false;
	}



}

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

cout<<checkSubsets(arr, 0, n-1);

return 0;
}