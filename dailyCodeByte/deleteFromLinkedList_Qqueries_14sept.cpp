/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : We are given a linked list. There are Q queries. Each query is 
		 represented by a index x which represents the position from which the 
		 element has to be deleted. After every query print the linked list. 
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

void deleteAtHead(node *&head){
	if(head == NULL)	
		return;
	node *temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(node *&head){
	if(head == NULL)
		return;
	node *prev = NULL;
	node *tail = head;

	while(tail->next != NULL){
		prev = tail;
		tail = tail->next;
	}
	delete tail;
	prev->next = NULL;
}

void deleteInMiddle(node *&head, int pos){
	if(head == NULL || pos==0)		// to insert in beginning
		deleteAtHead(head);

	else if(pos>length(head)){		// to insert at tail
		deleteAtTail(head);
	}

	else{							// to actually insert in middle
		node *temp = head;
		while(pos>1){
			temp = temp->next;
			pos--;
		}
		node *del = temp->next;
		temp->next = del->next;
		delete del;
	}
}

void buildList(node *&head, int n){
	int data;
	while(n--){
		cin>>data;
		insertAtTail(head, data);
	}
}

void print(node *head){
	// node *temp = head; --- no need to do this
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){

int n, q;
cin>>n>>q;
node *head = NULL;
buildList(head, n);

while(q--){
	int pos;
	cin>>pos;

	deleteInMiddle(head, pos);
	print(head);
}

return 0;
}