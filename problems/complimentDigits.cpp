/******************************************************************************
AUTHOR : RAGHAV GUPTA
PROB STAT : convert a given number with all its digits minus from 9.
            like 7 -> 2, 8 -> 1, 9 - >0....
STATUS : !!!!    COMPLETE    !!!!
******************************************************************************/

#include<iostream>
using namespace std;

int complementDigits(int);

int main(){
  int number, result;
  cout<<"enter a number please: ";
  cin>>number;
  result = complementDigits(number);
  cout<<"the complement number is: "<<result<<endl;
  return 0;
}

int complementDigits(int num){
  int result=0, count=1;
  while(num>0){
    result=result + (9 - num%10)*count; //
    /*unusual construction method. unlike the method we follow in reversal of
      number. here i am multplying every digit by its place value.*/
    num/=10;       // prepare for next iteration
    count*=10;     //this is basicllay the place value of the digit
  }
  return result;
}
