/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to swap 2 numbers using XOR operation
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

void XORswap(int &a, int &b){
	int temp;
	temp=a^b;
	a=a^temp;	
	b=b^temp;		
}

int main(){

int a,b,temp;
cin>>a>>b;

XORswap(a,b);
cout<<a<<" "<<b<<endl;

return 0;
}