/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 july 2019
AIM    : detect cycle
		 remove cycle
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

node* search(node *head, int key){
	while(head!=NULL){
		if(head->data == key)
			return head;
		head = head->next;
	}
	return NULL;
}

node* getTail(node *head){
	if(head == NULL)
		return head;
	while(head->next != NULL){
		head = head->next;
	}
	return head;
}

void buildCyclicList2(node *&head){
	int data;
	cin>>data;
	node* temp = NULL;
	while(data!=-1){
		temp = search(head, data);
		if(temp!=NULL)	// element already exists
			break;
		insertAtTail(head, data);
		cin>>data;
	}
	// now make the cycle
	if(data!=-1){
		node* tail = getTail(head);
		tail->next = temp;
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

istream& operator>>(istream &is, node *&head){
	buildCyclicList2(head);
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
		// cout<<"empty list"<<endl;
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
			// cout<<"cycle found ----- removing now.......... . . . "<<endl;
			break;
		}
		if(fast==NULL || fast->next == NULL){	// cycle doesn't exist
			// cout<<"no cycle"<<endl;
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
	// cout<<"cycle detected at "<<count<<" node "<<endl; 
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

node* head = NULL;
buildCyclicList2(head);
// cout<<head<<endl;

removeFloydCycle(head);
cout<<head<<endl;

return 0;
}