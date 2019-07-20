/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 july 2019
AIM    : reverse a linked list with k elements at a time
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

/*void buildList(node *&head){
	int data;
	cin>>data;

	while(data!=-1){
		insertAtTail(head, data);
		cin>>data;
	}
}*/


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


node* kReverse(node *head, int k){

	// base case
	if(head == NULL)
		return head;

	// rec case
	node *tail = head;
	node *p = NULL;		// previous node
	node *c = head; 	// current node in hand
	node *n;			// next node

	for(int i=0; i<k; i++){		
		// save the next node 
		n = c->next;
		// revrese the current link - make current node point to the previous node
		c->next = p;
		// update the prev and next node for next iteration 
		p = c;
		c = n;
		}

		// update the head
		head = p;
		tail->next = kReverse(c, k);
		// reverse remaining list and return its head. append with previous list.
		return head;
		
}


int main(){

node *head = NULL;
int n, k;
cin>>n>>k;

buildList(head, n);
// cout<<head<<endl;

head = kReverse(head, k);
cout<<head<<endl;

return 0;
}