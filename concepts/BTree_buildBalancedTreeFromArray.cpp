/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : build a balanced binary tree from an array
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
	if(s>e)
		return NULL;
	
	int mid = (s+e)/2;
	node *root = new node(arr[mid]);
	root->left = buildBalancedTree(arr, s, mid-1);
	root->right = buildBalancedTree(arr, mid+1, e);

	return root;
}

int main(){

// get the array
int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
	cin>>arr[i];

node *root =  buildBalancedTree(arr, 0, n-1);
bfs(root);

return 0;
}