/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 12 july 2019
AIM    : insertion, deletion, searching, length, input, prining, operator overloading
STATUS : !!! great success !!!
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

bool searchRecursive(node *head, int key){
	//base case
	if(head==NULL)
		return false;
	if(head->data == key)
		return true;
	head = head->next;
	return searchRecursive(head, key);
}

bool searchIterative(node *head, int key){
	while(head!=NULL){
		if(head->data == key)
			return true;
		head = head->next;
	}
	return false;
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


int main(){

node *head1 = NULL;
node *head2 = NULL;
cin>>head1>>head2;
cout<<head1<<endl<<head2;

return 0;
node *head = NULL;
cout<<"build the list"<<endl;
buildList(head);
print(head);


cout<<"insert in middle"<<endl;
insertInMiddle(head, 10, 2);
print(head);

cout<<"delete from head and tail"<<endl;
deleteAtHead(head);
deleteAtTail(head);
print(head);

cout<<"delete from middle"<<endl;
deleteInMiddle(head, 2);
print(head);

cout<<"searching"<<endl;
int key;
cin>>key;
cout<<searchRecursive(head, key)<<endl;
cout<<searchIterative(head, key)<<endl;
return 0;
}