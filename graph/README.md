# Graph and it's representation

Graph is a data structure that consists of following two components:
- A finite set of vertices called Nodes
- A finite set of ordered (directed) or unordered (undirected) pair of the form (u,v) called an edge. 

A directed graph is a graph in which all the edges are uni-directional. An undirected graph is a graph in which all the 
edges are bi-directional. In a weighted graph, each edge is assigned a weight or cost. A graph is cyclic if the graph 
has one or more cycle. A tree is an undirected acyclic graph and has N - 1 edges, where N is the number of vertices.

### Graph representation
Following are the two most common ways to represent a graph.

1. Adjacency Matrix
2. Adjacency List

There are other representation also like, Incidence Matrix and Incidence List. The choice of the graph representation is 
situation specific and depends on the type of the operations to be performed and ease of use.

#### Adjacency Matrix
For a graph G = (V, E), adjacency matrix A is a 2D binary matrix of size V x V. Element Aij is 1 if there is an edge
from vertex i to vertex j else Aij is 0. The adjacency matrix can also be modified for the weighted graph in which 
instead of storing 0 or 1 in Aij, the weight or cost of the edge is stored.

In an undirected graph if Aij = 1, then Aji = 1. In a directed graph, if Aij = 1, then Aji may or may not be 1.

Adjacency matrix prvides constant time access O(1) to determine if there is an edge or not. Space complexity of the 
adjacency matrix is O(v<sup>2</sup>). 

The adjacency matrix representation consumes more space. If the graph is sparse, it consumes the same space as that for 
a dense graoh. Thus a better representation is needed which takes into account the actual number of edges in the graph.

#### Adjacency List
An adjacency list is an array A of separate list. Each element of the array Ai is a list, which contains all the
vertices that are adjacent (connected) to Ai.

For a weighted graph, the weight or cost of the edge is stored along with the vertex in the list using paris. In an 
undirected graph, if vertex j is in the list Ai, then i will be in the list Aj.

The space complexity of adjacency list is **O(E + V)** because in an adjacency list information is stored only for those
edges that actually exist in the graph.


## Graph Traversal
Graph traversal means visiting every vertex and edge exactly once in a well-defined order. There are two main types of 
traversal, Breadth First Search (BFS) and Depth First Search (DFS).

### Breadth First Search (BFS)
Given a graph G = (V, E) and a source node s, breadth first search systematically explores the edges of G to discover 
vertex that is reachable from s. The algorithm discovers all vertices at distance k from s before discovering any 
vertices at distance k + 1. BFS computes the distance from from s to each reachable nodes and also produces a breadth
first tree with root s. For any vertex v reachable from s, the path in the breadth first tree from s to v corresponds 
to the shortest path from s to v in G.

Here is an approach to BFS:
```
BFS(G, s)
	for all v in V[G] do
		visited[v] = false
		parent[v] = none
		distance[v] = NAN
	end for

	Q := EmptyQueue

	visited[s] = true
	distance[s] = 0

	Enqueue(Q, s)

	while not Empty(Q) do
		u := Dequeue(Q)

		for all w in AdjacencyList[u] do
			if visited[w] == false do
				visited[w] = true
				distance[w] = distance[u] + 1
				parent[w] = u
				Enqueue(Q, w)
			end if
		end for
	end while

```

