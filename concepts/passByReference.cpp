/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 july 2019
AIM    : to study pass by reference in c++
STATUS : !!! learnt !!!
##############################################################################*/

#include <iostream>
using namespace std;

void inc(int &a, int &b){
	 a++;
	 b++;
}

/*
note - here, we are passing values by reference. means we are sending addresses.
so, we must use * to access the values. 
but here in c++, it looks as if the way of representation is different but the concept
underlying might be same.
we directly pass the variable name a - not its address. and instead of recieving it as 
int *a, we recieve it as int &a. i dont know how it works but,
ultimately, it giving ease that u can use 'a' directly without prepending * before it.
its good about c++ according to me.
*/

int main(){

int a=5, b=10;
cout<<a<<" "<<b<<endl;
inc(a, b);
cout<<a<<" "<<b<<endl;

return 0;
}