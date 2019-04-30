/******************************************************************************
PROBLM : to check if a number is armstrong number or not.
AUTHOR : RAGHAV GUPTA
STATUS : !!! error !!
NOTE   : armstrong number is the number which is equal to the sum of all
         [ digit raised to the power of number of digits in the number ]
         example - 371, 153, 370, 1, 0
******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

/*
  in case the pow function of the cmath header is not working fine, then  u can
  use the custum power function written here

  
 ---------------- custum power function -------------
int pow(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int result = pow(a, b/2);
    result *= result;
    if(b&1) {
        result *= a;
    }
    return result;
}*/


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
        cout<<"digit = "<<digit[i]<<endl;
        cout<<"power evaluated = "<<(long)pow(digit[i], length)<<endl;
        result+=pow(digit[i], length);
        cout<<"result = "<<result<<endl;
    }
    if(numcopy==result)     return true;
    else    return false;
}

int main() {
    int number;
    cin>>number;
    isArmstrong(number)?cout<<"number is armstrong\n":cout<<"number is not armstrong\n";
    return 0;
}
