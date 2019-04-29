/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 29 april 2019
AIM    : You are given a sorted but rotated array. You need to fine the index of
         the pivot element of the array where pivot is that element in the array
         which is greater than its next element and divides the array into two
         monotonically increasing halves.

         example - 4 5 1 2 3 (basically, it looks like te array 1 2 3 4 5 was
                              rotated towards right by )
         the answer is 1 [ index of 5 ] because 5>2.

STATUS : !!! success !!!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

  int n;        // size of the array
  cin>>n;
  int arr[n];

  // input the matrix
  for(int i=0; i<n; i++){
    cin>>arr[i];
    if(arr[i]<arr[i-1]){  //if the curr element is less than the previous element
      cout<<i-1<<endl;    // print index of the bigger element
    }
  }



return 0;
}
