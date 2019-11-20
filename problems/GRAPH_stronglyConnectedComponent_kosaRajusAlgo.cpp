/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 17 november 2019
AIM    : to check whether a graph is a strongly connected component or not.
NOTE   : SCC is one where we can go from every vertex to every other vertex.
	     the logic is that if we have a path from u->v , then we should have 
	     a path from v->u also. 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
	map<T, list<T>> adjList;
	int n;

public:

	Graph(int N){
		n=N;
	}

	void addEdge(T u, T v, bool bidirectional=true){
		adjList[u].push_back(v);

		if(bidirectional)
			adjList[v].push_back(u);
	}

	void dfsHelper(int node, bool *visited, int &visitCount){
		// cout<<"visiting node "<<node<<endl;
		visited[node] = true;
		visitCount++;

		// go to all neighbours.
		for(auto neighbour : adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour, visited, visitCount);
			}
		}
	}

	bool kosaRaju_byDFS(){
		bool visited[n];

		// set all nodes to be false in visited array 
		for(int i=0; i<n; i++)
			visited[i] = false;
		// visited[0] = true;

		int visitCount = 0;
		dfsHelper(0, visited, visitCount);

		if(visitCount != n){
			// cout<<"exit in first round"<<endl;
			// cout<<visitCount<<endl;
			return false;
		}

		// reverse all the edges
		map<T, list<T>> newList;
		for(int i=0; i<n; i++){
			for(int j : adjList[i]){
				newList[j].push_back(i);
			}
		}

		adjList = newList;

		// set all nodes to be false in visited array 
		for(int i=0; i<n; i++)
			visited[i] = false;
		// visited[0] = true;

		visitCount = 0;
		dfsHelper(0, visited, visitCount);

		if(visitCount != n){
			// cout<<"exit in second round"<<endl;
			// cout<<visitCount<<endl;
			return false;
		}

		// cout<<"exit otherwise"<<endl;
		// cout<<visitCount<<endl;
		return true;
	}

};

int main(){

// Graph<int> g(3);
// g.addEdge(0,1,false);
// g.addEdge(0,2,false);
// g.addEdge(1,2,false);

// Graph<int> g(5);
// g.addEdge(0,1,false);
// g.addEdge(1,2,false);
// g.addEdge(2,3,false);
// g.addEdge(3,0,false);
// g.addEdge(3,4,false);
// g.addEdge(4,3,false);

// Graph<int> g(6);
// g.addEdge(0,1,false);
// g.addEdge(1,2,false);
// g.addEdge(2,3,false);
// g.addEdge(3,0,false);
// g.addEdge(3,4,false);
// g.addEdge(4,5,false);
// g.addEdge(5,3,false);

Graph<int> g(4);
g.addEdge(0,1,false);
g.addEdge(1,2,false);
g.addEdge(2,0,false);
g.addEdge(1,3,false);

g.kosaRaju_byDFS()?cout<<"yes"<<endl:cout<<"no"<<endl;

return 0;
}