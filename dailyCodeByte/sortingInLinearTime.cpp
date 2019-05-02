/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 may 2019
AIM    : sort an array consisting of only 0s, 1s and 2s in linear time.
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int n, number;
cin>>n;
int zeros=0, ones=0, twos=0;      // holding the number of 0s, 1s, 2s

// input the numbers one by one and count the number of 0s, 1s, 2s
for(int i=0; i<n; i++){
  cin>>number;
  if(number==0)  zeros++;
  else if(number==1)  ones++;
  else  twos++;
}

// print all the 0s
while(zeros>0){
  cout<<0<<endl;
  zeros--;
}

// print all the 1s
while(ones>0){
  cout<<1<<endl;
  ones--;
}

// print all the 2s
while(twos>0){
  cout<<2<<endl;
  twos--;
}

return 0;
}
