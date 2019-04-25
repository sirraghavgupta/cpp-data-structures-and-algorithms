/*****************************************************************************
AUTHOR : raghav gupta
PROBLEM : to find the sum of two arrays, considering them as a number
          example -
          1 2 3 4
          8 9 2 5
      >>  1 0 1 5 9
STATUS  : !!! SUCCESS !!!
*****************************************************************************/

#include <iostream>
using namespace std;

int main(){
int size, num1=0, num2=0, sum, digit;

// ---------------------------get first array in form of number--------------
cin>>size;
for(int i=0; i<size; i++){
  cin>>digit;
  num1*=10;
  num1+=digit;
}
cout<<num1<<endl;

// --------------------------get second array in form of number-------------
cin>>size;
for(int i=0; i<size; i++){
  cin>>digit;
  num2*=10;
  num2+=digit;
}
cout<<num2<<endl;

sum = num1 + num2;      //evaluate sum of the 2 numbers
int sumcopy=sum, length=0;
cout<<sum<<endl;

// ------------------------- calculate length of the output array, result
while(sumcopy>0){
  length++;
  sumcopy/=10;
}

// ------------------------- generate the output array
int arr[length];
for(int i=length-1; i>=0; i--){
  arr[i]=sum%10;
  sum/=10;
}
// ------------------------- print the output array
for(int i=0; i<length; i++){
  cout<<arr[i]<<", ";
}
// cout<<"END"<<endl;

return 0;
}
