/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 june 2019
AIM    : to count the prime numbers between a and b inclusive
         a,b<=1000000
STATUS : !!! success !!!
##############################################################################*/

#include<iostream>
using namespace std;

// ------------------------------------------------------------------------------
void primeSieve(bool *p){   // function copied from my primeSieve program

  // set 2 to be prime
  p[2]=1;

  // set all odd numbers to be prime
  for(int i=3; i<1000000; i+=2){
    p[i]=1;
  }

  // iterate till root(N) to check for prime numbers
  // skip even numbers
  for(int i=3; i*i<=1000000; i+=2){
      // cancel all multiples of i.
      // skip the even multiples of i by jumping for 2i.
      for(int j=i*i; j<=1000000; j+=2*i){
           p[j]=0;
      }
    }
}
// --------------------------------------------------------------------------------

int main(){

  int t;
  cin>>t;

  // initialise the array to be zero
  bool primeArr[1000000] = {0};    // compiler wont allow such a big array declaration for int
  primeSieve(primeArr);


while(t>0){

int m,n;
cin>>m>>n;    // get range of search for prime

int count=0;
// count the prime numbers
  for(int i=m; i<=n; i++){
    if(primeArr[i])
      count++;
  }
cout<<count<<endl;
t--;
}

return 0;
}
