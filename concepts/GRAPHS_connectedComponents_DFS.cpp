/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 october 2019
AIM    : to get the connected components in a graph 
STATUS : !!! success !!!
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

	void sssp(T src){
		// single source shortest path by using bfs
		// looks big, but its very simple 

		map<T, int> distance;		// instead of visited, we take distance
		map<T, T> parent; 			// no use here 
		queue<T> q;					

		for(auto i : adjList){
			// set initial distance to be infinity. 
			distance[i.first] = INT_MAX;	
		}

		q.push(src);		// push start node 
		distance[src] = 0;
		parent[src] = src;

		while(!q.empty()){

			T node = q.front();
			q.pop();
			for(auto neighbour : adjList[node]){

				if(distance[neighbour] == INT_MAX){
					// if it has not been visited yet, then allocate the distance 
					q.push(neighbour);
					distance[neighbour] = distance[node]+1;
					parent[neighbour] = node;
				}
			}
			
		}
		for(auto vertex : distance){
			// printing 
			cout<<vertex.first<<" -> "<<vertex.second<<endl; 
		}

	}


	void dfsHelper(T node, map<T, bool> &visited){
		// print the node and mark it visited 
		visited[node] = true;
		cout<<node<<", ";

		// Rec case
		for(auto neighbour : adjList[node]){
			// for every unvisited neighbour, do DFS.
			if(!visited[neighbour])
				dfsHelper(neighbour, visited);
		}
		
	}

	void dfs(T src){
		map<T, bool> visited;

		dfsHelper(src, visited);
		cout<<endl;
	}

	int getConnectedComponents(T src){
		int components = 1;
			
		map<T, bool> visited;
		dfsHelper(src, visited);
		cout<<endl;

		for(auto i : adjList){
			T node = i.first;
			if(!visited[node]){
				dfsHelper(node, visited);
				cout<<endl;
				components++;
			}
		}
		return components;
	}
};

int main(){

Graph<string> g;
g.addEdge("Amritsar", "Jaipur");
g.addEdge("Amritsar", "Delhi");
g.addEdge("Jaipur", "Delhi");
g.addEdge("Delhi", "Agra"); 
g.addEdge("Jaipur", "Mumbai");
g.addEdge("Delhi", "Bhopal");
g.addEdge("Mumbai", "Bhopal");
g.addEdge("Mumbai", "Bangalore");

g.addEdge("Andaman", "Nicobar");

cout<<g.getConnectedComponents("Amritsar")<<" components are there."<<endl;


return 0;
}