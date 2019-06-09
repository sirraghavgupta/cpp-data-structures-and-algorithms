/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 june 2019
AIM    : bubble sort
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include "general.cpp"
using namespace std;

int main(){

int n;		// size of array
cin>>n;

int arr[n];
readArray(arr, n);
// for(int i=0; i<n; i++)		// read array
// 	cin>>arr[i];

bubble_sort(arr, n);

for(int i=0; i<n; i++)		// print the element
	cout<<arr[i]<<" ";
cout<<endl;

return 0;
}