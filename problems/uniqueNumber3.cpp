/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 june 2019
AIM    : in an array, all the numbers are present thrice, except 1 uniue elemets
		 find the elements... use BIMASKING
STATUS : !!! success !!!  --- very important question
##############################################################################*/

#include <iostream>
using namespace std;

void pushBits(int arr[], int n, int bitCount[], int size){
	// counts the respective bits of all the questions

	// we count the number of bits at position 0, position 1 etc...
	// see logic in notes
	for(int i=0; i<n; i++){		//for all numbers, count the bits

		int count=0, num=arr[i];
		while(num>0){
			bitCount[count]+=(num&1);	
			num = num>>1;
			count++;
		}
	}
}

int generateNum(int bitCount[], int size){
	// generate number from the bitCount array
	int num=0;
	for(int i=0; i<size; i++){
		num+=(bitCount[i]<<i);
	}
	return num;
}

int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

int bitCount[64]={0};
pushBits(arr, n, bitCount, 64);

for(int i=0; i<64; i++){	// because numbers are repeated thrice 
	bitCount[i]%=3;
}

/*	-- print and check the array
for(int i=0; i<n; i++)
	cout<<bitCount[i]<<" ";*/


cout<<generateNum(bitCount, 64)<<endl;
return 0;
}