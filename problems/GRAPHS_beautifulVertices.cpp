/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 November 2019 
AIM    : You are given a graph with N vertices and M edges. Master parent is the 
		 vertex which has no parent but may have 0 or more children. In any 
		 connected component of the graph, vertex with the lowest value in that 
		 component serves as the master parent. A vertex is called beautiful if 
		 it has more children than its parent. Count the number of beautiful 
		 vertices in the given graph. The graph has no cycles or self loops.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Graph{
public:
	int n;
	map<int, list<int>> adj;

	Graph(int N){
		n = N;
	}

	void addEdge(int u, int v, bool bidir = true){
		adj[u].push_back(v);
		if(bidir)
			adj[v].push_back(u);
	}

	int beautifulVertices_BFS(int src){
		// it sets the parent of all the nodes and gets the childCount of all nodes also.
		// then search for beautiful vertices in the given connected component 

		map<int, int> parent;
		int childCount[n+1] = {0};

		queue<int> q;
		q.push(src);
		parent[src] = src;

		while(!q.empty()){
			int node = q.front();
			q.pop();

			for(auto neighbour : adj[node]){
				if(neighbour != parent[node]){
					if(!parent[neighbour]){
						q.push(neighbour);
						childCount[node]++;
						parent[neighbour] = node;
					}
					else{
						childCount[node]++;
					}
				}
			}
		}

		// cout<<"parents"<<endl;
		// for(int i=1; i<=n; i++){
		// 	cout<<parent[i]<<endl;
		// }

		int ans = 0;
		for(int i=1; i<=n; i++){
			if(childCount[i]>childCount[parent[i]])
				ans++;
		}


		// print child count
		// cout<<"child count"<<endl;
		// for(int i=1; i<=n; i++){
		// 	cout<<childCount[i]<<" ";
		// }
		// cout<<endl;

		return ans;
	}

	// find the master node of all the connected components also
	
	void dfsHelper(int node, map<int, bool> &visited, int &min){
		visited[node] = true;

		// update master node if required. 
		if(node<min)
			min = node;

		for(int neighbour : adj[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour, visited, min);
			}
		}
	}

	vector<int> getMasternode_dfs(){
		// goes through all the connected components and get the master node from there. 
		vector<int> masterNodes;

		map<int, bool> visited;

		for(int i=1; i<=n; i++){
			int min = INT_MAX;

			if(!visited[i]){
				dfsHelper(i, visited, min);
				masterNodes.push_back(min);
			}
		}

		return masterNodes;
	}

};

int main(){

int n, e;	// nodes, edges 
cin>>n>>e;

Graph g(n);
// build the graph 
for(int i=0; i<e; i++){
	int u, v;
	cin>>u>>v;

	g.addEdge(u,v);
}

vector<int> masterNodes = g.getMasternode_dfs();

// cout<<"master nodes"<<endl;
// for(int i=0; i<masterNodes.size(); i++){
// 	cout<<masterNodes[i]<<" ";
// }
// cout<<endl;

int ans = 0;
for(int i=0; i<masterNodes.size(); i++){
	// find beautful vertices from all the connected components. 
	ans += g.beautifulVertices_BFS(masterNodes[i]);
}

cout<<ans<<endl;

return 0;
}

