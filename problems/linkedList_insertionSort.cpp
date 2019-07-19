/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 july 2019
AIM    : insertion sort on linked list
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
	// cout<<"END"<<endl;
}

// istream& operator>>(istream &is, node *&head){
// 	buildList(head);
// 	return is;
// }
ostream& operator<<(ostream &os, node *&head){
	print(head);
	return os;
}

void insertionSort(node *&head){

	// add dummy node to the head of link list
	insertAtHead(head, -1);

	node *sorted = head;	// points to the tail of sorted part
	node *unsorted = head->next;

	while(unsorted!=NULL){	

		node *number = unsorted;
		node *temp = head;
		while(temp!=unsorted && temp->next->data < number->data){
			// locate temp to the position before number's actual position
			temp = temp->next;
		}
		if(temp == sorted){  //number is already in place
			sorted = unsorted;
			unsorted = unsorted->next;
		}
		else{			
			node *n = temp->next;
			sorted->next = number->next;
			unsorted = number->next;
			temp->next = number;
			number->next = n;
		}
	}
	head = head->next;	// update head
}

int main(){

node *head = NULL;
int n;
cin>>n;
buildList(head, n);
cout<<head<<endl;

insertionSort(head);
cout<<head<<endl;

return 0;
}