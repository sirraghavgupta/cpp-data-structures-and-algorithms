/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : find the unique number from an array where all numbers occur twice
		 except one.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

	int n;
	cin>>n;
	int arr[n];
	int result=0;

	// take xor of all thhe numbers, the repeating numbers will be cancelled.
	// only unique number will be remaining;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		result = result^arr[i];
	}
	cout<<result<<endl;

return 0;
}