/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to implement the FAST power function effiently using recursion
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int power(int a, int b){	// O(b) time
	if(b==0)
		return 1;
	return a*power(a,b-1);
}

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
cout<<power(a,b)<<endl;
cout<<fastPower(a,b)<<endl;

return 0;
}