/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 25 july 2019
AIM    : implement stack using 2 queues
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

void transfer(queue<int> &q1, queue<int> &q2){
	int n = q1.size();
	while(n>1){
		int data = q1.front();
		q1.pop();
		q2.push(data);
		n--;
	}
}

class stack{
	private:
		queue<int> q1;
		queue<int> q2;
	public:
	
		void push(int data){
			if(q1.empty())
				q2.push(data);
			else
				q1.push(data);
		}

		void pop(){
			if(this->isEmpty()){
				cout<<"stack empty"<<endl;
				return;
			}
			if(q1.empty()){
				transfer(q2, q1);	// transfer n-1 elements from q2 to q1
				q2.pop();
			}
			else{
				transfer(q1, q2);	// transfer n-1 elements from q1 to q2
				q1.pop();
			}
		}

		int top(){
			if(this->isEmpty())
				return -99999999;
			else if(q1.empty()){
				transfer(q2, q1);
				int data = q2.front();
				q2.pop();
				q1.push(data);
				return data;
			}
			else{
				transfer(q1, q2);
				int data = q1.front();
				q1.pop();
				q2.push(data);
				return data;
			}
		}

		bool isEmpty(){
			return q1.empty() && q2.empty();
		}

		void print(){

			// will destroy the stack also
			while(!this->isEmpty()){
				cout<<this->top()<<" ";
				this->pop();
			}
			cout<<endl;
		}
};

int main(){

stack stk;

int choice;
do{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. push"<<endl;
	cout<<"2. pop"<<endl;
	cout<<"3. get top"<<endl;
	cout<<"4. print"<<endl;
	cout<<"5. exit"<<endl;

	cin>>choice;
	switch (choice){
		case 1: int data;
				cin>>data;
				stk.push(data);
				break;
		case 2: stk.pop();
				break;
		case 3:	cout<<stk.top()<<endl;
				break;
		case 4: stk.print();
				break;
		case 5: exit(0);
		default: cout<<"invalid input"<<endl;
				break;
	}

}while(choice!=0);

return 0;
}