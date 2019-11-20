/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 november 2019 
AIM    : to implement prim's Algorithm
STATUS : !!! success !!! --- need to practice more.
##############################################################################*/

#include <bits/stdc++.h>
#define inf 1e9;
using namespace std;


class Vertex{
public:
	bool visited;
	int parent;
	int weight;
};

class Graph{
public:
	int v, e;
	list<pair<int,int>> *adj;	// array of lists of pair type
								// pair = (dest, weight)

	Graph(int v, int e){
		this->v = v;
		this->e = e;
		adj = new list<pair<int, int>>[v];		// adjacency list - array of lists of pair type 
	}

	~Graph(){
		delete [] adj;
	}

	void addEdge(int u,int v, int w){
		// add a bidirectional edge. 
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	int findMinVertex(Vertex ver[]){
		// return the index of the minimum index vertex to be picked now 
		// its must be initially unvisited. 
		int minIndex = -1;

		for(int i=0; i<v; i++){
			if(!ver[i].visited && (minIndex==-1 or ver[i].weight<ver[minIndex].weight)){
				minIndex = i;
			}
		}
		return minIndex;
	}

	void prims(){
		Vertex ver[v]; 	// table of the prim's algo + the visited map

		// initial setup of table
		for(int i=0; i<v; i++){
			ver[i].weight = inf;
			ver[i].visited = false;
		}
		//mark the props of src. 
		int src = 0;
		ver[src].weight = 0;
		ver[src].parent = -1;

		// pick a minimum weight unvisted vertex and process its neighbours. 

		for(int i=0; i<v; i++){
			// get the min weight vertex
			int minVertex = findMinVertex(ver);
			ver[minVertex].visited = true;

			// process the neighbours
			for(auto i : adj[minVertex]){
				int neighbour = i.first;
				if(!ver[neighbour].visited){
					// if we find a more closer node 
					if(i.second < ver[neighbour].weight){
						// update in the table 
						ver[neighbour].parent = minVertex;
						ver[neighbour].weight = i.second;
					}
				}
			}
		}

		// print the minimum spanning tree
		int totalWeight = 0;

		for(int i=1; i<v; i++){
			cout<<i<<" ------"<<ver[i].weight<<"------ "<<ver[i].parent<<endl;
			totalWeight += ver[i].weight;
		}
		cout<<totalWeight<<endl;
	}

};



int main(){

int v, e;
cin>>v>>e;

Graph g(v, e);

for(int i=0; i<e; i++){
	int u, v, w;
	cin>>u>>v>>w;

	g.addEdge(u,v,w);
}

g.prims();

return 0;
}

