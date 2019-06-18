/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 june 2019
AIM    : to find out the integral Kth root of a number by binary search 

	   : You are given two integers n and k. Find the greatest integer x, such 
		 that, x^k <= n.
STATUS : !!! C O M P I L E R ----- P R O B L E M !!!
##############################################################################*/

#include <iostream>
#define ll long long int
using namespace std;

bool checkPower(ll a, ll b, ll n) {
   ll result=1;
   for(ll i=0; i<b; i++){
   	  result*=a;
   	  if(result<0)
   	  	return false;
   	  else if(result>n)
   	  	return false;
   }
   cout<<"result = "<<result<<endl;
   return true;
}


ll KthRoot(ll n, ll k){	// similar to binary search

	ll start=0, end=n;	
	ll mid;
	ll ans=-1;

	while(start<=end){

		mid = (start+end)/2;
		cout<<"mid = "<<mid<<endl;
		if(checkPower(mid,k,n)){
			ans=mid;
			start=mid+1;
		}
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