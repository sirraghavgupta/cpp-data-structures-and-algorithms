/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 july 2019
AIM    : Append the last K elements of a linked list to the front.K can be greater 
		 than N.
		 basically rotation of linked list
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
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"END"<<endl;
}

// istream& operator>>(istream &is, node *&head){
// 	buildList(head);
// 	return is;
// }
ostream& operator<<(ostream &os, node *&head){
	print(head);
	return os;
}


void append_KnodesFromLast(node *&head, int k){

	if(head==NULL || k==0)
		return;

	//else start finding the node
	node* slow = head;
	node* fast = head;

	// take k steps for fast first - create a gap of k between them
	while(k--){
		fast = fast->next;
		// if k>n
		if(fast==NULL){	
			return;
		}
	}

	// move untill fast becomes NULL.
	while(fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	} // --- now fast is at tail and slow is at k-1 th node

	// append operation
	fast->next = head;
	head = slow->next;
	slow->next = NULL;
}

int main(){

node *head = NULL;
int n;
cin>>n;
buildList(head, n);
cout<<head;

int k;
cin>>k;
k%=n;	// if k>n
append_KnodesFromLast(head, k);

cout<<head;

return 0;
}