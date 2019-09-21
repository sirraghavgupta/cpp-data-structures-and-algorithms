/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to find out the union of 2 arrays;
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

// read array 1
int n1;
cin>>n1;
int arr1[n1];
for(int i=0; i<n1; i++)
	cin>>arr1[i];

// read array 2
int n2;
cin>>n2;
int arr2[n2];
for(int i=0; i<n2; i++)
	cin>>arr2[i];

// processing logic 
unordered_map<int, bool> m;

// push first array into the map
for(int i=0; i<n1; i++){
	m[arr1[i]] = true;
}
// push second array also
for(int i=0; i<n2; i++){
	m[arr2[i]] = true;	
}

// print the union now
for(auto it:m)
	cout<<it.first<<" ";
cout<<endl;

return 0;
}