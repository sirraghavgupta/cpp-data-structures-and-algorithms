/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 august 2019
AIM    : to delete a node from a BST
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

			node *smallest = root->right;
			while(smallest->left!=NULL){
				smallest = smallest->left;
			}
			root->data = smallest->data;
			root->right = delete_BST(root->right, smallest->data);
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
printInOrder(root);
cout<<endl;
bfs(root);

cout<<"delete in BST"<<endl;

int key;
cin>>key;
root = delete_BST(root, key);
bfs(root);
printInOrder(root);
cout<<endl;

return 0;
}
