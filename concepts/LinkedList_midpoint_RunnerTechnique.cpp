/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 july 2019
AIM    : find he midpoint of the link list 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

class node{
	public:
		int data; 
		node *next;
	// default constructor 
		node(int d){
			data = d;
			next = NULL;
		}
};


void insertAtTail(node *&head, int data){
	if(head == NULL){		// if list is empty
		head = new node(data);
		return;
	}
	node *tail = head;
	while(tail->next != NULL)
		tail = tail->next;
	tail->next = new node(data);
}

void buildList(node *&head){
	int data;
	cin>>data;

	while(data!=-1){
		insertAtTail(head, data);
		cin>>data;
	}
}

void print(node *head){
	// node *temp = head; --- no need to do this
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"END"<<endl;
}

istream& operator>>(istream &is, node *&head){
	buildList(head);
	return is;
}
ostream& operator<<(ostream &os, node *&head){
	print(head);
	return os;
}

node* getMidPoint(node* head){

	if(head==NULL || head->next == NULL)
		return head;

	node* slow = head;
	node *fast = head->next;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;	// takes jump of 2
		slow = slow->next;			// takes jump of 1
	}
	return slow;
}

int main(){

node *head = NULL;
cin>>head;
cout<<head<<endl;

node* mid = getMidPoint(head);
cout<<mid->data<<endl;

return 0;
}