/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 september 2019
AIM    : Shekhar is a bomb defusal specialist. He once encountered a bomb that 
		 can be defused only by a secret code. He is given a number N and a 
		 number K. And he is also given permutation of first N natural numbers. 
		 The defusal code is the largest permutation possible by doing atmost K 
		 swaps among a pair of the given permutation. Help him to find the final 
		 permutation.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

int n;		// number of elements
cin>>n;

int k;		// n0. of swaps allowed 
cin>>k;

int arr[n];	// array to store the elements 
	
unordered_map<int, int> mp;		// key = number, value = index in array

for(int i=0; i<n; i++){
	// read the array and place in map also
	cin>>arr[i];
	mp[arr[i]] = i;
}

// processing logic 
for(int i=n; i>0 && k>0; i--){
	
	int currIndex = mp[i];
	int bestIndex = n - i;

	if(currIndex!=bestIndex){
		swap(arr[currIndex], arr[bestIndex]);
		mp[i] = bestIndex;
		mp[arr[currIndex]] = currIndex;
		k--;
	}
}

// print the final array/ permutation
for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}