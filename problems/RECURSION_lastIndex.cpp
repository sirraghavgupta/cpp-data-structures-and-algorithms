/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 july 2019
AIM    : Write a recursive function which returns the last index at which M is 
		 found in the array and -1 if M is not found anywhere. Print the value 
		 returned.
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

/*int getLastIndex(int arr[], int n, int m){
  // ---- if i start from the end
	// base case
	if(n==0)
		return -1;

	// Rec case
	if(arr[n-1] == m)
		return n-1;
	return getLastIndex(arr, n-1, m);
}*/

int getLastIndex(int arr[], int s, int e, int m, int lindex){
  // ---- if i start from the beginning - my method
	// base case
	if(s>e)
		return lindex;

	// Rec case
	if(arr[s]==m)
		lindex=s;
	return getLastIndex(arr, s+1, e, m, lindex);
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

int m;
cin>>m;

// cout<<getLastIndex(arr, n, m)<<endl;
cout<<getLastIndex(arr, 0, n-1, m, -1)<<endl;
return 0;
}