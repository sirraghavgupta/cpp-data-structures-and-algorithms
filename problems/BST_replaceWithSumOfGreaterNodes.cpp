/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 31 august 2019
AIM    : replace all the elements in a BST with the sum of all elements greater
		 than or equal to it.
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
	// build a binary tree in preorder format and return the root node.
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

node* buildBalancedTree(int arr[], int s, int e){
	// to build a BST from its inorder traversal array
	if(s>e)
		return NULL;
	
	int mid = (s+e)/2;
	node *root = new node(arr[mid]);
	root->left = buildBalancedTree(arr, s, mid-1);
	root->right = buildBalancedTree(arr, mid+1, e);

	return root;
}


void printPreOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int replaceWithGreaterSum(node *&root, int sum){
	if(root==NULL)
		return sum;

	if(root->left == NULL && root->right == NULL){
		root->data = root->data + sum;
		return root->data;
	}
	
	int rightsum = replaceWithGreaterSum(root->right, sum);
	sum = root->data = root->data + rightsum;
	int leftSum = replaceWithGreaterSum(root->left, sum);

	return leftSum;
}

int main(){

// get the array
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

node *root =  buildBalancedTree(arr, 0, n-1);
// bfs(root);
replaceWithGreaterSum(root, 0);
printPreOrder(root);
cout<<endl;

return 0;
}