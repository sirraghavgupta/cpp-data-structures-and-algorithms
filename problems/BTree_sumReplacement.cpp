/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : to replace each node with the sum of all the descendants.
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

int sumReplacement(node *root){
	if(root == NULL)	// if only one child id there, this condition is required
		return 0;

	if(root->left == NULL && root->right == NULL)	// leave leaf node untouched
		return root->data;

	int val = root->data;
	root->data = sumReplacement(root->left) + sumReplacement(root->right);
	return root->data + val;
}

int main(){

node *root =  buildTree();
bfs(root);
// after replacement
cout<<"---------"<<endl;
sumReplacement(root);
bfs(root);

return 0;
}