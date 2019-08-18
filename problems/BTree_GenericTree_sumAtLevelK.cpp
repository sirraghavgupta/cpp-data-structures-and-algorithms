/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 august 2019
AIM    : Take input of a generic tree using buildtree() function and also take 
		 input K the level at which we need to find the sum.
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <vector>
using namespace std;

class Gnode{	// generic tree node
public:
	int data;
	int child;
	vector<Gnode*> v;

	Gnode(int val, int c){
		data = val;
		child = c;
		v.resize(c);
	}
};


Gnode* buildGenericTree(){
	int val, c;			// c is the number of children
	cin>>val;
	cin>>c;
	Gnode *root = new Gnode(val, c);

	if(c==0){
		return root;
	}
	else{
		for(int i=0; i<c; i++){
			root->v[i] = buildGenericTree();
		}
	}
	return root;
}

void printPreOrder(Gnode *root){	// modified for generic tree
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	for(int i=0; i<root->child; i++){
		printPreOrder(root->v[i]);
	}
}

int getSumOf_KthLevel(Gnode *root, int k){
	if(k==0){
		return root->data;
	}

	int sum=0;
	for(int i=0; i<root->child; i++){
		sum+=getSumOf_KthLevel(root->v[i], k-1);
	}
	return sum;
}


int main(){

Gnode *root = buildGenericTree();
printPreOrder(root);
cout<<endl;
int k;
cin>>k;
cout<<getSumOf_KthLevel(root, k)<<endl;

return 0;
}