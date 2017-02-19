# usaco-algs
A compilation of some common algorithms/data structures and implementations used in USACO 

# Data Structures: 
  Binary Indexed Tree (BIT.cpp): implemented a structure, solves the Range Sum Query (RSQ) problem in O(log N) time. 
  
  Segment Tree (segtree.cpp): implemented in a structure, solves the Range Minimum Query (RMQ) problem in O(log N) time. 
  
# Algorithms: 
  Andrew's Algorithm (geometryR.cpp): implemented with a vector, using a cartesian system for computation. Constructs a convex hull for a set of points in O(Nlog N) time. Also contains a few other geometry tricks like ccw, Lines parallel/collinear. 
  
  Dijkstra's Algorithm: three implementations, all three solve the Single Source Shortest Path (SSSP) problem in some fast times. 
  
    O(V^2) implementation with an Adjacency Matrix (dijkstra_nopq_adjmat.cpp): useful for dense graphs (E ~ V^2) 
    
    O(E+V^2) implementation with an Adjacency List (dijkstra_nopq_adjlist.cpp): not really useful 
    
    O((E+V)log V) implemenation with a Priority Queue and Adjacency List (dijkstra_pq2.cpp): fastest usually, best for sparser graphs (E ~ V)
  
