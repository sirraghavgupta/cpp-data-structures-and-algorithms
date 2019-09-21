/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 september 2019
AIM    : print a B tree in vertical order;
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <map>
#include <vector>
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

void printPreOrder(node *root){
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

void verticalOrderPrint(node *root, map<int, vector<int>> &m, int d){
	// explanation for d can be seen in the notebook, its trick.
	if(root==NULL)
		return;

	m[d].push_back(root->data);	// try to understand .
	verticalOrderPrint(root->left, m, d-1);
	verticalOrderPrint(root->right, m, d+1);
	return;
}

int main(){


node *root = buildTree();
// printPreOrder(root);

map<int, vector<int>> m;
verticalOrderPrint(root, m, 0);

// print the map now 
for(auto it=m.begin(); it!=m.end(); it++){
	int n = it->second.size();
	cout<<it->first<<"\t: ";
	for(int j=0; j<n; j++){
		cout<<it->second[j]<<", ";
	}
	cout<<endl;
}


return 0;
}