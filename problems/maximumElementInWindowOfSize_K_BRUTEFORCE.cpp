/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 august 2019
AIM    : to find the maximum elemnent in all subarrays of size k
STATUS : !!! success !!!
TIME   : O(nk)  -- TLE for big input
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

int k;
cin>>k;

for(int i=0; i<n-k+1; i++){
	int max=-99999999;
	for(int j=i; j<i+k; j++){
		if(arr[j]>max)
			max=arr[j];
	}
	cout<<max<<" ";
}
cout<<endl;

return 0;
}