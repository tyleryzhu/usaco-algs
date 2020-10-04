/*
Input will be of the form: N, E, and then followed by E lines with A, B, C where A,B are nodes, C is weight
N E
A B C 
...
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

const int VertMax = 50000; 
const int EdgeMax = 200000; 

struct edge{
	int a, b, w; // a,b are the nodes, w is the weight/value of the edge 
};

bool comp(edge a, edge b){  //for a custom sort
        return (a.w < b.w); 
}

int N, M;			// store # of nodes, edges  
int parent[VertMax] = {0};   // parent array to store parents
int size[VertMax] = {0};  		// store the sizes of the components based on root node
edge edges[EdgeMax];            // store the edges (edge list)
edge MST[VertMax];              // keep track of edges used in MST

int find(int v) { //finds the root node of the component that v is in// should return v if v is the root
    return (v==parent[v]) ? v : (parent[v] = find(parent[v])); 
    /*
	if (v == parent[v]) return v; //base case
	parent[v] = find(parent[v]); //recursive
	return parent[v];  				//  parent becomes root node
    */
}

void Union(int u, int v){				// unions u-component and v-component together 
	int uRoot = find(u);				// capital U b/c union is already defined awk 
	int vRoot = find(v); 
	if (uRoot == vRoot) return; 
	if (size[uRoot] < size[vRoot]){   	// if the u-component is smaller than the v-component (heurestic)
		parent[uRoot] = parent[vRoot];  // adding all vertices of u-component to the v component, so u-component vertices access v-component node
		size[vRoot] += size[uRoot]; 		// hence it is an optimization to add the smaller comp. to larger one so that less vertices need to access one extra
	}
	else {								// if v-component is smaller than u-component
		parent[vRoot] = parent[uRoot]; 
		size[uRoot] += size[vRoot]; 
	}
}

int Kruskal(){
    sort(edges, edges+M, comp); //sort edges

    int cost = 0; // keep track of MST cost 
    int counter = 0; //keep a counter for MST edges

    //Kruskal's Algorithm
    for(int i = 0; i<M; i++){                       //iterate through edges (sorted)
        int A = find(edges[i].a);                   // save find so we call find twice not four times worst case
        int B = find(edges[i].b); 
        if (A != B){  // edge is not in MST yet
            cost += edges[i].w;                     // add cost to MST cost
            MST[counter] = edges[i];                // add edge to MST
            counter++;                              // increment
            Union(A,B);             // union them 
        }
        if (counter == N-1) break; 
    }
    return cost; 
}

int main() {
    cin >> N >> M;
    for (int i = 1; i<=N; i++){  // initialize all parents to themselves
    	parent[i] = i; 
    }

    for (int i = 0; i<M; i++){ // write the adjacency matrix
        int x, y, w; // two nodes + weight 
        cin >> x >> y >> w;
        edges[i].a = x; 
        edges[i].b = y; 
        edges[i].w = w; 
    }

    cout << Kruskal() << endl; 

    return 0;
}
