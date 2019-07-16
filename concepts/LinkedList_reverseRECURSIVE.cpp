/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 july 2019
AIM    : reverse a linked list recurively
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

void reverseREC(node *&head){
	//  --------- my made function - doenst return anything and makes changes directly to the main
	if(head == NULL || head->next == NULL)	// no need to reverse the link list - only one element
		return;

	// Rec case
	node *n = head;		// save the address of current head
	head = head->next;
	reverseREC(head);	// ask to reverse the remaining list
	// now head points to the first node of the reversed link list
	// insert the previous skipped head to the tail of the reversed list
	node *tail = head;
	while(tail->next != NULL){	// go to tail of reversed list
		tail = tail->next;
	}	
	tail->next = n;
	n->next = NULL;
}

node* reverseREC2(node *head){	// returns the address of current head of reversed link list
	// ------ prateek bhaiya version - does the work separately, and finaly updates the head in main
	// base case
	if(head->next == NULL || head==NULL)
		return head;

	node *smallHead = reverseREC2(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}

int main(){

node *head = NULL;
cin>>head;
cout<<head<<endl;

// reverseREC(head);
head = reverseREC2(head);
cout<<head<<endl;

return 0;
}