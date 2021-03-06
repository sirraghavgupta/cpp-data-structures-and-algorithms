/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : build tree from postorder and inorder given
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

node* buildTreeFromPostorderAndInorder(int *pre, int *in, int s, int e){
	static int i = e;
	// base case
	if(s>e)
		return NULL;

	// Rec case
	node *root = new node(pre[i]);		// place the root

	int index = linearSearch(in, s, e, pre[i]);		// search the root in inorder
	i--;
	// recursive for left tree and right tree
	root->right = buildTreeFromPostorderAndInorder(pre, in, index+1, e); 
	root->left  = buildTreeFromPostorderAndInorder(pre, in, s, index-1);

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

int post[n];				// preorder traversal
for(int i=0; i<n; i++)
	cin>>post[i];

int in[n];				// postorder traversal
for(int i=0; i<n; i++)
	cin>>in[i];

node *root = buildTreeFromPostorderAndInorder(post, in, 0, n-1);
bfs(root);

return 0;
}