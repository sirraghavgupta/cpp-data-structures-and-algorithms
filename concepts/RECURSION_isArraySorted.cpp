/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to check if an array is sorted, by using recursion 
			-- learn recursion on arrays
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

/*	both the versions are correct
bool isSorted(int *arr, int n){
	if(n==1)
		return true;
	else if(arr[0]<=arr[1] && isSorted(arr+1, n-1))
		return true;
	return false;
}*/


bool isSorted(int *arr, int n){
	if(n==1)
		return true;
	else if(arr[0]<=arr[1])
		return isSorted(arr+1, n-1);//arr+1 is the key step for dividing the array
	return false;
}

int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++)
	cin>>arr[i];

isSorted(arr, n)?cout<<"sorted"<<endl:cout<<"not sorted"<<endl;

return 0;
}