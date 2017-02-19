//Dijkstra Implementation using Prim Method and Adjacency Matrix
// O(V^2) Shortest Path Algorithm
// IMPORTANT: INITIALIZE YOUR DISTANCE ARRAY TO INFINITY SOMEHOW IN YOUR PROGRAM!!
#include <iostream> 
#include <cstring> 

using namespace std; 

const int maxV = 2501; 
const int INF = 1 << 20; 
int mat[maxV][maxV];
int dist[maxV]; 
bool mark[maxV]; 
int V, E; 

int Dijkstra(int S, int D){   //start, destination
	memset(dist, 0x3F, sizeof(dist)); 
	memset(mark, false, sizeof(mark)); 
	dist[S] = 0; 
	for (int m = 0; m<V-1; m++){
		/** Look for minimum unmarked distance **/ 
		int u = -1;  //keeps the min vertex 
		for (int i = 1; i <= V; i++){
			if (!mark[i] && (u == -1 || dist[i] < dist[u]))
				u = i; 
		}
		mark[u] = true; 
		if (u == D) break; 
		/** Relax neighbors of u **/
		for (int i = 1; i <= V; i++){
			if (!mark[i] && mat[u][i] + dist[u] < dist[i]){
				dist[i] = mat[u][i] + dist[u]; //relax 	
			}
		}
	}
	return ((D == -1 || dist[D] == INF) ? -1 : dist[D]); //returns distance to D
}

int main() {
	int S; 
	int D = -1; //destination
	cin >> V >> E >> S; 

	for (int i = 1;i<V+1; i++){
		for (int j = 1; j<V+1; j++){
			mat[i][j] = INF; 
		}
	}

	int x,y, C; 
	for (int i = 0; i<E; i++){ // receiving input
		cin >> x >> y >> C;
		mat[x][y] = C; 
		mat[y][x] = C;  //remove if directed
	}

	Dijkstra(S,D); 	

	for (int i = 1; i<V+1; i++){
		cout << ((dist[i]< INF) ? dist[i] : -1) << endl; 
	}

	return 0; 
}
