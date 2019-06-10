/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 june 2019
AIM    : check whether an array is mirror inverse or not
		 mirror inverse means the inverse of the array is same as the array
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n], inverse[n];
for(int i=0; i<n; i++)		// read the array
	cin>>arr[i];

for(int i=0; i<n; i++)		// prepare the inverse array
	inverse[arr[i]] = i;

// print the inverse
/*for(int i=0; i<n; i++)		
	cout<<inverse[i]<<" ";
cout<<endl;*/

// check for mirror inverse
for(int i=0; i<n; i++)
	if(arr[i]!=inverse[i]){
		cout<<"false"<<endl;
		return 0;
	}
cout<<"true"<<endl;

return 0;
}
