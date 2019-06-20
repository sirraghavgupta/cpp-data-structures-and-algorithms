/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 june 2019
AIM    : incredible hulk on hackerblocks - see image
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

int main(){

int number, t; 	// number, count of 1s, test cases
cin>>t;

while(t>0){

	cin>>number;
	cout<<countSetBits_Fast(number)<<endl;
	t--;
}
return 0;
}