/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 july 2019
AIM    : circular linked list
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

void push(node *&head, int data){
	node* n = new node(data);
	n->next = head;
	if(head!=NULL){
		node *temp = head;
		while(temp->next != head)
			temp = temp->next;
		temp->next = n;
	}
	else{
		n->next = n;
	}
	head = n;
}


void print(node* head){
	node* temp = head;
	while(temp->next != head){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

node* getNode(node* head, int data){
	node *temp = head;
	while(temp->next != head){
		if(temp->data == data)
			return temp;
		temp = temp->next;
	}
	if(temp->data == data)
		return temp;
	return NULL;
}

void deleteNode(node *&head, int data){
	node* del = getNode(head, data);
	// if node not found
	if(del == NULL){
		cout<<"node doesn't exist"<<endl;
		return;
		}
	// if node is head itself - update the head first
	if(del == head)
		head = del->next;
	//now update the links
	node* temp = head;
	while(temp->next != del){
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;
}

void buildListCircular(node *&head){
	int n;
	cin>>n;
	int data;
	while(n--){
		cin>>data;
		push(head, data);
	}	
}

int main(){

node *head = NULL;
buildListCircular(head);
print(head);
deleteNode(head, 10);
deleteNode(head, 50);
print(head);

return 0;
}