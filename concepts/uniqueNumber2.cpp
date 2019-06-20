/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 june 2019
AIM    : in an array, all the numbers are present twice, only 2 numbers are 
		 unique. find the 2 numbers. use BITMASKING
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
int arr[n];

int xorOfAll=0;		// will hold xor value of all the numbers.
					// indirectly, its the xor of the 2 unique numbers

for(int i=0; i<n; i++){		// input numbers
	cin>>arr[i];
	xorOfAll = xorOfAll^arr[i];	// simultaneously evaluate xor also
}
int xorAll = xorOfAll;
int mask=1;		// evaluate mask for splitting the array into two parts
				// 2 parts contain one number each
while(!(xorOfAll&1)){	// detect the first set bit in the xorOfAll
	xorOfAll = xorOfAll>>1;
	mask = mask<<1;		// mask is prepared with only that bit = 1
}

int num1=0, num2=0;		// will contain the xor of 2 splitted arrays
for(int i=0; i<n; i++){	// splitting the array and directly evaluating their xors.
	if(arr[i]&mask)
		num1 = num1^arr[i];
	// else
	// 	num2 = num2^arr[i];
}
num2 = xorAll^num1;
// finally we get the numbers.

if(num1<num2)	
	cout<<num1<<" "<<num2<<endl;
else
	cout<<num2<<" "<<num1<<endl;

return 0;
}