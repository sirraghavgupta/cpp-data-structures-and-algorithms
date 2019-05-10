/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 May 2019
AIM    : to find the king having maximum number of states with him 
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int t;
cin>>t; 		// number of test cases

for(int i=0;i<t; i++){ 			// for each test case
	int n;						// number of kings in that test case
	cin>>n;
	int arr[n];					// states owned by each king in that test case

	for(int j=0; j<n; j++){
		cin>>arr[j];
	}
	int max=-1, index=-1;
	for(int j=0; j<n; j++){		// find the king with max number of states 
		if(arr[j]>max)	{
		    max=arr[j];
		    index=j;
		    
		}
	}

	cout<<index+1<<" "<<max<<endl;	// give the index of kok and states owned by him
}

return 0;
}
