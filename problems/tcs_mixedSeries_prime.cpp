/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 july 2019
AIM    : mixed series of prime numbers and all.
STATUS : !!!  !!!
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



return 0;
}