/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to multiply 2 numbers using recursion
		 should work for negative numbers also
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int multiply(int a, int b){
	if(b==0)
		return 0;

	// this is the actual way the computer does multiplication
	int ans;
	if(b>0)
		ans = a + multiply(a,b-1);
	else 
		ans = multiply(a,b+1) - a;
	return ans;
}

int main(){

int a,b;
cin>>a>>b;
cout<<multiply(a,b)<<endl;

return 0;
}