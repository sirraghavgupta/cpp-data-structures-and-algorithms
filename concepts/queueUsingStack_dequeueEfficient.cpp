/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : implement a queue data structure using stack and make it dequeue 
	 	 efficient
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <stack>
using namespace std;

class queue{
private:
	stack<int> s;
	stack<int> temp;
	// int front;
	// int rear;
	int cs;
	int ms;
public: 
	queue(int n){
		ms = n;
		cs = 0;
	}

	void push(int data){
		if(this->full())
			cout<<"queue is full"<<endl;
		else{
			while(!s.empty()){
				temp.push(s.top());
				s.pop();
			}
			s.push(data);
			cs++;
			while(!temp.empty()){
				s.push(temp.top());
				temp.pop();
			}
		}
	}

	void pop(){
		if(cs>0)
			s.pop();
	}

	bool empty(){
		return cs==0;
	}

	bool full(){
		return cs==ms;
	}

	int front(){
		if(!this->empty())
			return s.top();
		else{
			cout<<"queue empty"<<endl;
			return -99999999;
		}
	}

};

int main(){

	int n;
	cin>>n;

	queue q(n);
	for(int i=0; i<n; i++)
		q.push(i);

	for(int i=0; i<n; i++){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

return 0;
}