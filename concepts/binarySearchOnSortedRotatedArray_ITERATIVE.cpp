/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 11 june 2019
AIM    : to apply binary search on sorted rotated array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int binSearchRotated(int arr[], int n, int key){
	int start=0, end=n-1;

	while(start<=end){
		int mid=(start+end)/2;

		if(arr[mid]==key)		// directly found
			return mid;

		else if(arr[mid]>=arr[start]){ // mid lies in left part - left branch is big
			if(key<=arr[mid] && key>=arr[start])
				end=mid-1;
			else
				start=mid+1;
		}
		else{		// mid lies in right part - right branch is big
			if(key>=arr[mid] && key<=arr[end])
				start=mid+1;
			else
				end=mid-1;
		}
	}	
	return -1;
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

int key;
cin>>key;

int index = binSearchRotated(arr, n, key);
(index>=0)?cout<<"element found at "<<index<<endl:cout<<"element not found"<<endl;

return 0;
}