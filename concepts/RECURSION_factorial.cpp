/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to evaluate the factorial by recursion - understand call stack
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int fact(int n){
	if(n==0)
		return 1;
	int ans = n*fact(n-1);
	return ans;
}

int main(){

int n;
cin>>n;
cout<<fact(n)<<endl;

return 0;
}