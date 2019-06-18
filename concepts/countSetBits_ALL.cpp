/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to count the number of set bits by faster approach
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int countSetBits_Fast(int n){
	/*
		- time complexity - O(number of set bits)
		- whenever we & a number n with (n-1), it removes the last se bit from it
		- so we go on &ing with predecessors.
		- --------- AWESOME APPROACH -----------
	*/
	int count=0;
	while(n){	// while n!=0
		n = n&(n-1);
		count++;
		// cout<<n<<endl;
	}
	return count;	
}

int countSetBits(int n){
	/*
		- time complexity - O(number of bits)
		- approach is to get the status of the rightmost bit and shift the number 
		  towards right by one bit
		- increment ans if bit is one.
	*/
	int ans=0;
	for( ;n>0; n=n>>1)		
		ans = ans + (n&1);
	return ans;
}

int main(){

int n;
cin>>n;	

// cout<<countSetBits(n)<<endl;
cout<<countSetBits_Fast(n)<<endl;
return 0;
}