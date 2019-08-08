/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : to convert decimal number to binary
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int res=0;
int face = 1;

while(n>0){
	int dig = n%2;
	res += dig*face;
	n/=2;
	face *= 10;
}

cout<<res<<endl;

return 0;
}