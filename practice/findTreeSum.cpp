/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 september 2019
AIM    : to find the sum of nodes in a binary tree
		 build a balanced binary tree from input first
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

node* buildBalancedBinaryTree(int arr[], int s, int e){
	// base case
	if(s>e)
		return NULL;

	// rec case
	int mid = (s+e)/2;
	node *root = new node(arr[mid]); 
	root->left = buildBalancedBinaryTree(arr, s, mid-1);
	root->right = buildBalancedBinaryTree(arr, mid+1, e);
	return root;
}

void printPreOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);	
}

int getSum(node *root){
	// base case
	if(root==NULL)
		return 0;

	// rec case
	return root->data + getSum(root->left) + getSum(root->right);
}


int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

node *root = buildBalancedBinaryTree(arr,0, n-1);
// printPreOrder(root);
cout<<getSum(root)<<endl;
return 0;
}