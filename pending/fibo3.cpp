/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 May 2019
AIM    : 
STATUS :
##############################################################################*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

int t;
cin>>t;

vector<pair <int,int> > testCases;
for(int i=0; i<t; i++){
	int n;
	cin>>n;
	testCases.push_back(make_pair(i,n));
}

for(int i=0; i<t; i++){
	cout<<testCases[i].first<<" , "<<testCases[i].second<<endl;
}


return 0;
}