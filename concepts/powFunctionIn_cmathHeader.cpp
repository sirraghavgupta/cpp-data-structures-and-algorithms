/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 30 april 2019
AIM    : to study the problem with pow function
STATUS :
##############################################################################*/
#include <iostream>
#include <cmath>
using namespace std;

/*  The pow() function takes ‘double’ as the arguments and returns a ‘double’
value. This functions does not always work for integers. One such example is
pow(5, 2). When assigned to an integer, it outputs 24 on some compilers and
works fine for some other compilers. But pow(5, 2) without any assignment to an
integer outputs 25.

This is because 52 (i.e. 25) might be stored as 24.9999999 or 25.0000000001
because the return type is double. When assigned to int, 25.0000000001 becomes
25 but 24.9999999 will give output 24.
To overcome this and output the accurate answer in integer format, we can add
0.5 to the result and typecast it to int e.g (int)(pow(5, 2)+0.5) will give the
correct answer(25, in above example), irrespective of the compiler.
*/

int main(){

int a;
a=pow(5,2);

cout<<pow(5,2)<<endl;     // in this compler gcc 4.8.1. its working fine.
                          // but in my previous gcc 8.2.0 it was not working properly.
                          // so i changed the compiler to older version.
cout<<a;

return 0;
}
