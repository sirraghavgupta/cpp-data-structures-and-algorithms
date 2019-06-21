/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 june 2019
AIM    : to find the total number of subarrays which are divisible by N
		 N is the size of array
STATUS : !!! time limit error !!!
NOTE   : ---- BRUTEFORCE APPROACH ----
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int t;
cin>>t;

while(t>0){
	int n;
	cin>>n;

	int arr[n];			// array of numbers
	int cummSum[n];		// cummulative sum arrays
	cin>>arr[0];		// initialise first element of cummSum to be first element 
	cummSum[0]=arr[0];  // of array
	for(int i=1; i<n; i++){
		cin>>arr[i];
		cummSum[i]=cummSum[i-1]+arr[i];
	}	

	int count=0; 		// count of subArrays
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if((cummSum[j] - cummSum[i-1])%n==0)	// get the sum of subarray
				count++;
		}
	}
	cout<<count<<endl;	
t--;
}

return 0;
}