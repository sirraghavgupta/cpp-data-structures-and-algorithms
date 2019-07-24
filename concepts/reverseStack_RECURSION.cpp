/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 23 july 2019
AIM    : to reverse a stack using recursion
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

void insertAtBottom(stack<int> &s, int data){
	// base case
	if(s.empty()){
		s.push(data);
		return;
	}

	// rec case
	int item = s.top();
	s.pop();
	insertAtBottom(s, data);
	s.push(item);
}

void reverseREC(stack<int> &s){
	// base case
	if(s.empty())
		return;

	// rec case
	int data = s.top();
	s.pop();
	reverseREC(s);
	insertAtBottom(s, data);

}

int main(){

stack<int> s;	

while(1){
	int a;
	cin>>a;
	if(a==-1)
		break;
	s.push(a);
}
printstack(s);

cout<<endl<<"after reversal:"<<endl;
reverseREC(s);
printstack(s);

return 0;
}