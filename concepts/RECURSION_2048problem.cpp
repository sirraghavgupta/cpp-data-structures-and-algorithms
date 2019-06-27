/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 27 june 2019
AIM    : print the spellings of digits in a number using recursion.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printNum(int num){
	if(num==0)
		return;
	int dig=num%10;
	printNum(num/10);
	cout<<arr[dig]<<" ";
}

int main(){

int n;
cin>>n;
printNum(n);
cout<<endl;

return 0;
}