/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 November 2019 
AIM    : snake and ladder problem
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
	int n;
	map<int, list<int>> l;

	Graph(int N){
		n = N;
	}

	void addEdge(int u, int v, bool bidir=true){
		l[u].push_back(v);
		if(bidir)
			l[v].push_back(u);
	}

	void bfsSSSP(int src){
		// indexing of edges is from 1-n. so , we do accordingly 
		map<int, bool> visited;
		map<int, int> dist;

		for(auto i:l){
			int node = i.first;
			dist[node] = INT_MAX;
			visited[node] = false;
		}

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

		cout<<dist[n]<<endl;
	}

};

int main(){

int t;
cin>>t;

while(t--){

	int n, l, s;
	cin>>n>>l>>s;

	Graph g(n);

	// prepare the snake board 
	// l = ladders
	// s = snakes 
	int board[100] = {0};
	for(int i=0; i<l+s; i++){
		int u, v;
		cin>>u>>v;

		board[u] = v-u;
	}

	// build the graph
	for(int i=0; i<=n; i++){
		for(int dice=1; dice<=6; dice++){
			int j = i + dice + board[i+dice];
			g.addEdge(i, j, false);
		}
	}

	g.bfsSSSP(0);


}

return 0;
}

