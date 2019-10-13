/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 october 2019
AIM    : euler's totient function 
STATUS : !!! success !!!
NOTE   : its the count of all the numbers which are mutually prime with n 
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)
      return a;
    else
      return gcd(b,a%b);
}

int eulerTotient(int n){
	// check from 1 to n which have GCD = 1.
	// GCD = 1 always with 1 
	int result = 1;
	for(int i=2; i<n; i++){
		if(gcd(i,n)==1)
			result++;
	}
	return result;
}

int main(){

int t;
cin>>t;

while(t--){

	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		// print the value for all numbers from 1 to n.
		cout<<eulerTotient(i)<<" ";
	}
	cout<<endl;
}


return 0;
}