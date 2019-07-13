/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 july 2019
AIM    : to merge 2 sorted linked lists 
STATUS : !!!  !!!
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

node* mergeSortedLists(node *head1, node* head2){

	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	node *head = NULL;
	node *tail = NULL;

	if(head1->data <= head2->data){
		head = head1;
		head1 = head1->next;
	}
	else{
		head = head2;
		head2 = head2->next;
	}
	tail = head;

	while(head1!=NULL && head2!=NULL){
		if(head1->data <= head2->data){
			tail->next = head1;
			head1 = head1->next;
		}
		else{
			tail->next = head2;
			head2 = head2->next;	
		}
		tail = tail->next;
	}

	if(head1==NULL){
		tail->next = head2;
	}
	else{
		tail->next = head1;
	}
	return head;
}

int main(){

node *head1 = NULL;
node *head2 = NULL;

cin>>head1;
cout<<head1;

cin>>head2;
cout<<head2;

node *head = mergeSortedLists(head1, head2);
cout<<head;

return 0;
}