#include <iostream>

using namespace std; 

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

const int maxV = 600;
const int INF = 1<< 20; 
int V, E; 
int mat[maxV][maxV]; 

void Floyd(){
	REP(k, 1, V+1){
		REP(i, 1, V+1){
			REP(j, 1, V+1){
				if (mat[i][j] > mat[i][k] + mat[k][j]){
					mat[i][j] = mat[i][k] + mat[k][j]; 
				}
			}
		}
	}
}

int main() {
	cin >> v >> E;  // #nodes, # edges

	REP(i, 1, V+1){
		REP(i, 1, V+1){
			mat[i][j] = ((i == j) ? 0 : INF); 	
		}
	}

	REP(i, 0, E){
		int x, y, weight; 
		cin >> x >> y >> weight; 
		mat[x][y] = weight; 
		mat[y][x] = weight;  // remove if directed
	}

	Floyd(); 	

	REP(i, 1, V+1){
		REP(j, 1, V+1){
			cout << mat[i][j] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}