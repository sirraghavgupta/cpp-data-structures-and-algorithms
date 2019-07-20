/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 july 2019
AIM    : There are two linked lists. Due to some programming error, the end node
		 of one of the linked list got linked into the second list, forming an 
		 inverted Y shaped list. Now it's your job to find the point(Node) at 
		 which the two linked lists are intersecting.
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
		cout<<head->data<<" ";
		head = head->next;
	}
}

// istream& operator>>(istream &is, node *&head){
// 	buildList(head);
// 	return is;
// }
ostream& operator<<(ostream &os, node *&head){
	print(head);
	return os;
}

node* reverseREC2(node *head){	// returns the address of current head of reversed link list
	// ------ prateek bhaiya version - does the work separately, and finaly updates the head in main
	// base case
	if(head->next == NULL || head==NULL)
		return head;

	node *smallHead = reverseREC2(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}


int length(node *head){		// to get the length of the linked list
	int len=0;
	while(head != NULL){
		head = head->next;
		len++;
	}
	// cout<<"length = "<<len<<endl;
	return len;
}

int intersectionPoint1(node *head1, node *head2){
  // ---------------- my approach --------------
	// reverse the lists first and match then
	head1 = reverseREC2(head1);
	head2 = reverseREC2(head2);

	// if first element matches then continue, else no intersection
	if(head1->data != head2->data)
		return -1;
	else{
		while(head1!=NULL && head1->next!=NULL && head2!=NULL && head2->next!=NULL && head1->next->data == head2->next->data){
			head1 = head1->next;
			head2 = head2->next;
		}
		return head1->data;	 
	}
}

int intersectionPoint2(node *head1, node *head2){
	// ------------- standard better approach

	// calculate the difference of their lengths
	int l1 = length(head1);
	int l2 = length(head2);	
	int diff = abs(l1-l2);

	node *temp = NULL;
	temp = (l1>l2)?head1:head2;	// points to longer list

	// jump ahead in the longer list so that the intersection is equidistant from 
	// pointers of both the lists
	while(diff--){
		temp = temp->next;
	}
	head1 = temp;
	// cout<<head1<<endl;

	// move node by node in both the lists untill
	while(head1!=NULL && head2!=NULL){
		// cout<<"------"<<endl;
		// cout<<head1<<endl;
		// cout<<head2<<endl;
		if(head1->data == head2->data){
			// cout<<"found"<<endl;
			return head1->data;
		}
		else{
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	return -1;
}

int main(){

node *head1 = NULL;
int n;
node *head2 = NULL;

cin>>n;
buildList(head1, n);

cin>>n;
buildList(head2, n);

// cout<<intersectionPoint1(head1, head2)<<endl;
cout<<intersectionPoint2(head1, head2)<<endl;

return 0;
}