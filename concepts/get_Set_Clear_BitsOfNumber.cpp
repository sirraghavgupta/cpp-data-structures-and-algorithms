/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to extract the ith bit from binary representation of a number
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int getIthBit(int n, int i){
	// 1<<i is the mast with Ith bit 1 and rest all 0
	// & number with mask
	return (n & (1<<i))?1:0;
}

void setIthBit(int &n, int i){
	// 1<<i is the mast with Ith bit 1 and rest all 0
	// OR number with mask
	int mask = 1<<i;
	n = n|mask;
}

void clearIthBit(int &n, int i){	// unset a bit
	// 1<<i is the mask with Ith bit 1 and rest all 0
	int mask = 1<<i;
	// complement the mask
	mask = ~mask;
	// & number with mask
	n = n&mask;
}

int main(){

int n,i;	// i is the bit number from right, starting from 0
cin>>n>>i;

cout<<getIthBit(n,i)<<endl;
setIthBit(n,i);
cout<<n<<endl;
clearIthBit(n,i);
cout<<n<<endl;

return 0;
}