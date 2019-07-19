/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 19 july 2019
AIM    : all the even numbers should come after the odd numbers
STATUS : !!! success !!! effortful
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


void evenAfterOdd(node *&head){

	// initialise the pointers to the 2 separate even and odd lists
	node *oddHead = new node(-1);
	node *oddTail = oddHead;
	node *evenHead = new node(-1);
	node *evenTail = evenHead;
	// traversal pointer for main LL
	node *temp = head;
	// traverse the LL
	while(temp!=NULL){
		if((temp->data)%2==1){		// if odd data
			oddTail->next = temp;	// add element at tail
			oddTail = temp;			// update tail
			temp = temp->next;		// move temp ahead
			oddTail->next = NULL;	// break the old link
		}
		else{						
			evenTail->next = temp;
			evenTail = temp;
			temp = temp->next;
			evenTail->next = NULL;
		}
	}

	evenTail->next = NULL;			// terminate even list
	oddTail->next = evenHead->next; // concatenate the lists
	delete evenHead;				// delete the extra first node taken
	head = oddHead->next;			// update head
	delete oddHead;					// delete the extra first node taken
	
}

int main(){

node *head = NULL;
int n;
cin>>n;
buildList(head, n);
cout<<head<<endl;

evenAfterOdd(head);

cout<<head<<endl;

return 0;
}