/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 13 july 2019
AIM    : find he Kth node of the link list from the end
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

node* getKthNode(node* head, int k){
	if(head==NULL){
		cout<<"empty list"<<endl;
		return head;
	}

	node* slow = head;
	node* fast = head;
	// take k steps for fast first - create a gap of k between them
	while(k--){
		fast = fast->next;
		if(fast==NULL){	// if k>number of elements in list
			cout<<"invalid index"<<endl;
			return NULL;
		}
	}

	while(fast!=NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(){

node *head = NULL;
cin>>head;
cout<<head<<endl;

int k;
cin>>k;
node* target = getKthNode(head, k);
if(target != NULL)
	cout<<target->data<<endl;

return 0;
}