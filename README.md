# usaco-algs
A compilation of some common algorithms/data structures and implementations used in USACO 

# Data Structures: 
  Binary Indexed Tree (BIT.cpp): implemented a structure, solves the Range Sum Query (RSQ) problem in O(log N) time. 
  
  Disjoint-Set Union (disj_set.cpp): implemented with an array, solves the DSU problem in O(log N) (amortized) time for finding components and O(log N) time for union of components. Needs to be updated with an implementation into a structure. 
  
  Segment Tree (segtree.cpp): implemented in a structure, solves the Range Minimum Query (RMQ) problem in O(log N) time. 
  
# Algorithms: 
  Andrew's Algorithm (geometryR.cpp): implemented with a vector, using a cartesian system for computation. Constructs a convex hull for a set of points in O(Nlog N) time. Also contains a few other geometry tricks like ccw, Lines parallel/collinear. 
  
  Dijkstra's Algorithm: three implementations, all three solve the Single Source Shortest Path (SSSP) problem in some fast times. 
  
    O(V^2) implementation with an Adjacency Matrix (dijkstra_nopq_adjmat.cpp): useful for dense graphs (E ~ V^2) 
    
    O(E+V^2) implementation with an Adjacency List (dijkstra_nopq_adjlist.cpp): not really useful 
    
    O((E+V)log V) implemenation with a Priority Queue and Adjacency List (dijkstra_pq2.cpp): fastest usually, best for sparser graphs (E ~ V)
    
  Floyd-Warshall Algorithm (floyd.cpp): implemented with adjacency matrix, solves the All-Pairs Shortest Path (APSP) problem in O(V^3) time.
  
  Kruskal's Algorithm (kruskal.cpp): implemented with Union-Find Data Structure and an edge array, solves the Minimum Spanning Tree problem by greedily adding edges in O(Elog E) time. 
  
  Prim's Algorithm: implemented with either an adjacency matrix or priority queue, solves the Minimum Spanning Tree Problem by greedily adding vertices 
  
    O(V^2) implemenation with an Adjacency Matrix (prim.cpp): useful for dense graphs (E ~ V^2), see FEB15 superbull 
    
    O(Elog E) implementation with an Adjacency list (prim_pq.cpp): useful for basically everything else. 
  
  Rabin-Karp Algorithm: implemented with a typical polynomial rolling hash, solves the substring search problem efficiently with said rolling hash. 
    
    O(n+m) implementation where n is the text length and m is the pattern length 
  
