/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 24 october 2019
AIM    : to implement dijkstra's algorithm
		 BFS algo doesnt work of graph having weights, so we have this

		 Dij.. works only if the graph doesnt have a negativwe weight cycle

TIME   : O(ElogV) time 
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
	unordered_map<T, list<pair<T, int>>> m;		// adjacency list basically 

public:
	void addEdge(T u, T v, int dist, bool bidirectional=true){
		m[u].push_back(make_pair(v, dist));

		if(bidirectional)
			m[v].push_back(make_pair(u, dist));
	}

	void printList(){
		for(auto it:m){
			cout<<it.first<<" -> ";

			for(auto vertex:it.second){
				cout<<"( "<<vertex.first<<" , "<<vertex.second<<" )";
			} 

			cout<<endl;
		}
	}

	void dijkstraSSSP(T src){
		// set up the initial dist array 
		map<T, int> dist;	// stores the shortest distance 
		for(auto i:m){
			dist[i.first] = INT_MAX;
		}
		dist[src] = 0;

		//now do the processing
		set<pair<int, T>> s;	// this set represents the table which we make while solving on paper
						// difference is that here we remove the column for the node selected
						// which we crossed/copied same in the table while on paper. 

			// set<distance, node> because set is sorted according to the first element always 

		s.insert(make_pair(0, src));

		while(!s.empty()){
			// get the shortest distance node from the set 
			auto shortest = *(s.begin());	// always at first as set is sorted 
			T selNode = shortest.second;	// name of selected node
			int nodeDist = shortest.first;	// distance of selected node 
			s.erase(s.begin());				// remove from set 

			// itertate over all the neighbours of the node in the adjList = map 
			for(auto neighbour : m[selNode]){
				int newDist = nodeDist + neighbour.second;	// 'second' bcoz we are using list here, not the set 
				int oldDist = dist[neighbour.first];

				if(newDist < oldDist){
					// remove the existing pair if exists
					auto f = s.find(make_pair(oldDist, neighbour.first));
					if(f!=s.end()){
						s.erase(f);
					}
					// insert the new pair
					s.insert(make_pair(newDist, neighbour.first));
					dist[neighbour.first] = newDist;
				}
			}
		}
		// print the shortest distances
		for(auto d : dist){
			cout<<d.first<<" -> "<<d.second<<endl;
		}
	}
};

int main(){

/*Graph<int> g;

g.addEdge(1, 2, 1);
g.addEdge(1, 3, 4);
g.addEdge(1, 4, 7);
g.addEdge(3, 4, 2);
g.addEdge(2, 3, 1);
g.dijkstraSSSP(1);
*/

Graph<string> india;
india.addEdge("Amritsar", "Delhi", 1);
india.addEdge("Amritsar", "Jaipur", 4);
india.addEdge("Jaipur", "Delhi", 2);
india.addEdge("Jaipur", "Mumbai", 8);
india.addEdge("Bhopal", "Agra", 2);
india.addEdge("Mumbai", "Bhopal", 3);
india.addEdge("Agra", "Delhi", 1);

// india.printList();
india.dijkstraSSSP("Amritsar");

return 0;
}