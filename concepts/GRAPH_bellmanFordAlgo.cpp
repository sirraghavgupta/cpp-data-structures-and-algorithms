/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 7 november 2019 
AIM    : to implement bellman ford Algorithm using dynamic programing
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

class Edge{
public:
	int src, dest, weight;
};

class Graph{
public: 
	int v, e;
	Edge *edge;
	// ctor
	Graph(int v, int e){
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}

	void addEdge(int u, int v, int w, int count){
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight = w;
	}
	void BellmanFord(int src){
		int distance[v];

		for(int i=0; i<v; i++){
			distance[i] = inf;
		}
		distance[src] = 0;

		// relaxation code
		for(int i=1; i<=v-1; i++){
			// relax all the edges for (v-1) times.
			for(int j=0; j<e; j++){
				// for all edges. 
				int src = edge[j].src;
				int dest = edge[j].dest;
				int wt = edge[j].weight;

				// relaxation check
				if(distance[src]!=inf && (distance[src]+wt)<distance[dest])
					distance[dest] = distance[src] + wt;
			}
		}

		// check for negative weight cycle
		for(int j=0; j<e; j++){
				int src = edge[j].src;
				int dest = edge[j].dest;
				int wt = edge[j].weight;

				// relaxation check
				if(distance[src]!=inf && (distance[src]+wt)<distance[dest]){
					cout<<"negative weight cycle detected "<<endl;
					return;
				}
		}

		// if no cycle, then print the distances. 
		for(int i=0; i<v; i++){
			cout<<i<<" -> "<<distance[i]<<endl;
		}
	}

};

int main(){

int v, e;
cin>>v>>e;

Graph g(v, e);

for(int i=0; i<e; i++){
	int u,v,wt;
	cin>>u>>v>>wt;

	g.addEdge(u, v, wt, i);
}

g.BellmanFord(0);

return 0;
}