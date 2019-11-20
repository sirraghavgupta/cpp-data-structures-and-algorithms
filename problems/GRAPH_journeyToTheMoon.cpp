/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 15 November 2019 
AIM    : see shots 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
	int v;
	list<int> *l;	//adj list implementation 

	Graph(int n){
		v=n;
		l = new list<int>[n];
	}

	void addEdge(int u, int v){
		// taking bidirectional connections 
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void dfsHelper(int node, map<int, bool> &visited, int &country_size){
			
			visited[node] = true;
			country_size++;		// add node to country 

			for(int neighbour : l[node]){
				// for all unvisited neighbours of the node 
				if(!visited[neighbour]){
					dfsHelper(neighbour, visited, country_size);
				}
			}
			cout<<"country_size of "<<node<<" is "<<country_size<<endl;

	}

	int dfsMoon(){
		map<int, bool> visited;
		for(int i=0; i<v; i++){
			visited[i] = false;
		}
		// total ways possible 
		int total_ways = v*(v-1)/2;

		for(int i=0; i<v; i++){
			// start preparing country from a node, one connected component will be traversed.
			// next component will be processed later as country in the adjacency list later on. 
			if(!visited[i]){
				int country_size=0;
				dfsHelper(i, visited, country_size);
				// minus the no. of ways for those within the same country. 
				total_ways -= country_size*(country_size-1)/2;
			}
		}

		return total_ways;
	}

};

int main(){

Graph g(5);
g.addEdge(0,1);
g.addEdge(2,3);
g.addEdge(0,4);

cout<<g.dfsMoon()<<endl;

return 0;
}

