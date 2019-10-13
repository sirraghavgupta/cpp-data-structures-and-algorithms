/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 6 october 2019
AIM    : find the factorial of big number like upto 500. 
STATUS : !!! success !!!
NOTE   : see geeks for geeks if u wish
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

void bigFactorial(int n){
	short int fact[1200];		// stores the digits of the factorial 

	fact[0] = 1;		// default answer 

	int resSize = 1;	// length of the current answer.  

	for(int num=2; num<=n; num++){
		// for every number from 2 to n - we do this.
		int i = 0;
		int carry = 0;
		while(i<resSize){
			// multiply every digitby the num and adjust
			int temp = fact[i]*num + carry;
			int base = temp%10;
			fact[i] = base;
			carry = temp/10;
	
			i++;
		}

		while(carry){
			// we need to do this because in this problem, carry can be greater than 
			// 9 also because its not the usual carry. its only the number with last 
			// digit removed.
			// the number temp here can be big because the 'num' is not necessarily 
			// a single digit number and so does temp. 
			fact[resSize] = carry%10;
			carry/=10;
			resSize++;
		}
	}
	cout<<resSize<<endl;

	for(int i=resSize-1; i>=0; i--){
		cout<<fact[i];
	}
	cout<<endl;
}

int main(){

int a;
cin>>a;

bigFactorial(a);

return 0;
}