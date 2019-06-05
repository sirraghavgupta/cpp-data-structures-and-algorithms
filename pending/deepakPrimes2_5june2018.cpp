/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : to print all the prime numbers between 2 numbers m and n
		 where  [ 1<=m<=n<=1000000000, n-m<=100000 ]
		 and test cases [ 1<=T<=10 ]
STATUS : !!! needs to be optimised  !!!
##############################################################################*/

#include <iostream>
using namespace std;

bool isPrime(int n){
	if(n==0 ||n==1)	
		return false;
	else{
		for(int i=2; i*i<=n; i++){
		if(n%i==0)
			return false;
	}	
	}
	return true;
}

int main(){

int m,n;

int t;	// number of test cases
cin>>t;

while(t>0){		// for all test cases
cin>>m>>n;

int size=n-m+1;
int prime[size];	// array required for all numbers

for(int i=0; i<size; i++){		// set all numbers to be prime
	prime[i]=1;
}

for(int i=0; i<size; i++){	
	if((i+m)%2==0 && (i+m)!=2)	// if number is even but not 2
		prime[i]=0;
	else if(!isPrime(i+m))		// if number is odd and not prime
		prime[i]=0;
					// only primes are left now
}

for(int i=0; i<size; i++){	// print the prime numbers
	if(prime[i])	
		cout<<i+m<<endl;
}
cout<<endl;

t--;
}

return 0;
}