//Prim's Algorithm
//Minimum Spanning Tree O(V^2)
// IMPORTANT: INITIALIZE YOUR DISTANCE ARRAY TO INFINITY SOMEHOW IN YOUR PROGRAM!!
#include <iostream> 

using namespace std; 

int mat[2000][2000];
int dist[2000]; 
bool mark[2000] = {false}; 
int V, E; 

int prims(int S){
	for (int i = 0; i<V; i++){ // reset on each run of prims 
		dist[i] = 1<< 20; 
		mark[i] = false;  
	}

	dist[S] = 0; 
	mark[S] = true; 
	int cost = S; 
	int i = S;  // min vertex counter; 
	for (int m = 0; m<V-1; m++){
		int min = 1<< 20; // initalize min as inf 
		for (int j = 0; j<V; j++){
			if (mat[i][j] < dist[j] && !mark[j]){   // if the dist from i to j is smaller than curr dist in dist[]
				dist[j] = mat[i][j]; // write in neighbors. 
			}
		}
		for (int j = 0; j<V; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				i = j; 
			}
		}
		mark[i] = true; 
		cost += dist[i]; 
	}
	return cost; 
}

int main() {
	cin >> V >> E; 
	for (int i = 0; i<V; i++){
		for (int j = 0; j<V; j++){
			mat[i][j] = (1<<20); // intialize arrays to huge values.  
			if (i ==j){
				mat[i][j] = 0; 
			}
		}
	}

	for (int i = 0; i<E; i++){ // receiving input
		int x,y, C; 
		cin >> x >> y >> C;
		if (C < mat[x-1][y-1]){
			mat[x-1][y-1] = C; 
			mat[y-1][x-1] = C; 
		}
	}

	cout << prims(0) << endl; 

}

