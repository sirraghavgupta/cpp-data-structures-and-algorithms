/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 june 2019
AIM    : bubble sort of integers
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include "general.h" 
using namespace std;


int main(){

int n;
cin>>n;
int arr[n];

readArray(arr, n);
// for(int i=0; i<n; i++){
// 	cin>>arr[i];
// }

bubble_sort(arr,n);

// for(int i=0; i<n; i++){
// 	cout<<arr[i]<<" ";
// }
printArray(arr, n);

return 0;
}