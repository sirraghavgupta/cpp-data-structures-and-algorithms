/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 31 May 2019
AIM    : to print the binary representation of an octal number 
STATUS : !!! needs improvement !!!
##############################################################################*/
#include <iostream>
using namespace std;


int getLength(int number){
	int length=0;
	while(number>0){
	number/=10;
	length++;
	}
return length;
}

/*void convertBinary(int digits[], int length, int binary[], int size){
	int count=0;
	int bincount=0;
	while(count<length){
		int dig=digits[count];
		while(dig>0){
			binary[bincount]=dig%2;
			dig/=2;
			bincount++;
		}
		count++;
	}
}*/

int splitNumber(int number, int digits[], int length){
	int count=0;
	while(number>0){
		digits[count]=number%10;
		number/=10;
		count++;
	}
}

/*void printArray(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}*/

int main(){

int number;
cin>>number;

int length = getLength(number);
// cout<<length<<endl;

int digits[length];

splitNumber(number, digits, length);
// printArray(digits,length);

// int size = length*3;
// bool binary[size];
// convertBinary(digits, length, binary, size);
// printArray(binary, size);

char binValues[8][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
int redValues[8] = {0, 1, 10, 11, 100, 101, 110, 111};

cout<<redValues[digits[length-1]];
for(int i=length-2; i>=0; i--){
	cout<<binValues[digits[i]];
}
return 0;
}