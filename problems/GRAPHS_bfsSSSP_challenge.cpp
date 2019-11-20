/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 November 2019 
AIM    : Consider an undirected graph consisting of 'n' nodes where each node is 
		 labeled from 1 to n and the edge between any two nodes is always of 
		 length 6 . We define node 's' to be the starting position for a BFS.
		 Given 'q' queries in the form of a graph and some starting node, 's' , 
		 perform each query by calculating the shortest distance from starting 
		 node 's' to all the other nodes in the graph. Then print a single line 
		 of n-1 space-separated integers listing node s's shortest distance to 
		 each of the n-1 other nodes (ordered sequentially by node number); if 
		 's' is disconnected from a node, print -1 as the distance to that node.
STATUS : !!! SUCCESS !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
	int n;
	list<int> *l;

	Graph(int N){
		n = N;
		l = new list<int>[n+1];
	}

	void addEdge(int u, int v, bool bidir=true){
		// by default the weight is 6 here. so, no need to take that
		l[u].push_back(v);
		if(bidir)
			l[v].push_back(u);
	}

	void bfsSSSP(int src){
		// indexing of edges is from 1-n. so , we do accordingly 
		bool visited[n+1] = {0};
		int dist[n+1];
		for(int i=0; i<=n; i++)
			dist[i] = INT_MAX;

		queue<int> q;
		
		q.push(src);
		visited[src] = true;
		dist[src] = 0;

		while(!q.empty()){

			int node = q.front();
			q.pop();

			for(auto neighbour : l[node]){
				if(!visited[neighbour]){
					visited[neighbour] = true;
					dist[neighbour] = dist[node] + 1;
					q.push(neighbour);
				}
			}
		}

		// print the distances
		for(int i=1; i<=n; i++){
			if(i!=src){
				if(dist[i] == INT_MAX)
					cout<<"-1"<<" ";
				else
					cout<<dist[i]*6<<" ";
			}
		}
		cout<<endl;
	}
};

int main(){

int q;
cin>>q;

while(q--){

	int n, e;
	cin>>n>>e;

	Graph g(n);
	// get the edges 
	for(int i=0; i<e; i++){
		int u, v;
		cin>>u>>v;
		g.addEdge(u,v);
	}
	int src;
	cin>>src;

	g.bfsSSSP(src);
}

return 0;
}



