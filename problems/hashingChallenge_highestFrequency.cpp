/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : Given an array find the number which comes with maximum frequency. 
		 It must work in O(n) time complexity.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <map>
using namespace std;

int main(){

int n;
cin>>n;

map<int,int> m;

int val;
int max=-99999999;
while(n--){
	cin>>val;
	if(m.count(val))
		m[val]++;
	else
		m[val] = 1;

	if(m[val]>m[max])
		max = val;
}
cout<<max<<endl;

return 0;
}