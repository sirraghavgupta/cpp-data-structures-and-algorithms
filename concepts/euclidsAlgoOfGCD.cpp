// *******************************************************************************
// PROBLM : to calculate the hcf and lcm of 2 numbers by euclid's algorithm
// AUTHOR : RAGHAV GUPTA
// DATE   : 20 june 2019
// STATUS : SUCCESS!!
// NOTE   : nothing new, just the maths wala method of finding gcd taught to
//          children, only name is new.
// *******************************************************************************
#include<iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)
      return a;
    else
      gcd(b,a%b);
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}

int main(){
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b)<<endl;
  cout<<lcm(a,b)<<endl;
  return 0;
}
