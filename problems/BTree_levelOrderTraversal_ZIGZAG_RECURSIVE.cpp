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

node* buildTree(){
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
}

/*node* buildTree(){
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
}*/

int getHeight(node *root){
	// get the number of levels = get height
	if(root==NULL)
		return 0;
	int leftH = 1 + getHeight(root->left);
	int rightH = 1+ getHeight(root->right);
	return (leftH>rightH)?leftH:rightH;
}

void printKthlevel(node *root, int k, bool inverse){
	if(root==NULL)
		return;
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	if(inverse){
		printKthlevel(root->right, k-1, inverse);
		printKthlevel(root->left, k-1, inverse);
	}
	else{
		printKthlevel(root->left, k-1, inverse);
		printKthlevel(root->right,k-1, inverse);		
	}
	return;
}

void levelOrder_ZigZag(node *root){
	int levels = getHeight(root);

	for(int i=1; i<=levels; i++){
		if(i&1)
			printKthlevel(root, i, false);
		else
			printKthlevel(root, i, true);
		cout<<endl;
	}
	return;
}

int main(){

node *root =  buildTree();
levelOrder_ZigZag(root);

return 0;
}