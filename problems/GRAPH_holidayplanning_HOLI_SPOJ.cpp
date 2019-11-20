/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 17 november 2019 
AIM    : see on SPOJ - holiday planning
STATUS : !!! success !!! -- awesome 
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;
	
class Graph{
public:
	int n;
	list<pair<int, int>> *l;

	Graph(int N){
		n = N;
		l = new list<pair<int, int> >[n];
	}

	void addEdge(int u, int v, int w, bool bidir=true){
		l[u].push_back(make_pair(v, w));
		if(bidir)
			l[v].push_back(make_pair(u, w));
	}	

	void dfsHelper(int node, map<int, bool> &visited, map<int, int> &count, int &ans){

		visited[node] = true;
		count[node] = 1;

		// visit the neighbours now 
		for(auto i : l[node]){
			int neighbour = i.first;
			
			if(!visited[neighbour]){
				dfsHelper(neighbour, visited, count, ans);
				count[node] += count[neighbour];

				int transfer = min(count[neighbour], n-count[neighbour]);
				ans += 2*transfer*i.second;
			}
		}
		
	}

	int dfs(){
		map<int, bool> visited;
		map<int, int> count;
		for(int i=0; i<n; i++){
			visited[i] = false;
			count[i] = 0;
		}

		int ans=0;
		dfsHelper(0, visited, count, ans);
		

		for(int i=0; i<n; i++){
			cout<<i<<" -> "<<count[i]<<endl;
		}

		return ans;
	}
	
};

int main(){

// Graph g(5);
// g.addEdge(0,1,1);
// g.addEdge(0,2,2);
// g.addEdge(1,3,4);
// g.addEdge(1,4,3);

Graph g(4);
g.addEdge(0,1,3);
g.addEdge(1,2,2);
g.addEdge(2,3,2);

cout<<g.dfs()<<endl;

return 0;
}

