/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 28 september 2019
AIM    : Given an array, the task is to calculate the sum of lengths of 
		 contiguous subarrays having all elements distinct
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++)
	cin>>arr[i];

unordered_map<int, bool> mp;
int j=0; 
int sum=0;

for(int i=0; i<n; i++){
	// evaluate the length of all desired subarrays starting with index i.

	while(j<n && mp.count(arr[j])==0){
		// increment j untill a repeated element is found 
		// insert the elements into array

		mp[arr[j]] = true;
		j++;
	}
	mp.erase(arr[i]);
	int ans = (j-i)*(j-i+1)/2;
	sum+=ans;
}

cout<<sum<<endl;
return 0;
}