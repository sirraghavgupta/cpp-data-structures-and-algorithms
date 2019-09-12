/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 10 august 2019
AIM    : to check if a tree is valid BST
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
// #include <climits>	// not required in THIS MY version of compiler
using namespace std;

class node{
public:
	node *left;
	int data;
	node *right;

	node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

class Pair{
public:
	int min;
	int max;
	bool isBST;
};

void insert_BST(node *&root, int val){
	// insert the val into a tree with root
	if(root==NULL){
		root = new node(val);
		return;
	}

	if(val<=root->data)
		insert_BST(root->left, val);
	else
		insert_BST(root->right, val);

	return;
}

void build_BST(node *&root){
	// keep on inputing values and -1 to stop
	int val;
	cin>>val;
	while(val!=-1){
		insert_BST(root, val);
		cin>>val;
	}
}

void printInOrder(node *root){
	if(root==NULL)
		return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
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

Pair isBST(node *root){

	// B O T T O M   U P   A P P R O A C H   I M P L E M E N T A T I O N
 
	Pair p;
	// base case
	if(root==NULL){
		p.min=INT_MAX;
		p.max=INT_MIN;
		p.isBST = true;
		return p;
	}

	// Rec case
	Pair left  = isBST(root->left);
	Pair right = isBST(root->right);
	p.min = min(root->data, min(left.min, right.min));
	p.max = max(root->data, max(left.max, right.max));
	if(left.isBST && right.isBST && left.max<=root->data && right.min>=root->data){
		p.isBST = true;
	}
	else
		p.isBST = false;
	return p;
}

bool isBST(node *root, int min, int max){

	// T O P   D O W N   A P P R O A C H   I M P L E M E N T A T I O N

	if(root==NULL)
		return true;

	if(root->data<=max && root->data>=min){
		bool left  = isBST(root->left, min, root->data);
		bool right = isBST(root->right, root->data, max);
		return left&&right;
	}
	return false;

}

node* buildTree(){
	// to build a normal tree
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

int main(){

node *root = NULL;
root = buildTree();
bfs(root);
printInOrder(root);
cout<<endl;

isBST(root, INT_MIN, INT_MAX)?cout<<"true"<<endl:cout<<"false"<<endl;

return 0;
}
