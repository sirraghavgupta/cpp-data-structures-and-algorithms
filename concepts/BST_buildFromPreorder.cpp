/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 16 august 2019
AIM    : build BST from preorder only
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
#include <algorithm>
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

int linearSearch(int arr[], int s, int e, int key){
	for(int i=s; i<=e; i++){
		if(arr[i] == key)
			return i;
	}
	return -1;
}

node* buildTreeFromPreorderAndInorder(int *pre, int *in, int s, int e){
	static int i = 0;
	// base case
	if(s>e)
		return NULL;

	// Rec case
	node *root = new node(pre[i]);		// place the root

	int index = linearSearch(in, s, e, pre[i]);		// search the root in inorder
	i++;
	// recursive for left tree and right tree
	root->left  = buildTreeFromPreorderAndInorder(pre, in, s, index-1);
	root->right = buildTreeFromPreorderAndInorder(pre, in, index+1, e); 

	return root;
}

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


int main(){

int n;
cin>>n;

int pre[n];				// preorder traversal
int in[n];				// inorder traversal
for(int i=0; i<n; i++){
	cin>>pre[i];
	in[i] = pre[i];
}

sort(in, in+n);

node *root = buildTreeFromPreorderAndInorder(pre, in, 0, n-1);
bfs(root);

return 0;
}