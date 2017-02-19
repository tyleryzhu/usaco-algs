/** Binary Indexed Tree Implementation **/
#include <iostream>
#include <cstring>

using namespace std;

struct BIT{
	int* tree; 	//initializes array tree 
	int maxT; 

	BIT() {}; 	

	BIT(int n){ //constructor
		tree = new int[n+5]; 
		maxT = n+5; 
		memset(tree, 0, sizeof(int)*maxT); 
	}

	~BIT(){ //destructor
		delete[] tree; 
	}

	void update(int ind, int val){ //update value at index ind with val
		ind++; 
		while (ind < maxT){
			tree[ind] += val; 
			ind += (ind & -ind); 
		}
	}

	int query(int ind){ //query the sum [1...a]; 
		ind++; 
		int sum = 0; 
		while (ind > 0){
			sum += tree[ind]; 
			ind -= (ind & -ind); 
		}
		return sum; 
	}

	int query(int a, int b){ //query the sum [a...b];  (overloaded)
		return query(b)-query(a-1); 
	}

	void printarr(){
		for (int i = 0; i<maxT; i++){
			cout << tree[i] << " "; 
		}
		cout << endl; 
	}
}; 

int main() {
	BIT bit(10); 
	bit.printarr(); 
	cout << bit.query(10) << endl; 
	bit.printarr(); 
	bit.update(5, 10); 
	cout << bit.query(4) << " " << bit.query(5) << " " << bit.query(10) << " " << bit.query(6,10) << endl; 
}