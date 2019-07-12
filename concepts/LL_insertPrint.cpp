/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 july 2019
AIM    : to create a link list and print that
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
/* 	--------- OBJECT ORIENTED APPROACH ----
class LinkedList{
public:
	node *head;
	node *tail;

// default constructor
	LinkedList(){
		head = NULL;
		tail = NULL;
	}

// member functions
	void insertAtHead(){
		// -----------
	}
	void deleteFromHead(){
		// -----------
	}
}*/

// ------- FUNCTIONAL APPROACH ------

void insertAtHead(node *&head, int data){	//pass head by reference
	node *n = new node(data);
	n->next = head;
	head = n;
}

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

int length(node *head){		// to get the length of the linked list
	int len=0;
	while(head != NULL){
		head = head->next;
		len++;
	}
	// cout<<"length = "<<len<<endl;
	return len;
}

void insertInMiddle(node *&head, int data, int pos){
	if(head == NULL || pos==0)		// to insert in beginning
		insertAtHead(head, data);

	else if(pos>length(head)){		// to insert at tail
		insertAtTail(head, data);
	}

	else{							// to actually insert in middle
		node *temp = head;
		while(pos>1){
			temp = temp->next;
			pos--;
		}
		node *n = new node(data);
		n->next = temp->next;
		temp->next = n;
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


int main(){

node *head = NULL;
insertAtHead(head, 3);
insertAtHead(head, 4);
insertAtHead(head, 5);
insertAtHead(head, 6);

insertAtTail(head, 12);
insertInMiddle(head, 10, 2);
print(head);
// print(head);	    // to check that the changes to head in print() are not reflected back
return 0;
}