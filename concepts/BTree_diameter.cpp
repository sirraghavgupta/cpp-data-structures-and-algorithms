/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : to calclate the diameter of the tree 
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

class Pair{	
	// we made this class because we wanted to return 2 values from the fast function
	// we could have used the inbuilt pair class but this helps to give better names
public:
	int height;
	int diameter;
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

int getHeight(node *root){
	// get the number of levels = get height
	if(root==NULL)
		return 0;
	int leftH = 1 + getHeight(root->left);
	int rightH = 1+ getHeight(root->right);
	return (leftH>rightH)?leftH:rightH;
}

int getDiameter(node *root){
	// ------- O(n^2) is the worst case complexity - veyr bad
	if(root == NULL)
		return 0;

	int h1 = getHeight(root->left);
	int h2 = getHeight(root->right);
	
	int op1 = h1 + h2;
	int op2 = getDiameter(root->left);
	int op3 = getDiameter(root->right);

	return max(op1, max(op2, op3));
}

Pair getDiameterFast(node *root){
	// ------- O(n) very good
	Pair p;
	if(root==NULL){
		p.height = 0;
		p.diameter = 0;
		return p;
	}
	// based on bottom up approach - post order traversal.
	Pair left  = getDiameterFast(root->left);
	Pair right = getDiameterFast(root->right);
	p.height   = max(left.height, right.height)+1;
	p.diameter = max(max(left.diameter, right.diameter), left.height + right.height);
	return p;
}

int main(){

node *root =  buildTree();
// cout<<getDiameter(root)<<endl;

Pair p = getDiameterFast(root);
cout<<p.height<<endl;
cout<<p.diameter<<endl;

return 0;
}