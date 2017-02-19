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
const int INF = INT_MAX;  

vii graph[MaxV]; 
int dist[MaxV]; 
bool mark[MaxV]; 
int V, E; 

class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};

int Prim(){
	REP(i, 1, V+1){ 		//initializing dist to inf
		dist[i] = INF; 
		mark[i] = false; 
	}
	priority_queue<ii, vii, prioritize> pq; //priority queue of the node #s
	pq.push(make_pair(1,dist[1]=0)); // push in first vertex w/ edge of weight 0 
	int sum = 0; 
	while (!pq.empty()){
		int k = pq.top().first;  //min node
		int w = pq.top().second; // weight of edge 
		pq.pop(); 
		if (mark[k]) continue; 
		sum += w; 
		mark[k] = true; 
		REP(j, 0, graph[k].size()){
			int a = graph[k][j].first; //node of the neighbor of k; 
			int b = graph[k][j].second;  // weight of the edge to a
			if (!mark[a] && dist[a]> b){ 	 // if distance is greater than edge
				dist[a] = b; 								//update distance array
				pq.push(graph[k][j]); 			//pushin the edge
			}
		}
	}
	return sum; 
}

int main() {
	cin >> V >> E; 
	int x, y, c; 
	REP(i, 0, E){
		cin >> x >> y >> c; 
		graph[x].push_back(make_pair(y,c)); 
		graph[y].push_back(make_pair(x,c)); 
	}
	
	cout << Prim() << endl; 
	return 0; 
}	