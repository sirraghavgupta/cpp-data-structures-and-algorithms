/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 2 june 2019
AIM    : to count the number of 1s in the binary representation of a number
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
using namespace std;

int main(){

int number, setCount, t; 	// number, count of 1s, test cases
cin>>t;

while(t>0){

	cin>>number;
	setCount=0; 	// initialise setCount to be 0

	// logic for getting binary bit 
	while(number>0){
		int rem=number%2;
		number/=2;
		if(rem)	setCount++;		// if binary bit is 1, increment count	
	}
	cout<<setCount<<endl;
	t--;
}

return 0;
}