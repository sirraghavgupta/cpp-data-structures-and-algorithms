/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 august 2019
AIM    : breath first search travesal of tree 
		 it uses queue.
TIME   : O(n) -- efficient
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


/*	
// -------- A R C H I V E ------------
void bfs(node *root){
	// breadth first search
	// print without newline after every level
	queue<node*> q;

	q.push(root);

	while(!q.empty()){
		
		node *n = q.front();
		cout<<n->data<<" ";
		q.pop();
		if(n->left)
			q.push(n->left);
		if(n->right)
			q.push(n->right);
	}
	cout<<endl;
}*/


int main(){

node *root =  buildTree();
bfs(root);

return 0;
}