// 2D-BIT 
#include <iostream>
#include <cstring>

using namespace std;

struct BIT2 { //2D BIT
    int* tree; //array
    int max_x, max_y;  
    int rX, rY; //real x, real y
    
    BIT2() {}; 

    BIT2(int x, int y) { //constructor
        max_x = x+5; 
        rX = x; 
        max_y = y+5; 
        rY = y; 
        tree = new int[(max_x)*(max_y)];  //make initialization easier
        memset(tree, 0, sizeof(int)*(max_x)*(max_y)); 
    }

    void update(int x, int y, int val) {
        int y1; 
        while (x < max_x) {
            y1 = y; 
            while (y1 < max_y) {
                tree[x+y1*max_y] += val; 
                y1 += (y1 & -y1); 
            }
            x += (x & -x); 
        }
    }

    int query(int x, int y) { // sum from (1,1) to (x,y)
        int tot = 0; 
        int y1; 
        while (x > 0) {
            y1 = y; 
            while (y1 > 0) {
                tot += tree[x+y1*max_y]; 
                y1 -= (y1 & -y1); 
            }
            x -= (x & -x); 
        }
        return tot; 
    }

    int query(int x1, int y1, int x2, int y2) { //query [a...b]
        return query(x2, y2) - query(x1-1, y2) - query(x2,y1-1) + query(x1-1, y1-1); 
    }

   void print() {
        for (int i = 1; i < max_x-4; i++){
            for (int j = 1; j < max_y - 4; j++){
                cout << query(i,j,i,j) << " "; 
            }
            cout << endl; 
        }
        cout << endl; 
    }
}; 


int main() {
    BIT2 bit(5,5); 
    for (int i = 1; i < 6; i++){
        bit.update(i,i,i);  
        cout << bit.query(i,i,i,i) << endl; 
    }
    cout << bit.query(2,3) << " " << bit.query(1,1,4,5) << " " 
         << bit.query(2,3,5,5) << endl; 
    bit.print(); 
    return 0; 
}
