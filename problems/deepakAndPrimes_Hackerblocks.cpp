/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : print the nth prime number in the prime sieve 
         1<=n<=5000000
STATUS : !!! success !!!
##############################################################################*/

#include<iostream>
using namespace std;

// -----------------------------------------------------------------------------
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
// -----------------------------------------------------------------------------


// we need to print the 5000000th prime number also, so we used google to find out that
// 5,761,455 primes lie before 100000000. so we took the size of the array.

int main(){
  int n;    
  cin>>n;

  // initialise the array to be zero
  int size=100000000;
  bool *primeArr;
  primeArr = new bool[size];   // because such a big size cant be allocated statically
  
  for(int i=0; i<size; i++)
      primeArr[i]=0;
  primeSieve(primeArr, size);

  // lookup and print the nth prime number
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

return 0;
}
