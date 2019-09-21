/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to find out the unique numbers from an arrays
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

// read array 1
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];


// processing logic 
unordered_map<int, bool> m;

// push first array into the map
for(int i=0; i<n; i++){
	if(m[arr[i]]==false)
		m[arr[i]] = true;
}

// print the map now
for(auto it:m)
	cout<<it.first<<" ";
cout<<endl;

return 0;
}