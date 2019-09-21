/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to implement hash table by STL
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

unordered_map<string, int> myMap;

// 3 ways to insert 
myMap["banana"] = 500;					// direct

// insert function asls for a pair 
myMap.insert(make_pair("mango", 100));	// u can make pair by make_pair() function 
pair<string, int> p("apple", 600);		// u can make pair by constructor 
myMap.insert(p);

// iterate over the nodes.
for(auto node:myMap){	// for each loop
	// auto keyword automatically determines the data type 
	// its basically pair<string, int> here.
	cout<<node.first<<", "<<node.second<<endl;
}

myMap["guava"] = 90;	
myMap["papaya"] = 70;
myMap["kiwi"] = 50;	

// how to iterate over the BUCKETS...

int n = myMap.bucket_count();

for(int i=0; i<n; i++){
	// for each bucket
	cout<<"bucket "<<i<<" : ";
	// it is a pointer to pair here - refer to cplusplus.com
	for(auto it = myMap.begin(i); it!=myMap.end(i); it++){
		cout<<it->first<<" - "<<it->second<<", ";
	}
	cout<<endl;
}

return 0;
}