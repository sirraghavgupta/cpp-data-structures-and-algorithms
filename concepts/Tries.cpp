/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 september 2019
AIM    : to implement the trie data structure. 
STATUS : !!! success !!!
##############################################################################*/

#include <iostream>
#include <unordered_map>
using namespace std;

#define hashmap unordered_map<char,node*>
// never use ; after this statement, it blows off my mind with error.

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
private:
	node *root;

public:
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

};

int main(){

trie t;

char word[20];
for(int i=0; i<5; i++){
	cin>>word;

	t.insert(word);
}

cin>>word;
t.search(word)?cout<<"word exists"<<endl:cout<<"word doesnt exists"<<endl;

return 0;
}