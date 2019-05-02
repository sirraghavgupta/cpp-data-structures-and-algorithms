/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 may 2019
AIM    : u can see the picture with the same name
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){

int n;      // size of the array - number of coins
cin>>n;
int arr[n];

for(int i=0; i<n; i++){     //read the values of the coins
  cin>>arr[i];
}

int sum=0;        // sum acquired by the player having first turn
int start=0, end=n-1;

while(start<=end){
  if(arr[start]>arr[end]){
    sum+=arr[start];
    // cout<<sum<<endl;
    start++;
  }
  else{
    sum+=arr[end];
    // cout<<sum<<endl;
    end--;
  }

  //other person turn
  if(arr[start]>arr[end]){
    // sum+=arr[start];     // dont add the coin picked by the other player
    start++;
  }
  else{
    // sum+=arr[end];
    end--;
  }
}

cout<<sum<<endl;

return 0;
}
