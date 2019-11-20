/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 3 november 2019
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

	bool detectCycleHelper(T node, map<T,bool> &visited, T parent){
		// little different from bhaiya but looks fine to me. 
		if(visited[node])
			return true;

		visited[node] = true;
		for(auto neighbour : adjList[node]){
			if(neighbour!=parent){
				bool res = detectCycleHelper(neighbour, visited, node);
				if(res)
					return true;
			}
		}
		return false;

	}

	bool detectCycle(){
		map<T, bool> visited;

		for(auto i : adjList){
			T node = i.first;
			if(!visited[node]){
				bool res = detectCycleHelper(node, visited, node);
				if(res)
					return true;
			}
		}

		return false;
	}

};

int main(){

/*Graph<int> g;
g.addEdge(1,0);
g.addEdge(1,2);
g.addEdge(2,4);
g.addEdge(2,3);
g.addEdge(0,4);
g.addEdge(4,3);
g.addEdge(3,5);*/


/*Graph<string> g;
g.addEdge("Putin", "Trump");
g.addEdge("Putin", "Modi");
g.addEdge("Putin", "Pope");
g.addEdge("Trump", "Modi");
g.addEdge("Prabhu", "Modi");
g.addEdge("Yogi", "Prabhu");
g.addEdge("Yogi", "Modi");*/



/*Graph<int> g;
g.addEdge(0,1);
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,0);
g.addEdge(1,3);
g.addEdge(1,4);*/

Graph<int> g;
g.addEdge(1,2);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(4,1);

g.detectCycle()?cout<<"cycle detected"<<endl:cout<<"no cycle"<<endl;

return 0;
}