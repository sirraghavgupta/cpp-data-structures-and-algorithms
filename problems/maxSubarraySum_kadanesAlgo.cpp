/********************************************************************************
AUTHOR : raghav gupta
DATE   :  7 june 2019
PROBLEM : to find the maximum sum of the subarrays of an array
          KADANE'S ALGORITHM
STATUS  : !!! SUCCESS !!!
*********************************************************************************/

#include <iostream>
using namespace std;

int main(){

int size, arr[100];		// array and its size
int cs=0, ms=0;			// cummulative and maximum sum
cin>>size;

for(int i=0; i<size; i++){		// read the array
  cin>>arr[i];
}

for(int i=0; i<size; i++){
  cs+=arr[i];
  if(cs<0)   cs=0;
  ms=max(ms, cs);
}

cout<<ms<<endl;
return 0;
}
