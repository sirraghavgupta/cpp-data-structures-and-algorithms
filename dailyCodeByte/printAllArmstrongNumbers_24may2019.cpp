/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 24 May 2019
AIM    : to print all armstrong numbers between n1 and n2 inclusive
		 		0 < N1 < 100 
		 		N1 < N2 < 10000
STATUS : !!! success !!!
##############################################################################*/
#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int number){
    int length=0, numcopy=number;
    int result = 0;
    int digit[10]={0};      // holds the digits of the number

    while(number>0){
        digit[length]=number%10;     // adding digits to the digits array
        length++;
        number/=10;
    }

    for(int i=0; i<length; i++){     // check for armstrong number
        // cout<<"digit = "<<digit[i]<<endl;
        // cout<<"power evaluated = "<<(long)pow(digit[i], length)<<endl;
        result+=pow(digit[i], length);
        // cout<<"result = "<<result<<endl;
    }
    if(numcopy==result)     return true;
    else    return false;
}

int main(){

int n1, n2;
cin>>n1>>n2; 		// input range of search

for(int i=n1; i<=n2; i++){
	if(isArmstrong(i)) 		// if number is armstrong, then print the number
		cout<<i<<endl;
}
return 0;
}