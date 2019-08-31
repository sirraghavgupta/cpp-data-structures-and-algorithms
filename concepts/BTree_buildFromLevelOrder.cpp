/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 31 august 2019
AIM    : build tree from level order array
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
	// build the tree in preorder format and return the root node.
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

node* buildLevelOrder(){
	queue<node*> q;

	int val; 
	cin>>val;
	if(val==-1)
		return NULL;
	
	node *root = new node(val);
	q.push(root);


	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		cin>>val;
		if(val==-1)
			temp->left = NULL;
		else{
			temp->left = new node(val);
			q.push(temp->left);
		}
		cin>>val;
		if(val==-1)
			temp->right = NULL;
		else{
			temp->right = new node(val);
			q.push(temp->right);
		}
	}
	return root;

}

int main(){

node *root = buildLevelOrder();
bfs(root);

return 0;
}