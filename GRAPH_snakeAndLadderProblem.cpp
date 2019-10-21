/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 21 october 2019
AIM    : find the shortest path(minimum number of dice throws) to reach the 
		 destination from the start point on a snake ladder board where snakes 
		 and ladders are actually present.
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

	void sssp(T src=0, T dest=36){
		// single source shortest path by using bfs
		// looks big, but its very simple 

		map<T, int> distance;		// instead of visited, we take distance
		map<T, T> parent; 			// useful to track the path 
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
		// we dont want to print all the distances.
		/*for(auto vertex : distance){
			// printing 
			cout<<vertex.first<<" -> "<<vertex.second<<endl; 
		}*/

		// print the final answer 
		cout<<distance[dest]<<endl;

		// print thr path also
		T temp = dest;
		cout<<temp;
		while(temp!=src){
			temp = parent[temp];
			cout<<" <- "<<temp;
		}
		cout<<endl;

	}

};

int main(){

Graph<int> g;

// to store the jump given by the ladders and the snakes
// all other nodes dont give any jump, so 0 value.
int board[50] = {0};
board[2] = 13;
board[5] = 2;
board[9] = 18;
board[17] = -13;
board[18] = 11;
board[20] = -14;
board[24] = -8;
board[25] = 10;
board[32] = -2;
board[34] = -22;

// build the graph actually 
for(int u=0; u<=36; u++){
	// u can throw a dice at every node.
	for(int dice = 1; dice<=6; dice++){
		// make a connection with all the reachable nodes. 

		// intial pos + dice jump + jump of ladder/snake.
		int v = u + dice + board[u+dice];
		g.addEdge(u, v, false);
	}
}

g.sssp();

return 0;
}