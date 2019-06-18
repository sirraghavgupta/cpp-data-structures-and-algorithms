/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 june 2019
AIM    : to find out the integral Kth root of a number by binary search 

	   : You are given two integers n and k. Find the greatest integer x, such 
		 that, x^k <= n.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <cmath>
#define ll long long int
using namespace std;


ll KthRoot(ll n, ll k){			// similar to binary search

	ll start=0, end=n;	
	ll mid;
	ll ans=-1;

	while(start<=end){

		mid = (start+end)/2;
		// cout<<"mid = "<<mid<<endl;
		if(pow(mid,k)<n){
			ans=mid;
			start=mid+1;
		}
		else if(pow(mid,k)==n)
			return mid;
		else
			end=mid-1;
	}

	return ans;
}
// -------------------------------------------------


int main(){

int t;
cin>>t;

while(t>0){
	ll n;		// number 
	cin>>n;

	ll k;		// value of k
	cin>>k;

	cout<<KthRoot(n, k)<<endl;
t--;
}

return 0;
}