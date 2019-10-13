/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : Peter found a digital dictionary which is far better than normal 
		 dictionaries. The digital dictionary has an input field in which one 
		 can search any string and the dictionary displays all the words whose 
		 prefix is that input string. Now you are given a task to make your own 
		 digital dictionary. You will be given words that you can store in your 
		 database and then you need to design the search functionality. And if 
		 no such words are available, add this word to your dictionary and print
		 "No suggestions". 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

#define hashmap map<char,node*>

class node{
public:
	char data;
	hashmap h;			// to store the address of branches 
	bool isTerminal;	// whether its terminal node or not 

	node(char val){
		data = val;
		isTerminal = false;	// default non terminal
	}
};

class trie{
// private:

public:
	node *root;

	trie(){
		root = new node('\0');	// root doesnt contain any data in tries.
	}

	// insert word
	void insert(char *word){
		node *temp = root;
		// iterate over the word for each char 
		for(int i=0; word[i]!='\0'; i++){
			char ch = word[i];
			// if branch exists, go there 
			if(temp->h.count(ch))
				temp = temp->h[ch];
			else{
				// create a new branch for that char
				temp = temp->h[ch] = new node(ch);
			}
		}
		// set last char node to be terminal
		temp->isTerminal = true;
	}

	// lookup a word 
	bool search(char *word){
		node *temp = root;

		for(int i=0; word[i]!='\0'; i++){
			char ch = word[i];
			// if branch for char not found 
			if(temp->h.count(ch) == 0)
				return false;
			else{
				// go to the branch if exists
				temp = temp->h[ch];
			}
		}
		// now u are at terminal or not.
		return temp->isTerminal;
	}

	// check the existence of a character sequence - not complete word
	node* checkExistence(char *word){
		node *temp = root;

		for(int i=0; word[i]!='\0'; i++){
			char ch = word[i];
			// if branch for char not found 
			if(temp->h.count(ch) == 0)
				return NULL;
			else{
				// go to the branch if exists
				temp = temp->h[ch];
			}
		}
		// now u are at terminal or not.
		return temp;
	}

};

// print all the strings which have word as their prefix. 
void dfsPrint(node* temp, char *word){

// Base Case

	// if the word is a terminal, print this.
	if(temp->isTerminal)
		cout<<word<<endl;
	// if no more children are there
	if(temp->h.size() == 0)
		return;

// Rec Case
	// create modified word to pass to next node 
	char w[30];
	strcpy(w, word);
	// for every node in the hashmap of current node 
	for(auto n:temp->h){
		// add the char of the child and call dfs.
		int len = strlen(word);
		w[len++] = n.second->data;
		w[len++] = '\0';

		dfsPrint(n.second, w);
	}
}

int main(){

trie t;

int n;
cin>>n;
char word[31];

// build the database 
for(int i=0; i<n; i++){
	cin>>word;
	t.insert(word);
}

// process the queries now.
int q;
cin>>q;
while(q--){
	cin>>word;
	
	// if the word doesnt exist - add it in database
	node *target = t.checkExistence(word);
	if(target == NULL){
		t.insert(word);
		cout<<"No suggestions"<<endl;
	}

	else
		dfsPrint(target, word);

}


return 0;
}