	/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 july 2019
AIM    : to implement a queue using linked list
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

class queue{
private:
	node *head;
	node *tail;

public:
	queue(){
		head = NULL;
		tail = NULL;
	}
	void enqueue(int d){
		node *n = new node(d);
		if(tail == NULL){	// head would be obviously null
			head = n;
			tail = n;
		}
		else{
			tail->next = n;
			tail = n;
		}
	}
	void dequeue(){
		if(head!=NULL){
			node *temp = head;
			head = head->next;
			delete temp;
		}
	}
	void print(){
		node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"end"<<endl;
	}
	bool empty(){
		return head==NULL;
	}
	int front(){
		if(head==NULL)
			return -99999999;
		else
			return head->data;
	}
};

int main(){

queue q;

int choice;
do{
	cout<<"----- MENU -----"<<endl;
	cout<<"1. enqueue"<<endl;
	cout<<"2. dequeue"<<endl;
	cout<<"3. get front"<<endl;
	cout<<"4. print"<<endl;
	cout<<"5. exit"<<endl;

	cin>>choice;
	switch (choice){
		case 1: int data;
				cin>>data;
				q.enqueue(data);
				break;
		case 2: q.dequeue();
				break;
		case 3:	cout<<q.front()<<endl;
				break;
		case 4: q.print();
				break;
		case 5: exit(0);

		default: cout<<"invalid input"<<endl;
				 break;
	}

}while(choice!=0);

return 0;
}