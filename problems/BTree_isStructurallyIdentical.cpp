/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 17 august 2019
AIM    : Given two trees check if they are structurally identical
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
#include <cstring>
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


void printInOrder(node *root){
	if(root==NULL)
		return;
	printInOrder(root->left);
	cout<<root->data<<" ";
	printInOrder(root->right);
}



node* buildTree(){
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

bool isIdentical(node *a, node *b){
	if(a!=NULL && b!=NULL)
		return isIdentical(a->left, b->left) && isIdentical(a->right, b->right);

	if(a==NULL && b==NULL)
		return true;

	return false;
}

int main(){

cout<<"- - - for tree 1 - - -"<<endl;
node *root1 = buildTree();
bfs(root1);
cout<<endl;

cout<<"- - - for tree 2 - - -"<<endl;
node *root2 = buildTree();
bfs(root2);
cout<<endl;

isIdentical(root1, root2)?cout<<"identical"<<endl:cout<<"not identical"<<endl;

return 0;
}