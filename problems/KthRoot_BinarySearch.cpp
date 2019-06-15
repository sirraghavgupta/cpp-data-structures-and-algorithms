/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 june 2019
AIM    : to find out the Kth root of a number by binary search 

	   : You are given two integers n and k. Find the greatest integer x, such 
		 that, x^k <= n.
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
#define ll long long int
using namespace std;

ll power(ll a, int b, int n) {
   ll result=1;
   for(int i=0; i<b; i++){
   	  result*=a;
   	  if(result>n)	
   	  	return -1;
   }
   return result;
}

ll KthRoot(ll n, int k){	// similar to binary search

	ll start=0, end=n;	
	ll mid;
	ll ans=-1;

	while(start<=end){

		mid = (start+end)/2;
		ll currVal = power(mid,k,n);
		if(currVal==n){	 // perfect square root found, then return it
			ans = mid;
			break;
		}

		else if(currVal<n){	// look for a better integral part if exists
			start = mid+1;
			ans = mid;
		}
		else
			end = mid-1;
	}

	return ans;
}
// -------------------------------------------------


int main(){

ll n;		// number 
cin>>n;

int k;		// value of k
cin>>k;

cout<<KthRoot(n, k)<<endl;

return 0;
}