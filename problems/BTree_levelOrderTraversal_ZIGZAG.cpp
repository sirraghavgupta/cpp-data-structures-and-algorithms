/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 1 september 2019
AIM    : print level order traversal of the three in zig zag manner
		 every level in new line
		 odd levels from L2R, even levels from R2L
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
#include <stack>
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

/*node* buildTree(){
	// build the binary tree in preorder formal using -1 method 
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
}*/

node* buildTree(){
	// build the binary tree in preorder formal using TRUE FALSE method
	string s;
	cin>>s;
	int data;
	if(s=="false")
		return NULL;
	else if(s=="true")
		cin>>data;
	else
		data = stoi(s);

	node *root = new node(data);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}


void levelOrder_ZigZag(node *root){

	stack<node*> s;	// for reversing the order only
	queue<node*> q;	// for normal bfs
	bool order = true;  // for L2R
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		
		node *n = q.front();

		if(n==NULL){
			q.pop();
			order = !order;
			while(!s.empty()){
				cout<<s.top()->data<<" ";
				s.pop(); 
			}
			cout<<endl;
			if(!q.empty())
				q.push(NULL);
		}

		else{
			if(order)
				cout<<n->data<<" ";
			else
				s.push(n);
			q.pop();
			if(n->left)
				q.push(n->left);
			if(n->right)
				q.push(n->right);
			}
	}
}

int main(){

node *root =  buildTree();
levelOrder_ZigZag(root);

return 0;
}