	/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : linear search on array
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key){
	
	for(int j=0; j<n; j++){
		if(arr[j]==key)
			return j;
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
cout<<linearSearch(arr, n, key)<<endl;

return 0;
}