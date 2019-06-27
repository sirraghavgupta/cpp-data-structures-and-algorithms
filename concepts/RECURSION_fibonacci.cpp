/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : to print the nth term of fibonacci series which starts from 0,1
						 -- understand recursion tree and call stack
						 -- understand multiple recursive calls
STATUS : !!! success !!! 
##############################################################################*/

#include <iostream>
using namespace std;

int fib(int n){
	if(n==0 || n==1)
		return n;
	int f1 = fib(n-1);
	int f2 = fib(n-2);
	return f1+f2;
}

int main(){

int n;
cin>>n;
cout<<fib(n)<<endl;

return 0;
}