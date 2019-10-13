/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : Given an array arr of n length. You will be given Q queries for the array. 
		 Each query contains a number N. You have to determine whether a number 
		 exist in the array or not.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

int t;
cin>>t;

while(t--){	// process for every test case 
	int l;
	cin>>l;

	unordered_map<int,bool> m;
	int val;
	for(int i=0; i<l; i++){	// read the array
		cin>>val;
		m[val] = true;
	}

	int q;	// queries number
	cin>>q;
	while(q--){		//process queries 
		cin>>val;
		if(m[val])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}

return 0;
}