/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : implement linear search using recursion
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
	if(arr[n-1]==key)
		return n-1; 
	if(n==-1)
		return -1;
	return linearSearch(arr, n-1, key);
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];
int key;
cin>>key;

cout<<linearSearch(arr, n, key)<<endl;
return 0;
}