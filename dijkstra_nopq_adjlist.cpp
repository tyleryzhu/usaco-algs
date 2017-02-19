//Dijkstra Implementation using Prim Method and Adjacency Lists
// O(E+V^2) Shortest Path Algorithm
#include <iostream> 
#include <climits>
#include <vector> 

using namespace std; 

typedef pair<int, int> ii; 
typedef vector<ii> vii; 
#define REP(i,a,b) \
	for (int i  = int(a); i<int(b); i++)
const int maxV = 2501; 
const int INF = INT_MAX;  

vii graph[maxV]; 
int dist[maxV]; 
bool mark[maxV]; 
int V, E;  

int Dijkstra(int S, int D){ //destination 
	REP(i, 1, V+1){
		dist[i] = INF;   // initialize to huge values
		mark[i] = false; 		//initialize all to unvisited 
	}

	dist[S] = 0; 
	mark[S] = true; 
	int i = S;  // start node
	REP(m, 0, V-1){
		if (i == D) break; 
		int min = INF; // initalize min as inf 
		REP(j, 0, graph[i].size()){  // iterate through neighbors of i, which is the minimum dist vert. 
			int currV = graph[i][j].first; 
			int currW = graph[i][j].second;
			if (dist[i]+ currW < dist[currV] && !mark[currV]){ //j must not be marked
				 // if the path from S to i and i to j is smaller than curr dist in dist[]
				dist[currV] = currW+dist[i]; // write in neighbors. 
			}
		}
		REP(j, 1, V+1){  					// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				i = j; 
			}
		}
		mark[i] = true;  				//found new min;  
	}

	return (D == -1) ? -1 : dist[D] ; 
}

int main() {
	int S; // starting node
	int D = -1;  //destination if necessary
	cin >> V >> E >> S; 

	int x,y, w; 
	REP(i,0,E){
		cin >> x >> y >> w; 
		graph[x].push_back(make_pair(y,w)); 
		graph[y].push_back(make_pair(x,w));  //remove if directed graph
	}

	Dijkstra(S, D);  // run dijkstras starting at S; 

	for (int i = 1; i<V+1; i++){ //output distances
		cout << ((dist[i] < INF) ? dist[i] : -1 )<< endl; 
	}
	return 0; 
}