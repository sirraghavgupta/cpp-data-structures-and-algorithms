/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 august 2019
AIM    : see shot
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <stack>
using namespace std;

int prime[100];			// holds q prime numbers

bool isPrime(int n){

 	if(n==1)	return false;
 	for(int i=2; i*i<=n; i++){		// check from 2 to root n
 									// bcoz divisors exist in pairs
 		if(n%i==0)
 			return false;
 	}
 	return true;
}

void getQprimeNumbers(int q){
	// generate an arry of first q prime numbers
	int count=0, i=2;
	while(count<q){
		if(isPrime(i)){
			prime[count]=i;
			count++;
		}
		i++;
	}
	return;
}

void printStack(stack<int> s){
	while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
		}
		// cout<<endl;
}

void solve(stack<int> s, int i, int q){

	if(i>q){	// at last print the Aq stack
		printStack(s);
		return;
	}

	stack<int> a, b;	// represent the Ai and Bi stacks

	while(!s.empty()){
		// processing the Ith iteration
		if(s.top() % prime[i-1] == 0)
			b.push(s.top());

		else
			a.push(s.top());
		
		s.pop();
	}

	printStack(b); 	// print the Bi stack
	solve(a, i+1, q);
}

int main(){

int n, q;
cin>>n>>q;

// build initial stack
stack<int> s0;
int val;
for(int i=0; i<n; i++){
	cin>>val;
	s0.push(val);
}

getQprimeNumbers(q);
solve(s0, 1, q);
cout<<endl;	

return 0;
}