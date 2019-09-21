/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to find out the intersection of 2 arrays;
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
unordered_map<int, int> m;

// push first array into the map
for(int i=0; i<n1; i++){
	m[arr1[i]] = 1;
}

// iterate for second array
for(int i=0; i<n2; i++){
	if(m[arr2[i]]==1)
		m[arr2[i]]++;	
}

// print the union now
for(auto it:m)
	if(it.second == 2)
		cout<<it.first<<" ";
cout<<endl;

return 0;
}