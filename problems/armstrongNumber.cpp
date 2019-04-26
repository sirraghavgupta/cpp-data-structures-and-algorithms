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

bool isArmstrong(int number){
    int length=0, result=0, numcopy=number;
    int digit[10]={0};      // holds the digits of the number
    while(number>0){
        digit[length]=number%10;     // adding digits to the digits array
        length++;
        number/=10;
    }

    for(int i=0; i<length; i++){
        cout<<"digit = "<<digit[i]<<endl;
        cout<<"power evaluated = "<<pow(digit[i], length)<<endl;
        result+=pow(digit[i], length);
        cout<<"result = "<<result<<endl;
    }
    cout<<"the result is: "<<result<<endl;
    if(numcopy==result)     return true;
    else    return false;
}

int main() {
    int number;
    cin>>number;
    isArmstrong(number)?cout<<"number is armstrong\n":cout<<"number is not armstrong\n";
    return 0;
}
