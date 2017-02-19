#include <iostream>
#include <cstring>

using namespace std; 

int N, M;			// store # of nodes, edges  
int adj[2500][2500];  // adjacency list 
int parent[2500] = {0};   // parent array to store parents
int size[2500] = {0};  		// store the sizes of the components based on root node
int counter;

int find(int v) { //finds the root node of the component that v is in// should return v if v is the root
	if (v == parent[v]) return v; //base case
	parent[v] = find(parent[v]); //recursive
	return parent[v];  				//  parent becomes root node
}

void Union(int u, int v){				// unions u-component and v-component together 
	int uRoot = find(u);				// capital U b/c union is already defined awk 
	int vRoot = find(v); 
	if (uRoot == vRoot) return; 
	if (size[uRoot] < size[vRoot]){   	// if the u-component is smaller than the v-component (heurestic)
		parent[uRoot] = parent[vRoot];  // adding all vertices of u-component to the v component, so u-component vertices access v-component node
		size[vRoot] = size[uRoot]; 		// hence it is an optimization to add the smaller comp. to larger one so that less vertices need to access one extra
	}
	else {								// if v-component is smaller than u-component
		parent[vRoot] = parent[uRoot]; 
		size[uRoot] += size[vRoot]; 
	}
}


int main() {
    cin >> N >> M;
    memset(parent, -1, sizeof(parent)); 
	
    return 0;
}
