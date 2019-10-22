/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 22 october 2019
AIM    : cycle detection in undirected graph using BFS
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

	bool detectCycle(T src){
		map<T, bool> visited;
		map<T, T> parent;
		queue<T> q;

		q.push(src);
		visited[src] = true;
		parent[src] = src;

		while(!q.empty()){
			T node = q.front();
			q.pop();

			for(auto neighbour : adjList[node]){
				
				// if the neighbour is already visited and is not the parent, then cycle found
				// rest all code is same as BFS 
				if(visited[neighbour]==true && neighbour!=parent[node]){
					return true;
				}
				else if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					parent[neighbour] = node;
				}
			}
		}
		return false;
	}

};

int main(){

Graph<int> g;
g.addEdge(1,0);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(0,4);
g.addEdge(4,3);
g.addEdge(3,5);

g.detectCycle(1)?cout<<"cycle detected"<<endl:cout<<"no cycle"<<endl;

/*Graph<string> g;

g.addEdge("Putin", "Trump", false);
g.addEdge("Putin", "Modi", false);
g.addEdge("Putin", "Pope", false);
g.addEdge("Trump", "Modi");
g.addEdge("Prabhu", "Modi", false);
g.addEdge("Yogi", "Prabhu", false);
g.addEdge("Yogi", "Modi");

g.bfs("Putin");*/


/*Graph<int> g;
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,0);
g.addEdge(1,3);
g.addEdge(1,4);
g.bfs(0);*/

return 0;
}