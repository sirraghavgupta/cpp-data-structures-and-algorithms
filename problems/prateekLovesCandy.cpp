/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 july 2019
AIM    : to print the Nth prime number.
		     maximum prime number an be 1000000.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void primeSieve(bool *p, int number){

  // set 2 to be prime
  p[2]=1;

  // set all odd numbers to be prime
  for(int i=3; i<number; i+=2){
    p[i]=1;
  }

  // iterate till root(N) to check for prime numbers
  // skip even numbers
  for(int i=3; i*i<=number; i+=2){
      // cancel all multiples of i.
      // skip the even multiples of i by jumping for 2i.
      for(int j=i*i; j<=number; j+=2*i){
           p[j]=0;
      }
    }
}

int main(){

// generate the prime sieve first
bool arr[1000001];
primeSieve(arr, 1000001);

//copy all primes into another array
int *primeArr;
primeArr = new int[80400];
int j=0;
for(int i=2; i<1000001; i++){
  if(arr[i]){  
    primeArr[j]=i;
    j++;
  }
}


int t;
cin>>t;

while(t>0){
	int n;
	cin>>n;

  cout<<primeArr[n-1]<<endl;    // print the nth prime number

t--;
}
return 0;
}