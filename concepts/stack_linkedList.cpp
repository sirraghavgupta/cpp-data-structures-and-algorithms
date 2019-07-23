/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement stack using linked list
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	// def ctor
	node(int n){
		data = n;
		next = NULL;
	}
};

/*
we use head as the top because if we would use tail, then after every pop operation,
we need to move back the tail by 1 which can only be achived indirectly by traversing
the whole linked list and is an EXPENSIVE OERATION
*/

class stack{
private: 
	node *head; 	// top basically
public: 

	// def ctor
	stack(){
		head=NULL;
	}

	void push(int d){

		node *n = new node(d);
		n->next = head;
		head = n;
	}

	void pop(){
		if(!isEmpty()){
			node *temp = head;
			head = head->next;
			delete temp;
		}
	}

	int top(){
		if(!isEmpty())
			return head->data;
		else
			return -99999999;
	}

	bool isEmpty(){
		return head==NULL;
	}

	void print(){
		node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp = temp->next;
		}
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