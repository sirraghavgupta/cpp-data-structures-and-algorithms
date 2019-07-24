/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 23 july 2019
AIM    : to reverse a stack using 2 extra stacks.
STATUS : !!! success !!!
##############################################################################*/


#include <iostream>
#include <stack>
using namespace std;

void printstack(stack<int> s){
	while(!s.empty()){
	cout<<s.top()<<endl;
	s.pop();
	}
	cout<<"end"<<endl;
}

void transfer(stack<int> &s1, stack<int> &s2){
	// transfer s1 into s2.
	while(!s1.empty()){
		int data = s1.top();
		s2.push(data);
		s1.pop();
	}
}

void reverse(stack<int> &s){
	stack<int> s1, s2;
	transfer(s, s1);
	transfer(s1, s2);
	transfer(s2, s);
}

int main(){

stack<int> s;	

s.push(10);
s.push(20);
s.push(30);
s.push(40);
printstack(s);
cout<<endl<<"after reversal:"<<endl;
reverse(s);
printstack(s);

return 0;
}