/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : to build a binary tree in preorder form and print it.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

class node{
public:
	node* left;
	int data;
	node* right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

node* buildTree(){
	 int d;
	 cin>>d;

	 // base case
	 if(d==-1)
	 	return NULL;

	 // rec case
	 node *root = new node(d);
	 root->left = buildTree();
	 root->right = buildTree();
	 return root;
}

void printPreOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void printInOrder(node *root){
	if(root==NULL)
		return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}

void printPostOrder(node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

/*void printLevelOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printLevelOrder(root->left);
	printLevelOrder(root->right);
	node *left = root->left;
	node *right = root->right;
}*/

int computeHeight(node *root){
	// get the number of levels = get height
	if(root==NULL)
		return 0;
	int leftH = 1 + computeHeight(root->left);
	int rightH = 1+ computeHeight(root->right);
	return (leftH>rightH)?leftH:rightH;
}

int main(){

node *root =  buildTree();
printPreOrder(root);
cout<<endl;
printInOrder(root);
cout<<endl;
printPostOrder(root);
cout<<endl;
cout<<computeHeight(root)<<endl;

return 0;
}