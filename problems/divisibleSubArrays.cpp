/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 july 2019
AIM    : to find the total number of subarrays which are divisible by N
		 N is the size of array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

ll a[1000005], freq[1000005];	// to hold the values and the frequences of remainders

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		ll sum=0;	// to hold the cummulative sum
		memset(freq, 0, sizeof freq);	// reset the freq array everytime

		freq[0]=1;	// because 0 sum null subarray will always be there
		
		for(int i=0; i<n; i++){
			cin>>a[i];
			sum+=a[i];	
			sum%=n;		// evaluate sum
			sum+=n;		// make it positive if its negative
			sum%=n;
			freq[sum]++;
		}

		ll ans=0;
		for(int i=0; i<n; i++){	// count the subarrays
			ll num = freq[i];
			ans+=(num*(num-1))/2;
		}
		cout<<ans<<endl;
	}
	return 0;
}