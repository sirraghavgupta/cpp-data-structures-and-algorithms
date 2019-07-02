/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 july 2019
AIM    : given three numbers, calculate (a^b)mod c.
		 1<=a,b,c<=100000
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;

ll power(ll a, ll b, ll m){		
	ll ans=1;
	for(ll i=0; i<b; i++)
		ans = ((ans%m)*(a%m))%m;
	return ans;
}

/* 	// ----- not working because of int ----- 
int power(int a, int b, int m){		
	int ans=a;
	// cout<<"initial value of answer"<<ans<<endl;
	for(int i=1; i<b; i++){
		// cout<<"for i = "<<i<<endl;
		ans = ((ans%m)*(a%m))%m;
		// cout<<ans<<endl;
	}
	return ans;
}*/

int main(){

ll a, b, m;
cin>>a>>b>>m;

cout<<power(a, b, m)<<endl;
return 0;
}