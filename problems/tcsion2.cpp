/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : 
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

int fibo(int n){
	if(n==1 || n==2)
		return 1;
	else 
		return fibo(n-1)+fibo(n-2);
}

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

int n;
cin>>n;


// start working

if(n&1){
	n = n/2 + 1;
	cout<<fibo(n)<<endl;
}

else{
	n = n/2;

// initialise the array to be zero
  int size=100000000;
  bool *primeArr;
  primeArr = new bool[size];   // because such a big size cant be allocated statically
  
  for(int i=0; i<size; i++)
      primeArr[i]=0;
  primeSieve(primeArr, size);

  int count=0;
  for(int i=2; i<size; i++){
    if(primeArr[i]){
      count++;
      if(count==n){
        cout<<i<<endl;
        return 0;
      }
    }
  }
}
	
return 0;
}