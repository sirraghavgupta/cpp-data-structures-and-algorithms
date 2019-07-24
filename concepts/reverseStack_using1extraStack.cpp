/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 23 july 2019
AIM    : to reverse a stack using 1 extra stack.
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

void transfer(stack<int> &s1, stack<int> &s2, int k){
	// transfer k elemnets from s1 into s2.
	while(k--){
		int data = s1.top();
		s2.push(data);
		s1.pop();
	}
}


void reverse1(stack<int> &s){
	stack<int> x;
	int n = s.size();

	for(int i=0; i<n-1; i++){
		// step 1 - pop and store topmost element
		int temp = s.top();
		s.pop();

		// step 2 - transfer all unsettled elements to another
		transfer(s, x, n-i-1);

		// step 3 - push the stored element back and then transfer back elements also
		s.push(temp);
		transfer(x, s, n-i-1);
	}
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
reverse1(s);
printstack(s);

return 0;
}