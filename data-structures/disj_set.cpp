#include <iostream>
#include <queue>

using namespace std; 

int N, M;			// store # of nodes, edges  
int adj[2500][2500];  // adjacency list 
int parent[2500] = {0};   // parent array to store parents
int size[2500] = {0};  		// store the sizes of the components based on root node
int counter;
queue<int> q;

void bfs(int v){ 			// floodfill components and fill out parents array while doing so . 
    parent[v] = v;
    q.push(v);
    int start = v; 
    while (!q.empty()){
    	size[start]++; 			// keep the size of the component 
        v = q.front();
        q.pop();
        for (int i = 1; i <= N; i++){
            if (adj[v][i] && (parent[i] == -1)){
                parent[i] = v;
                q.push(i);
            }
        }
    }
}

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
    counter = 0;
    cin >> N >> M;
    for (int i = 1; i<=N; i++){  // initialize all parents as -1 
    	parent[i] = -1; 
    }

    for (int i = 0; i<M; i++){ // write the adjacency matrix
        int x, y, w; // two nodes + weight 
        cin >> x >> y >> w;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    
    sort(edges, edges+M, comp); //sort edges

    return 0;
}