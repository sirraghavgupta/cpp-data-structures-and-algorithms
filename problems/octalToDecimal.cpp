/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 26 july 2019
AIM    : to convert octal number to decimal
STATUS : !!!  !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;

int face=1;
int res=0;

while(n>0){
	int dig = n%10;
	res += dig*face;
	face*=8;
	n/=10;
}	

cout<<res<<endl;

return 0;
}