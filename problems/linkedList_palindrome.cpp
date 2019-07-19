/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 july 2019
AIM    : check if linked list is palindrome
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

bool isPalindrome(node *head){
	node *temp = head;
	node *reverse = NULL;
	// generate reverse linked list
	while(temp!=NULL){
		insertAtHead(reverse, temp->data);
		temp = temp->next;
	}
	// match the reverse list with original
	while(head!=NULL){
		if(head->data != reverse->data)
			return false;
		head = head->next;
		reverse = reverse->next;
	}
	return true;
}

int main(){

node *head = NULL;
int n;
cin>>n;
buildList(head, n);
cout<<head<<endl;

isPalindrome(head)?cout<<"True"<<endl:cout<<"False"<<endl;

return 0;
}