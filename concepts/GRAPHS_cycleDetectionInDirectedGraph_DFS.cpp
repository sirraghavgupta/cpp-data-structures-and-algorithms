/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 24 october 2019
AIM    : cycle detection in directed graph using DFS 
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

	bool DFScycleDetectionHelper(T node, map<T, bool> &visited, map<T, bool> &inStack){
		
		// process the current node - visited, inStack 
		visited[node] = true;
		inStack[node] = true;

		// explore the neighbours of thec current node
		for(auto neighbour : adjList[node]){
			// for every unvisited neighbour, do DFS.
								// bhaiya version 
								// if((!visited[neighbour] && DFScycleDetectionHelper(neighbour, visited, inStack)) || inStack[neighbour])
								// 	return true;

			// case 1 = if neighbour is unvisited but its dfs call returns true 
			if(!visited[neighbour] && DFScycleDetectionHelper(neighbour, visited, inStack))
				return true;
			// case 2 = if neighbour is visited and its in stack also, then backedge exists
			if(visited[neighbour] && inStack[neighbour]){
				return true;
			}
			// case 3 = if node is visited but is not present in stack
			// comes in rest possibilities and we return false then at last. 
				
			
		}
		inStack[node] = false;
		return false;
	}

	bool detectCycle(){
		map<T, bool> visited;
		map<T, bool> inStack;

		// for evry node in the graph, make a dfs call. 
		for(auto i : adjList){
			T node = i.first;
								// bhaiya version 
								// if(!visited[node]){
								// 	bool cyclePresent = DFScycleDetectionHelper(node, visited, inStack);
								// 	if(cyclePresent)
								// 		return true;
								// } 

			// my version 
			// if the node is unvisited and its dfs call returns returns true, then return true also
			if(!visited[node] && DFScycleDetectionHelper(node, visited, inStack))
				return true;
		} 

		return false;
	}
};

int main(){

Graph<int> g;
g.addEdge(0, 1, false);
g.addEdge(0, 2, false);
g.addEdge(2, 3, false);
g.addEdge(2, 4, false);
g.addEdge(4, 5, false);
g.addEdge(1, 5, false);
g.addEdge(3, 0, false);

g.detectCycle()?cout<<"cycle found"<<endl:cout<<"cycle not found"<<endl;

return 0;
}