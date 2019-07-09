/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 june 2019
AIM    : to find the total number of subarrays which are divisible by N
		 N is the size of array
STATUS :  ------------ I N C O M P L E T E -----------------
##############################################################################*/

#include <iostream>
#include <cstdlib>
#define ll long long int
using namespace std;

void printArray(int arr[], int n){		
  // print an array of size n
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

// =================================================================

int main(){

int t;		// number of test cases
cin>>t;

while(t>0){		// process all test cases
	int n;		// size of array
	cin>>n;

	ll arr[n];			
	ll cummSum[n];		// cummulative sum
	cin>>arr[0];		 
	cummSum[0]=arr[0]%n;  	
	for(int i=1; i<n; i++){
		cin>>arr[i];
		cummSum[i]=cummSum[i-1]+arr[i];
		if(cummSum[i]<0)
			cummSum[i]+=n;
		cummSum[i]%=n;
	}	

	// printArray(arr, n);
	// printArray(cummSum, n);
	// return 0;
	ll freq[n]={0};
	for(int i=0; i<n; i++){
		int index = cummSum[i];
		freq[index]++;
	}
	// printArray(freq, n);
	// return 0;
	ll count=freq[0]; 		// count of subArrays
	for(int i=0; i<n; i++){
		count+=(freq[i]*(freq[i]-1))/2;	
	}
	cout<<count<<endl;	
t--;
}

return 0;
}