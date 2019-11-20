/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 November 2019
AIM    : to check if a graph is bipartite or not. 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;


class Graph{
private:
	int n;
	map<int, list<int>> adjList;

public:
	Graph(int N){
		n = N;
	}

	void addEdge(int u, int v, bool bidirectional=true){
		adjList[u].push_back(v);

		if(bidirectional)
			adjList[v].push_back(u);
	}

	bool isBipartite_byBFS(int src){

		int color[n];
		for(int i=0; i<n; i++){
			color[i] = -1;
		}

		queue<int> q;
		q.push(src);
		color[src] = 0;		// color 1 

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto i : adjList[node]){
				// for every adjacent node
				if(color[i] == -1){
					// unvisited node
					color[i] = 1 - color[node];
					q.push(i);
				}
				// visited but same color - anomaly
				else if(color[i] == color[node]){
					return false;
				}
				// visited but correct color
				// do nothing. includes parent of node also
			}
		}
		return true;
	}
};

int main(){

// Graph g(4);
// g.addEdge(0,1);
// g.addEdge(1,2);
// g.addEdge(2,3);
// g.addEdge(3,0);
// // g.addEdge(0,2);	// anomaly edge 

// Graph g(5);
// g.addEdge(0,1);
// g.addEdge(1,2);
// g.addEdge(2,3);
// g.addEdge(3,4);
// g.addEdge(4,1);
// // g.addEdge(1,3);

// Graph g(5);
// g.addEdge(0,1);
// g.addEdge(0,2);
// g.addEdge(0,3);
// g.addEdge(1,4);
// g.addEdge(4,0);

Graph g(5);
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,1);


g.isBipartite_byBFS(0)?cout<<"yes"<<endl:cout<<"no"<<endl;

return 0;
}