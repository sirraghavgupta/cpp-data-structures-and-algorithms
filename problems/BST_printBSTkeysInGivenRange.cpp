/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 august 2019
AIM    : to build a BST and print all the keys in the given range.
STATUS : !!!  !!!
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

void build_BST(node *&root, int n){
	// keep on inputing n values
	int val;
	while(n--){
		cin>>val;
		insert_BST(root, val);
	}
}

void printPreOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printBSTkeysInRange(node *root, int a, int b){
	if(root==NULL)
		return;
	if(root->data < a)
		return printBSTkeysInRange(root->right, a, b);
	if(root->data > b)
		return printBSTkeysInRange(root->left, a, b);

	printBSTkeysInRange(root->left, a, b);
	cout<<root->data<<" ";
	printBSTkeysInRange(root->right, a, b);

	return;
}

int main(){

int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	node *root = NULL;
	build_BST(root, n);
	// bfs(root);
	cout<<"# Preorder : ";
	printPreOrder(root);
	cout<<endl;
	
	int a, b;
	cin>>a>>b;
	cout<<"# Nodes within range are : ";
	printBSTkeysInRange(root, a, b);
	cout<<endl;
}

return 0;
}