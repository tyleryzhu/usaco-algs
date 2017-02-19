// Dijkstra Implementation using Prim Method; Priority Queue + Adjacency List Implement
// O((E+V)log V) Runtime 
#include <iostream>
#include <queue>
#include <vector> 
#include <climits>

using namespace std; 

typedef pair<int, int> ii; 
typedef vector<ii> vii; 
#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)

const int MaxV = 50001; 
const int MaxE = 100000; 
const int INF = INT_MAX;  // initialize to max just in case, may be needed. won't overflow (why?)

vii graph[MaxV]; 
int dist[MaxV]; 
bool mark[MaxV]; 
int V, E; 

class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};

int Dijkstra(int S, int D){ //destination for stopping early  (pass -1 to go on for all)
	REP(i, 1, V+1){ 		//initializing dist to inf
		dist[i] = INF; 
		mark[i] = false; 
	}
	priority_queue<ii, vii, prioritize> pq; //priority queue of the node #s
	pq.push(make_pair(S,dist[S]=0)); // push in first vertex w/ edge of weight 0 
	while (!pq.empty()){
		int k = pq.top().first;  //min node
		pq.pop(); 
		if (mark[k]) continue; 
		mark[k] = true; 
		if (k == D) return; 

		REP(j, 0, graph[k].size()){
			int a = graph[k][j].first; //node of the neighbor of k; 
			int b = graph[k][j].second;  // weight of the edge to a
			if (!mark[a] && dist[a]> b+dist[k]) 	 // if distance is greater than edge
				pq.push(make_pair(a, dist[a] = b+dist[k])); 			//pushin the edge and update dist[a]
		}
	}
	return (D == -1 || dist[D] == INF) ? -1 : dist[D]; 
}

int main() {
	int S; // source
	cin >> V >> E >> S; 
	int x, y, c; 
	REP(i, 0, E){
		cin >> x >> y >> c; 
		graph[x].push_back(make_pair(y,c)); 
		graph[y].push_back(make_pair(x,c)); 
	}
	
	Dijkstra(S, -1); 

	REP(i, 1, V+1){
		cout << ((dist[i] == INF) ? -1 : dist[i]) << endl; 
	}	
	return 0; 
}