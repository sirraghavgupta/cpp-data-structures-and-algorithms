/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : to detect and remove cycle in linked list
STATUS : !!! success !!!
NOTE   : time O(n)
	     space O(n)
	     WHILE floyd algo is better [ O(n) in time and O(1) in space ]
##############################################################################*/

#include <iostream>
#include <unordered_map>
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


void buildCyclicList(node* head, int k){
	// connect last node to the Kth node from beginning
	int count=1;
	node* beg = NULL;
	while(head->next != NULL){
		if(count==k)
			beg = head;
		head = head->next;
		count++;	
	}
	head->next = beg;
}

bool detectCycle(node *head){

	unordered_map<node*, bool> myMap;

	while(head!=NULL){
		if(myMap[head]==true)
			return true;

		myMap[head] = true;
		head = head->next;
	}
	return false;
}

void removeCycle(node *&head){

	unordered_map<node*, bool> myMap;
	node *temp = head;
	node *prev = NULL;

	while(temp!=NULL){
		if(myMap[temp]==true)
			break;

		myMap[temp] = true;
		prev = temp;
		temp = temp->next;
	}

	if(temp==NULL)
		return;
	else
		prev->next = NULL;
}

int main(){

node *head = NULL;
cin>>head;

// cout<<head;
buildCyclicList(head, 3);
// cout<<head;

detectCycle(head)?cout<<"cycle found"<<endl:cout<<"cycle not found"<<endl;
removeCycle(head);
detectCycle(head)?cout<<"cycle found"<<endl:cout<<"cycle not found"<<endl;
cout<<head;

return 0;
}