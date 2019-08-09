/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : build tree from preorder and inorder given
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

int linearSearch(int arr[], int s, int e, int key){
	for(int i=s; i<=e; i++){
		if(arr[i] == key)
			return i;
	}
	return -1;
}

node* buildTreeFromPreAndIn(int pre[], int s1, int e1, int in[], int s2, int e2){
	
	int rI = linearSearch(pre, s1, e1, pre[s]);
	node *root = new node(pre[0]);
	root->left  = buildTreeFromPreAndIn(pre, s1+1, rI, in, s2, rI-1);
	root->right = buildTreeFromPreAndIn(pre, s1+rI+1, e1, in, rI+1, e2);
	return root;
}

int main(){

int n;
cin>>n;

int pre[n];				// preorder traversal
for(int i=0; i<n; i++)
	cin>>pre[i];

int in[n];				// postorder traversal
for(int i=0; i<n; i++)
	cin>>in[i];

node *root = buildTreeFromPreAndIn(pre, 0, n-1, in, 0, n-1);
bfs(root);

return 0;
}