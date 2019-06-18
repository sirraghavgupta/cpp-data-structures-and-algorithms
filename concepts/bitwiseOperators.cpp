/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 june 2019
AIM    : to study the bitwise operators
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

int main(){

int a,b;
cin>>a>>b;

int result = a&b;
cout<<"a and b is: "<<result<<endl;
result = a|b;
cout<<"a or b is: "<<result<<endl;
result = a^b;
cout<<"a xor b is: "<<result<<endl;

cout<<"input shift number: "<<endl;
int shift;
cin>>shift;

a=a<<shift;
b=b>>shift;
cout<<"left shifted a = "<<a<<endl; 	// multiply the number by 2
cout<<"right shifted b = "<<b<<endl;    // divide the number by 2

return 0;
}