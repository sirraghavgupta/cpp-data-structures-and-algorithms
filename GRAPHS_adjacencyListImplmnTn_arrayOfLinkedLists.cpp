/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 october 2019
AIM    : to implement the concept of graphs by using ADJACENCY LISTS.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
private:
	int v; 			// number of vertices
	list<int> *l;	// array of lists.

public:

	Graph(int n){
		v = n;
		l = new list<int>[v];	
	}

	void addEdge(int u, int v, bool bidirectional=true){
		l[u].push_back(v);
		if(bidirectional)
			l[v].push_back(u);
	}

	void printAdjList(){
		for(int i=0; i<v; i++){
			cout<<i<<" -> ";

			// for each loop -> for every list print the elements 
			for(int vertex:l[i])
				cout<<vertex<<", ";

			cout<<endl;
		}
	}
};

int main(){

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,0);
	g.addEdge(1,3);
	g.addEdge(1,4);

	g.printAdjList();

return 0;
}