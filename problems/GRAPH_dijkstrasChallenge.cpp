/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 18 november 2019
AIM    : dijkstra- only diff is that print -1 for unreachhable nodes.
STATUS : !!! success !!!
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
private:
	int n;
	unordered_map<T, list<pair<T, int>>> m;		// adjacency list basically 

public:
	Graph(int N){
		n = N;
	}

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
		// for(auto i:m){
		// 	dist[i.first] = INT_MAX;
		// }

		for(int i=1; i<=n; i++){
			dist[i] = INT_MAX;
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
		for(int i=1; i<=n; i++){
			if(i != src){
				// cout<<i<<" -> ";
				if(dist[i]==INT_MAX)
					cout<<"-1"<<" ";
				else
					cout<<dist[i]<<" ";
			}
		}
		cout<<endl;
	}
};

int main(){

int t;
cin>>t;

while(t--){

	int n, e;
	cin>>n>>e;

	Graph<int> g(n);
	
	for(int i=0; i<e; i++){
		int u, v, w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	int src;
	cin>>src;

	g.dijkstraSSSP(src);
}


return 0;
}