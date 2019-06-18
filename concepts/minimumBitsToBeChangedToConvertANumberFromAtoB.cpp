/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to find the minimum number of bits to be changed to convert a number a
		 to b.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int countSetBits_Fast(int n){
	int count=0;
	while(n){	// while n!=0
		n = n&(n-1);
		count++;
		// cout<<n<<endl;
	}
	return count;	
}

int main(){

int a,b;
cin>>a>>b;
// basically take the xor of 2 numbers and count the number of set bits in that.
cout<<countSetBits_Fast(a^b)<<endl;
return 0;
}