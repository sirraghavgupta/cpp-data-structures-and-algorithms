/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : print a B tree in vertical order;
MOD    : take level order input
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <queue>
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

int n;
cin>>n;

node *root = buildLevelOrder();

map<int, vector<int>> m;
verticalOrderPrint(root, m, 0);

// print the map now 
for(auto it=m.begin(); it!=m.end(); it++){
	int n = it->second.size();
	// cout<<it->first<<"\t: ";
	for(int j=0; j<n; j++){
		cout<<it->second[j]<<" ";
	}
	cout<<endl;
}


return 0;
}