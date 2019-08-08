/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 august 2019
AIM    : to calclate the diameter of the tree
STATUS : !!!  !!!
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

int countNodes(node *root){
	if(root==NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node *root){
	if(root==NULL)
		return 0;
	return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int main(){

node *root =  buildTree();
cout<<countNodes(root)<<endl;
cout<<sumNodes(root)<<endl;

return 0;
}