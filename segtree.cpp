// Segment Tree Implementation of Range Minimum Query 
// O(n) Space, O(n) construction to make, O(logN) for queries 
#include <iostream>
#include <cstring> 

using namespace std; 

const int INF = 1 << 30; 

struct SegTree{
	int* segTree; //initializes segtree array 
	int segLen; 

	SegTree() {}; 

	void construct_Tree(int arrs[], int low, int hi, int pos){ //recursive function for making the segtree
		if (low == hi){ //same element of the input array
			segTree[pos] = arrs[low];  // min from [low, hi] if low== hi is just arrs[low]
			return; 
		}
		int mid = (low + hi)/2;  //split 
		construct_Tree(arrs, low, mid, 2*pos+1); //left subtree, should be min[low, mid]; 
		construct_Tree(arrs, mid+1, hi, 2*pos+2); //right subtree, should be min[mid+1, hi]; 
		segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);  //min is for the R-(Minimum)-Query, gives min[low, hi]; 
	}

	SegTree(int arrs[], int len){ //constructor 
		int maxLen = 1; 
		segLen = len; 
		while (maxLen < len) maxLen <<= 1;  //finds smallest power of 2 greater than or equal to len. 
		segTree = new int[2*maxLen-1]; 
		memset(segTree, 63, sizeof(int)*(2*maxLen-1)); //initialize to big numbas
		construct_Tree(arrs, 0, len-1, 0); 
	}	

	/** Calculate based on (1) partial overlap, (2) total overlap, (3) no overlap. **/ 
	int RangeMinimumQuery(int qlow, int qhi, int low, int hi, int pos){
		if (qlow <= low && qhi >= hi) { //total overlap
			return segTree[pos]; 
		}
		if (qlow > hi || qhi < low) { //no overlap
			return INF;  
		}
		int mid = (hi + low)/2; 
		return min(RangeMinimumQuery(qlow, qhi, low, mid, 2*pos+1), 
					RangeMinimumQuery(qlow, qhi, mid+1, hi, 2*pos+2)); //min of both left and right ranges 
	}

	int RMQ(int qlow, int qhi){ //gives the minimum from the range [qlow, qhi]; 
		return RangeMinimumQuery(qlow, qhi, 0, segLen-1, 0); 
	}
}; 

int main() {
	int arr[17] = {-1, 2, 3, 0, -4, 7, 5, 2, 0, 3, -10, 4, -5, -3, 8, 3, 2}; 
	SegTree SGT(arr, 17); 
	cout << SGT.RMQ(1, 3) << endl;  // 0
	cout << SGT.RMQ(2, 8) << " " << SGT.RMQ(10, 16) << " " << SGT.RMQ(11, 13) << " " << SGT.RMQ(0, 16)<< endl;  //-4 -10 -5 -10 
}