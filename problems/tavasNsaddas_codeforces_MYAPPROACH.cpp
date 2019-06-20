/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 june 2019
AIM    : to give the index of the lucky number in the lucky number series
		 a lucky number is the one which is made up of only 4 and 7s.
		 ex - 4, 7, 44, 47, 74, 77 .................. 
STATUS : !!! success !!!
NOTE   : refer to PDF also.
##############################################################################*/

#include <iostream>
using namespace std;

int getLength(int number){
  // find the number of digits in a number
  int length=0;
  while(number>0){
  number/=10;
  length++;
  }
return length;
}

int main(){

int n;
cin>>n;

// calculate count of all numbers of length less than the digits in current number
int index = (1<<getLength(n))-1;


// get the digits of the number 1 by 1, and assign appropriate weight to it
// -- to count the index of the number within the numbers of same length
int count=0;
while(n>0){
	if(n%10 == 7){
		index += (1<<count);
	}
	n/=10;
	count++;
}
cout<<index<<endl;		// final index of the number

return 0;
}