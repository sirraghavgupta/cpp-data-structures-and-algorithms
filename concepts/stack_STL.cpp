/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement stack using STL
STATUS : !!! success !!!
##############################################################################*/

/* 
4 basic functions are there in this library.
	push, pop, top, empty ----- simple
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){

stack<int> s;	// templated already 

s.push(10);
s.push(20);
s.push(30);
s.push(40);

while(!s.empty()){
	cout<<s.top()<<endl;
	s.pop();
}

return 0;
}