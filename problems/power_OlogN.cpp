/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 5 october 2019
AIM    : to calculate a power b, in logB time.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
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

int a,b;
cin>>a>>b;

cout<<fastPower(a,b)<<endl;

return 0;
}