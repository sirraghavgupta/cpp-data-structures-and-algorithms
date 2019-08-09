/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 9 august 2019
AIM    : to check if a tree is height balanced or not
STATUS : !!! success !!!
TIME   : O(n)
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

class Pair{
public:
	int height;
	bool balance;
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

Pair isHeightBalanced(node *root){
	// top down approach will be O(n^2), so i'll follor bottom up approach
	Pair p;
	// Base case
	if(root==NULL){
		p.height = 0;
		p.balance = true;
		return p;
	}

	// Rec case
	Pair left = isHeightBalanced(root->left);
	Pair right = isHeightBalanced(root->right);

	p.height =  1 + max(left.height, right.height);

	if(left.balance && right.balance){
		if(abs(left.height - right.height)<=1)
			p.balance = true;
		else
			p.balance = false;
	}
	else{
		p.balance = false;
	}
	return p;
}

int main(){

node *root =  buildTree();
Pair p = isHeightBalanced(root);
cout<<p.height<<endl;
cout<<p.balance<<endl;
return 0;
}