/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : build tree from preorder and inorder given
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
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

void printDifferent(node *root){
	// according to similar problem in course tree challenges
	if(root->left==NULL)
	cout<<root->left->data;
	cout<<" => ";
	cout<<root->data;
	cout<<" <= ";
	cout<<root->right->data;
	printDifferent(root->left)
}

int main(){

int n;
cin>>n;

int pre[n];				// preorder traversal
for(int i=0; i<n; i++)
	cin>>pre[i];

int in[n];				// inorder traversal
for(int i=0; i<n; i++)
	cin>>in[i];

node *root = buildTreeFromPreorderAndInorder(pre, in, 0, n-1);
bfs(root);

return 0;
}