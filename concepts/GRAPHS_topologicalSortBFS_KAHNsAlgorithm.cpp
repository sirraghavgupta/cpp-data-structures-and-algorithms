/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 october 2019
AIM    : print the graph in topological manner.
		 all the dependencies of any node should be printed before that.
		 the graph will be DAG [directed acyclic graph]
STATUS : !!! success !!! -- awesome 
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


	void bfsTopologicalSort(){
		map<T, bool> visited;
		map<T, int> indegree;
		queue<T> q;

		for(auto i : adjList){
			// i is a pair <node, list>
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		// initialise the indegrees 
		for(auto i : adjList){
			T node = i.first;
			for(auto vertex : i.second){
				indegree[vertex]++;
			}
		}

		// initialise the queue with all nodes with indegree 0
		for(auto i : adjList){
			T node = i.first;
			if(indegree[node]==0)
				q.push(node);
		}

		// start the processing now
		while(!q.empty()){
			T node = q.front();
			q.pop();
			cout<<node<<", ";

			for(auto neighbour : adjList[node]){
				indegree[neighbour]--;
				if(indegree[neighbour]==0)
					q.push(neighbour);
			}
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

g.bfsTopologicalSort();

return 0;
}