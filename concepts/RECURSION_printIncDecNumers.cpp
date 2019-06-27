/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : print the numbers from 1-n in deresing and increasing order;
			-- learn to do task while returning in the recursion call stack also
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void dec(int n){
	if(n==0)
		return;
	cout<<n;
	dec(n-1);
}

void inc(int n){
	if(n==0)
		return;
	inc(n-1);
	cout<<n;
}

int main(){

int n;
cin>>n;
dec(n);
inc(n);

return 0;
}