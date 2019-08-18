/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 august 2019
AIM    : to build and search in a binary search tree
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

bool search_BST(node *root, int key){
	// base case
	if(root == NULL)
		return false;

	if(root->data == key)
		return true;

	// Rec case
	if(key<=root->data)
		return search_BST(root->left, key);
	else
		return search_BST(root->right, key);
}


int main(){

node *root = NULL;
build_BST(root);
printInOrder(root);
cout<<endl;
bfs(root);

cout<<"search in BST"<<endl;

int key;
cin>>key;
while(key!=-1){
	search_BST(root, key)?cout<<"true"<<endl:cout<<"false"<<endl;
	cin>>key;
}

return 0;
}


/*
// 	bhaiya's code --------------- archive
//  there is only a difference of designing the recursive function
node* insertInBST(node *root, int data){
	// base case
	if(root==NULL)
	return new node(val);

	// Rec case
	if(data<=root->data)
		root->left = insertInBST(root->left, data);
	else
		root->right = insertInBST(root->right, data);
	return root;
}

node* build(){
	// read a list of numbers till -1 and also these numbers will be inserted into bst
	int d;
	cin>>d;

	node*root = NULL;

	while(d!=-1){
		root = insertInBST(root, d);
		cin>>d;
	}
	return root;
}
*/