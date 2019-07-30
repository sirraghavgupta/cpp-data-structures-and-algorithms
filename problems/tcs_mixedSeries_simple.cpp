/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : calulate Nth term of the series 1 1 3 4 9 16 27 64
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int fastPower(int a, int b){	// O(log b) time --- very much optimised
	if(b==0)
		return 1;
	int tempAns=fastPower(a,b/2);
	tempAns*=tempAns;

	if(b&1)
		return a*tempAns;
	return tempAns;
}

int main(){

int n;
cin>>n;

if(n&1)
	cout<<fastPower(3, n/2)<<endl;
else
	cout<<fastPower(2, n-2)<<endl;

return 0;
}