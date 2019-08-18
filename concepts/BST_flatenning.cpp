/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 august 2019
AIM    : to convert a bst into a sorted linked list
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
using namespace std;

class node{
public:
	node *left;
	int data;
	node *right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

class LinkedList{
	// a pair basically
public: 
	node *head;
	node *tail;
};

void bfs(node *root){
	// breadth first search
	// print with newline after every level
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		
		node *n = q.front();

		if(n==NULL){
			q.pop();
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}

		else{
			cout<<n->data<<" ";
			q.pop();
			if(n->left)
				q.push(n->left);
			if(n->right)
				q.push(n->right);
			}
	}
}

void insert_BST(node *&root, int val){
	// insert the val into a tree with root
	if(root==NULL){
		root = new node(val);
		return;
	}

	if(val<=root->data)
		insert_BST(root->left, val);
	else
		insert_BST(root->right, val);

	return;
}

void build_BST(node *&root){
	// keep on inputing values and -1 to stop
	int val;
	cin>>val;
	while(val!=-1){
		insert_BST(root, val);
		cin>>val;
	}
}

void printInOrder(node *root){
	if(root==NULL)
		return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}

node* flatten(node *root){		// my function

	// BASE CASE
	if(root==NULL)
		return NULL;

	if(root->left==NULL && root->right==NULL)
		return root;


	// REC CASE
	node *left = flatten(root->left);
	node *right = flatten(root->right);

	node *temp = left;	
	
	if(left==NULL){
		left = root;
		root->right = right;
		left = root;
	}

	else{
		// go to tail
	while(temp->right != NULL){
		temp = temp->right;
	}

	// attach the root
	temp->right = root;
	root->left = NULL;
	temp = temp->right;
	temp->right = right;
	}
	return left;
}


LinkedList flatten_BST(node *root){		// bhaiya function
	LinkedList l;
	// empty tree
	if(root==NULL){
		l.head = l.tail = NULL;
		return l;
	}

	// leaf node 
	if(root->left == NULL && root->right == NULL){
		l.head = l.tail = root;
		return l;
	}
	
	// if left subtree is null
	if(root->left==NULL && root->right!=NULL){
		LinkedList rightLL = flatten_BST(root->right);
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l; 
	}
	
	// if right subtree is null
	if(root->left!=NULL && root->right==NULL){
		LinkedList leftLL = flatten_BST(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	
	// if both are not null
	LinkedList leftLL = flatten_BST(root->left);
	LinkedList rightLL = flatten_BST(root->right);
	l.head = leftLL.head;
	leftLL.tail->right = root;
	root->right = rightLL.head;
	l.tail = rightLL.tail;
	return l;
}

void printList(node *head){
	// node *temp = head; --- no need to do this
	while(head!=NULL){
		cout<<head->data<<"->";
		head = head->right;
	}
	cout<<"END"<<endl;
}


int main(){

node *root = NULL;
build_BST(root);
printInOrder(root);
cout<<endl;
bfs(root);

cout<<"after flattening the tree"<<endl;

root = flatten(root);
printList(root);

// LinkedList l = flatten_BST(root);
// printList(l.head);

return 0;
}

