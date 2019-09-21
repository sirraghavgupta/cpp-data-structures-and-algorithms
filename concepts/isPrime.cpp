
#include<iostream>
using namespace std;

bool isPrime(int n){
  if(n==1)
    return false;

  if(n==2)
    return true;

  if(n%2==0)
    return false;

  for(int i=3; i<n; i+=2){
    if(n%i == 0)
      return false;
  }
  
  return true;
}

// basic verison of prime number program. for class its ok for now.

int main(){

  //print all prime numbers within 100
  for(int i=1; i<=100; i++){
    if(isPrime(i))
      cout<<i<<" ";
  }
cout<<endl;
  return 0;
}
