/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 april 2019
AIM    : to draw a a pattern like this [ for n=5 ]
         only odd values allowed for n [number of rows]
         stars separated by tab
    *
  *   *
*   *   *
  *   *
    *
STATUS :
##############################################################################*/


#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
for(int row=0; row<n; row++){
   int i=(row>n/2)?n-row-1:row;

  int count=n/2 - i;
  while(count>0){
    cout<<" \t";
    count--;
  }
  count=2*i+1;
  while(count>0){
    cout<<"*\t";
    count--;
  }
  cout<<endl;
}

return 0;
}
