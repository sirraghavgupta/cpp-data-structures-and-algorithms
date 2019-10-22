/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 20 october 2019
AIM    : to implement graph using adjacency lists using hashmaps.
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
};

int main(){

Graph<string> g;

g.addEdge("Putin", "Trump", false);
g.addEdge("Putin", "Modi", false);
g.addEdge("Putin", "Pope", false);
g.addEdge("Trump", "Modi");
g.addEdge("Prabhu", "Modi", false);
g.addEdge("Yogi", "Prabhu", false);
g.addEdge("Yogi", "Modi");

g.printList();

return 0;
}