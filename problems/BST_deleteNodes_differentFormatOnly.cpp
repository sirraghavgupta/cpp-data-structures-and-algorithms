/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 31 august 2019
AIM    : You are given an array A1 of integers. You have to form first Binary 
		 Search tree and then you are provided another array A2. You have to 
		 delete each node from the BST which is present in the array A2. Now you 
		 have to print preorder traversal of the tree.
STATUS : !!! success !!!
NOTE   : in another similar program, we replaced root with the smallest element
		 of the right subtree in case of 2 children.
		 here, we are replacing it with the largest element of the left subtree.
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
	int n;
	cin>>n;

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

node* search_BST(node *root, int key){
	// base case
	if(root == NULL)
		return NULL;

	if(root->data == key)
		return root;

	// Rec case
	if(key<=root->data)
		return search_BST(root->left, key);
	else
		return search_BST(root->right, key);
}

node* delete_BST(node *root, int val){
	
	if(root==NULL){
		return NULL;
	}

	if(val<root->data){	// delete from left subTree
		root->left = delete_BST(root->left, val);
	}

	else if(val>root->data){					// delete from right subTree
		root->right = delete_BST(root->right, val);
	}

	else{

		// 2 children case
		if(root->left!=NULL && root->right!=NULL){

			node *largest = root->left;
			while(largest->right!=NULL){
				largest = largest->right;
			}
			root->data = largest->data;
			root->left = delete_BST(root->left, largest->data);
		}

		// 1 children case
		else if(root->right!=NULL){		// right child is there
			node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->left!=NULL){		// left child is there
			node *temp = root->left;
			delete root;
			return temp;
		}

		// 0 children case
		else if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL ;
		}
	}

	return root;
}

int main(){

node *root = NULL;
build_BST(root);
cout<<"tree built"<<endl;
printPreOrder(root);
cout<<endl;
bfs(root);

// cout<<"delete in BST"<<endl;

int n;
cin>>n;
int del[n];
for(int i=0; i<n; i++)
	cin>>del[i];

for(int i=0; i<n; i++)
	root = delete_BST(root, del[i]);

cout<<"after deleting"<<endl;
bfs(root);
printPreOrder(root);
cout<<endl;

return 0;
}
