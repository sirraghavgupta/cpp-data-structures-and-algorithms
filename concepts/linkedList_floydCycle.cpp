/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 14 july 2019
AIM    : create a cycle in a list
		 detect cycle
		 remove cycle
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

bool detectFloydCycle(node* head){
	// only to detect floyd cycle

	if(head==NULL){	// if empty list
		cout<<"empty list"<<endl;
		return false;
	}
	node* slow = head;
	node* fast = head;

	// iterate untill slow meets fast
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast==slow)
			return true;
	}
	// if null is found, no cycle
	return false;
}

void removeFloydCycle(node *head){
	// if list is empty, then return
	if(head==NULL){
		cout<<"empty list"<<endl;
		return;
	}
	// 2 runners
	node* slow = head;
	node* fast = head;

	// detect the cycle
	while(1){
		slow = slow->next;
		fast = fast->next->next;	// [STEP = 2]
		if(fast==slow){	// cycle found
			cout<<"cycle found ----- removing now.......... . . . "<<endl;
			break;
		}
		if(fast==NULL || fast->next == NULL){	// cycle doesn't exist
			cout<<"no cycle"<<endl;
			return;
		}
	}

	slow = head;		// move slow to the head
	// iterate untill slow meets fast. 
	int count=1;
	while(slow!=fast){
		slow = slow->next;
		fast = fast->next;		// [STEP = 1]
		count++;
	}
	cout<<"cycle detected at "<<count<<" node "<<endl; 
	// now both slow and fast are at the beginning of the cycle
	// move to the last node of cycle to break the cycle 
	node *prev = slow;
	while(prev->next != fast){
		prev = prev->next;
	}
	prev->next = NULL;
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

int main(){

node *head = NULL;
cin>>head;
cout<<head;
cout<<detectFloydCycle(head)<<endl;
removeFloydCycle(head);
int cycIndex;
cin>>cycIndex;
buildCyclicList(head, cycIndex);
// cout<<head;
cout<<detectFloydCycle(head)<<endl;
removeFloydCycle(head);
cout<<head;
return 0;
}