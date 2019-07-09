/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 may 2019
AIM    : u can see the picture with the same name
STATUS : !!!  !!!
##############################################################################*/
#include <iostream>
#include <cmath>
using namespace std;

// int findMaxScore(int arr[], int s, int e, int player){

//   if(s>e)
//     return 0;
//   if(player){
//       if(arr[s]>=arr[e])
//         return arr[s] + findMaxScore(arr, s+1, e, !player);
//       // if(arr[e]<arr[s])
//       return arr[e] + findMaxScore(arr, s, e-1, !player);
//   }
//   else{
//       if(arr[s]>=arr[e])
//         return findMaxScore(arr, s+1, e, !player);
//       // if(arr[e]<arr[s])
//       return findMaxScore(arr, s, e-1, !player);
//   }
// }

int findMaxScore(int arr[], int s, int e){

  if(s>e)
    return 0;
  int value;
  if(arr[s]>=arr[e]){
    value = arr[s];
    s++;
  }
  else{
    value = arr[e];
    e--;
  }
  if(arr[s]>=arr[e]){
    s++;
  }
  else{
    e--;
  }
  return value+findMaxScore(arr, s, e);
}


int main(){

int n;      // size of the array - number of coins
cin>>n;
int arr[n];

for(int i=0; i<n; i++){     //read the values of the coins
  cin>>arr[i];
}

cout<<findMaxScore(arr, 0, n-1)<<endl;

return 0;
}
