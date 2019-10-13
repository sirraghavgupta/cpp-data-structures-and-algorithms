/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : to find out the intersection of 2 arrays;
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std; 

vector<int> intersection(int arr1[], int n, int arr2[]){
	// processing logic 
	map<int, int> m;

	// push first array into the map 
	for(int i=0; i<n; i++){
		// if it exists, increment its count
		if(m.count(arr1[i]))
			m[arr1[i]]++;
		//else insert it 
		else
			m[arr1[i]] = 1;
	}

	vector<int> v;

	// iterate for second array
	for(int i=0; i<n; i++){
		// if it exists, then push into vector
		if(m[arr2[i]]){
			m[arr2[i]]--;
			v.push_back(arr2[i]);	
		}
	}

	sort(v.begin(), v.end());
	return v;
}

int main(){

int n;
cin>>n;

// read array 1
int arr1[n];
for(int i=0; i<n; i++)
	cin>>arr1[i];

//read array 2
int arr2[n];
for(int i=0; i<n; i++)
	cin>>arr2[i];

// call function and recieve the vector of intersection
vector<int> v = intersection(arr1, n, arr2);

// printing 
cout<<"[";
int i;
for(i=0; i<v.size()-1; i++){
	cout<<v.at(i)<<", ";
}
cout<<v.at(i)<<"]"<<endl;

return 0;
}
