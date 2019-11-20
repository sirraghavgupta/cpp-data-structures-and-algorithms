/*##############################################################################
AUTHOR : RAGHAV GUPTA
DATE   : 8 november 2019 
AIM    : to implement Kruskal's Algorithm
STATUS : !!! success !!! - need to understand more alot. 
##############################################################################*/

#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src, dest, w;

	void getData(){
		cin>>src>>dest>>w;
	}
};

class Set{
	public:
		int rank;
		int parent;
};

int find(Set *set, int i){
	if(set[i].parent != i)
		set[i].parent = find(set, set[i].parent);
	return set[i].parent;
}

void Union(Set *set, int v1, int v2){
	int v1_root = find(set, v1);
	int v2_root = find(set, v2);
	if(set[v1_root].rank < set[v2_root].rank)
		set[v1_root].parent = v2_root;
	else if(set[v1_root].rank > set[v2_root].rank)
		set[v2_root].parent = v1_root;
	else{
		set[v2_root].parent = v1_root;
		set[v1_root].rank++;
	}
}

bool compare(Edge a, Edge b){
	return a.w < b.w;
}

class Graph{
public:
	int v, e;
	Edge *edge;

	Graph(int v, int e){
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}

	~Graph(){
		delete [] edge;
	}

	void Kruskal(){
		sort(edge, edge+e, compare);	// sort the edges in ascending order of weights.
		Edge *output = new Edge[v-1];	// the array for edges selected for MST
		Set *set = new Set[v];			// the array for all initial sets

		for(int i=0; i<v; i++){	
			set[i].rank = 0;			// initially, set rank=0
			set[i].parent = i;			// self parent - individual sets for each vertex. 
		}

		int counter = 0, i=0;
		while(counter<v-1){
			Edge currentEdge = edge[i];	// pick a minimum edge weight. 
			int sourceParent = find(set, currentEdge.src); // find the parent of src
			int destinationParent = find(set, currentEdge.dest);	// find parent of dest

			if(sourceParent != destinationParent){	// if they belong to differnt sets
				output[counter] = currentEdge;		// add that edge to MST
				Union(set, sourceParent, destinationParent);	// union them
				counter++;
			}
			i++;
		}

		// print all the edges of the minimum spaning tree
		int totalWeight = 0;
		for(int i=0; i<v-1; i++){
			cout<<output[i].src<<" ------"<<output[i].w<<"------ "<<output[i].dest<<endl;
			totalWeight += output[i].w;	// calculate the total weight of MST.
		}
		cout<<totalWeight<<endl;
		
		// free the memory
		delete [] output;
		delete [] set;
	}
};



int main(){

int v, e;
cin>>v>>e;

Graph g(v, e);

for(int i=0; i<e; i++){
	g.edge[i].getData();
}

g.Kruskal();

return 0;
}

