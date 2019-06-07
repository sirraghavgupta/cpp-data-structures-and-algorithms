/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : june 2019
AIM    : Take as input N, the size of array. Take N more inputs and store that in an array. 
		 Take as input M, the size of second array and take M more inputs and store that in 
		 second array. Write a function that returns the sum of two arrays. Print the value 
		 returned.
		 example - 
		    1 0 2 9
		  3 4 5 6 7
		= 3 5 5 9 6
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

// -------------------------- initial setup -------------------------
short int size1;
cin>>size1;
int num1[size1];
for(int i=0; i<size1; i++){
	cin>>num1[i];
}

short int size2;
cin>>size2;
int num2[size2];
for(int i=0; i<size2; i++){
	cin>>num2[i];
}

int carry=0, p=0;	// p points to the target number;
int result;		// store the result of every addition operation
int num1p=size1-1, num2p=size2-1;	// pointers for the 2 number arrays
int targetSize = (size1>size2)?(size1+1):(size2+1);
int target[targetSize];


// --------------------- processing part ----------------------------
while(num1p>=0 && num2p>=0){
	result = num1[num1p] + num2[num2p] + carry;
	if(result>9){
		target[p] = result%10;
		carry = result/=10;
	}
	else{
		target[p] = result;
		carry = 0;
	}
	num2p--;
	num1p--;
	p++;
}

// if number 1 has ended but number 2 is remaining
if(num1p<0 && num2p>=0)
{
	while(num2p>=0){
		result = num2[num2p] + carry;
		if(result>9){
			target[p] = result%10;
			carry = result/=10;
		}
		else{
			target[p] = result;
			carry = 0;
		}
		num2p--;
		p++;
		target[p] = carry;
		p++;
	}
}

// if number 2 has ended but number 1 is remaining
else if(num2p<0 && num1p>=0){
	while(num1p>=0){
		result = num1[num1p] + carry;
		if(result>9){
			target[p] = result%10;
			carry = result/=10;
		}
		else{
			target[p] = result;
			carry = 0;
		}
		num1p--;
		p++;
		target[p]=carry;
		p++;
	}
}

// if both have ended but carry is there 
else if(carry!=0){
	target[p]=carry;
	p++;
}


// if the number is, of size greater than the number of digits in the bigger number, 
// so we check for the last digit in the array.
if(target[targetSize-1]<10 && target[targetSize-1]>0)	cout<<target[targetSize-1]<<", ";

// print normal 
for(int i=targetSize-2; i>=0; i--)
		cout<<target[i]<<", ";

cout<<"END"<<endl;

return 0;
}