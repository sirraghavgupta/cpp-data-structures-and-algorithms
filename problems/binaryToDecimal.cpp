/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 august 2019
AIM    : to convert binary number to decimal
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int binToDec(int n){
	// if number doesnt has fractional part
	int face=1;
	int res=0;

	while(n>0){
		int dig = n%10;
		res += dig*face;
		face*=2;
		n/=10;
	}	
	return res;
}

float binToDec(string s){
	// if number has both fractional part and decimal part
	int face = 1;
	float res = 0;

	while(n>0){
		int dig = n%10;
		res += dig*face;
		face*=2;
		n/=10;
	}	

}

int main(){

int n;
cin>>n;

cout<<binToDec(n)<<endl;

return 0;
}