/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : to find the hcf of n numbers
         > N <= 10 and all the numbers lie between 1 and 100.
STATUS : !!! success !!!
##############################################################################*/

#include<iostream>
using namespace std;

//  ------------------------------------------------------------
int gcd(int a, int b){
    if(b==0)
      return a;
    else
      gcd(b,a%b);
}

int lcm(int a, int b){
  return (a*b)/gcd(a,b);
}
//  ------------------------------------------------------------


int main(){

  int n;      // number of candidates
  cin>>n;
  int arr[n];

  for(int i=0; i<n; i++){   // read numbers into array
    cin>>arr[i];
  }

  int hcf=arr[0];   // initialise hcf to first number
  int i=1;
  while(i<n){       // evaluate hcf successfully
    hcf=gcd(hcf,arr[i]);
    i++;
  }
  cout<<hcf<<endl;
  
  return 0;
}
