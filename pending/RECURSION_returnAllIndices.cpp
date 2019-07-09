/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 july 2019
AIM    : Take as input N, the size of array. Take N more inputs and store that 
		 in an array. Take as input M, a number. Write a recursive function which 
		 returns an array containing indices of all items in the array which have 
		 value equal to M. Print all the values in the returned array.
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
------------- this way is useless, not working, leave it. TA is unable to understand
int* returnAllIndices(int a[], int s, int e, int m){
	// base case
	if(s>e)			// if no element is remaining
		return NULL;

	// Rec case
	if(a[e]!=m)		// if required element not found
		return returnAllIndices(a, s, e-1, m);
			
	// element matched
	int *res;
	res = returnAllIndices(a, s, e-1, m);	//search in remaining array first
	
	int size=sizeof(res)/sizeof(int);	// calculated size of returned array
	res = (int *)realloc(res, (size+1)*sizeof(int));	// insert one more index in that
	res[size]=e;
	  
	return res;

}*/


void returnAllIndices(int a[], int s, int e, int m, int ans[], int j){
	// base case
	if(s>e)			// if no element is remaining
		return;

	// Rec case
	if(a[s]!=m)		// if required element not found
		returnAllIndices(a, s+1, e, m, ans, j);
			
	// element matched
	ans[j++] = s;	// add the index into the array
	returnAllIndices(a, s+1, e, m, ans, j);	//search in remaining array
}


int main(){

// get the array
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

// get the key
int m;
cin>>m;

// get the answer array returned
int ans[n];
returnAllIndices(arr, 0, n-1, m, ans, 0);

// print the answer
for(int i=0; i<n; i++){
	if(ans[i]>0)
		cout<<ans[i]<<" ";
}
cout<<endl;

return 0;
}