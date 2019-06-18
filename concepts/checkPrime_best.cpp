/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to check whether a number is prime or not
STATUS : !!! success !!!
TIME   : O(root n)
##############################################################################*/

#include <iostream>
using namespace std;

bool isPrime(int n){
 	if(n==1)	return false;
 	for(int i=2; i*i<=n; i++){		// check from 2 to root n
 									// bcoz divisors exist in pairs
 		if(n%i==0)
 			return false;
 	}
 	return true;
}

int main(){

int n;
cin>>n;
isPrime(n)?cout<<"yes"<<endl:cout<<"no"<<endl;

return 0;
}