/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to check whether a number is prime or not
STATUS : !!! success !!!
TIME   : O(n/2) -- O(n)
##############################################################################*/

#include <iostream>
using namespace std;

bool isPrime(int n){
 	if(n==1)	return false;
 	for(int i=2; i<=n/2; i++){		// check from 2 to n/2
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