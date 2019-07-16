/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 july 2019
AIM    : to merge 2 sorted linked lists rcursively
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

node* mergeSortedListsREC(node *head1, node* head2){

	// base case
		// -- if any one of the lists become null, then the other list is the answer
		// -- both lists can never be null, else the user is crazy
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;

	// rec case
	node *head = NULL;	// points to the smaller element of the 2 lists
	if(head1->data <= head2->data){
		// save the address of the smaller element
		head = head1;
		// merge the remaining list and then finally add the smaller element to its head
		head->next = mergeSortedListsREC(head1->next, head2);
	}
	else{
		head = head2;
		head->next = mergeSortedListsREC(head1, head2->next);
	}
	return head;
}

int main(){

// input and print the lists
node *head1 = NULL;
node *head2 = NULL;

cin>>head1;
cout<<head1;

cin>>head2;
cout<<head2;

// merging
node *head = mergeSortedListsREC(head1, head2);
cout<<head;

return 0;
}