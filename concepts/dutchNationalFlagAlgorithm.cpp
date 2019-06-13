/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 june 2019
AIM    : to sort an array containing only 0,1,2s in linear time
		 expected time complexity is constant
		 dont build the frequency array - counting sort X X X X
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

int low=0, mid=low, high=n-1;	// pointers to 3 windows of 0s, 1s and 2s

while(mid<=high){	// terminating condition
	if(arr[mid]==1)		// increment mid pointer	
		mid++;
	else if(arr[mid]==0){	// swap elements and increment both pointers
		swap(arr[mid], arr[low]);
		mid++;
		low++;
	}
	else{		// swap elements and decrement high pointer
		swap(arr[mid], arr[high]);
		high--;
	}
}
for(int i=0; i<n; i++)		// print the array
	cout<<arr[i]<<" ";
cout<<endl;
return 0;
}