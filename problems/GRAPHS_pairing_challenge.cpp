/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 November 2019 
AIM    : There are N cities numbered from 0 to N-1. You have to choose 2 cities 
		 such that there is no path from first city to second city .
		 You are given information in the form of M pairs (X,Y) i.e there is an 
		 undirected road between city X and city Y.
		 Find out the number of ways in which cities can be chosen.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph{
public:
	ll n;
	map<int, list<int>> adj;

	Graph(ll N){
		n = N;
	}

	void addEdge(int u, int v, bool bidir = true){
		adj[u].push_back(v);
		if(bidir)
			adj[v].push_back(u);
	}

	void dfsHelper(int node, map<int, bool> &visited, ll &count){
		visited[node] = true;
		count++;

		for(auto neighbour : adj[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour, visited, count);
			}
		}
	}

	int dfs(){
		// for the purpose of counting the nodes in each connected component

		map<int, bool> visited;
		ll ans = n*(n-1)/2;
		cout<<ans<<endl;

		ll count=0;
		for(int node=0; node<n; node++){
			count=0;
			if(!visited[node]){
				dfsHelper(node, visited, count);
				cout<<count<<endl;
				ans -= count*(count-1)/2;
			}
		}
		return ans;
	}
};

int main(){

ll n, e;
cin>>n>>e;

Graph g(n);
for(int i=0; i<e; i++){
	int u,v;
	cin>>u>>v;

	g.addEdge(u,v);
}

cout<<g.dfs()<<endl;

return 0;
}

