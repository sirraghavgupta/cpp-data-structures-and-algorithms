/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 october 2019
AIM    : print the graph in topological manner.
		 all the dependencies of any node should be printed before that.
		 the graph will be DAG [directed acyclic graph]
STATUS : !!! success !!! -- super logic, awesome
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
	map<T, list<T>> adjList;

public:
	void addEdge(T u, T v, bool bidirectional=true){
		adjList[u].push_back(v);

		if(bidirectional)
			adjList[v].push_back(u);
	}

	void printList(){
		for(auto it:adjList){
			cout<<it.first<<" -> ";

			for(auto vertex:it.second){
				cout<<vertex<<", ";
			} 

			cout<<endl;
		}
	}

	void bfs(T src){
		map<T, bool> visited;		// for generic visited array
		queue<T> q;					

		q.push(src);		// push start node 
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			for(auto neighbour : adjList[node]){

				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}

			cout<<node<<", ";
			q.pop();
		}
		cout<<endl;
	}


	void dfsTopologicalHelper(T node, map<T, bool> &visited, list<T> &order){

		visited[node] = true;

		// Rec case
		for(auto neighbour : adjList[node]){
			// for every unvisited neighbour, do DFS.
			if(!visited[neighbour])
				dfsTopologicalHelper(neighbour, visited, order);
		}

		// now i have processed all the children of node, so i can push it into the list.
		// push the node into head of list before returning 
		order.push_front(node);
	}

	void dfsTopologicalSort(){
		map<T, bool> visited;
		list<T> order;

		for(auto i:adjList){
			// for every node in the adjacency list of graph 
			auto node = i.first;
			// if node is unvisited, call DFS 
			if(!visited[node]){
				dfsTopologicalHelper(node, visited, order);
			}
		}

		//print the toplogical order
		for(auto node : order){
			cout<<node<<", ";
		}
		cout<<endl;
	}
};

int main(){

Graph<string> g;
g.addEdge("English", "Programming Logic", false);
g.addEdge("Math", "Programming Logic", false);
g.addEdge("English", "HTML", false);
g.addEdge("Programming Logic", "HTML", false);
g.addEdge("Programming Logic", "JS", false);
g.addEdge("Programming Logic", "Python", false);
g.addEdge("Programming Logic", "Java", false);
g.addEdge("HTML", "CSS", false);
g.addEdge("CSS", "JS", false);
g.addEdge("JS", "Web Development", false);
g.addEdge("Java", "Web Development", false);
g.addEdge("Python", "Web Development", false);

g.dfsTopologicalSort();

return 0;
}