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
The total time devoted to Queue operation is O(|V|) and since each adjacency list is scanned at most once and the sum 
of the lengths of all adjacency list is O(|E|), the runtime for breadth first search is **O(|V| + |E| ), i.e., BFS 
runs in Linear time**.

### Depth First Search (DFS)
Depth first search (DFS) is a generalization of preorder traversal. Starting at some vertex *s*, we process s and then 
recursively traverse all vertices adjacent to s. When all of s's edges are discovered, the search backtracks to explore
edges leaving the vertex(s) from which s was discovered. The process continues untill we have discovered all the 
vertices that are reachable from s. If any undiscovered vertices remains, then one of them is selected as new source 
and the search is repeated. 

We can use two approach to implement DFS, 1. Using a stack 2. Using recursion 

One thing to note is that even with recursion we are implicitly using a stack, the runtime stack. Given below are the 
two implementation.

```
DFS_STACK(G, s)

	S = EmptyStack
	visited[s] = true
	Push(S, s)

	while not Empty(S) do
		u = Pop(S)
		if there is at least one unvisited vertex in AdjacencyList(u) then
			Pick w to be any unvisited vertex in AdjacencyList(u)
			Push(S, u)
			visited[w] = true
			parent[w] = u
			Push(S, w)
		end if
	end while

```

```
DFS_RECURSIVE(G, s)
	visited[s] = true
	for all w in AdjacencyList(s) do
		if visited[w] == false do
			parent[w] = s
			DFS_RECURSIVE(G, w)
		end if
	end for
```
For both of these appraoch one extra layer can be added to run DFS for all nodes in the Graph.

```
DFS(G)
	for all v in V[G] do
		visited[v] = false
		parent[v] = none
	end for

	for all v in V[G] do
		if visited[v] == false do
			DFS_STACK(G, v) OR DFS_RECURSIVE(G, v)
		end if
	end for
```

The running time of DFS is **O(|V| + |E|)**. Unlike breadth first search whose predecessor subgraph forms a tree, the 
predecessor subgraph of depth first search forms a depth-first forest composed of several depth first trees.

Breadth first search is usually used to find the shortest-path in unweighted graphs. Depth first search is often a 
subroutine in another alogirthms.

A BFS on a binary tree genrally requires more memory than a DFS.

Following are the uses if DFS:
1. For an unweighted graph, DFS traversal of the graph produces the minimum spanning tree and all pair shortest path tree.

2. Detecting cycle in a graph 
A graph has cycle if and only if we see a back edge during DFS. So we can run DFS for the graph and check for back edges. 

3. Path Finding
We can specialize the DFS algorithm to find a path between two given vertices u and z.
	- Call DFS(G, u) with u as the start vertex.
	- Use a stack S to keep track of the path between the start vertex and the current vertex.
	- As soon as destination vertex z is encountered, return the path as the contents of the stack 

4. Topological Sorting
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, 
applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula 
values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data 
serialization, and resolving symbol dependencies in linkers. 

5. To test if a graph is bipartite
We can augment either BFS or DFS when we first discover a new vertex, color it opposited its parents, and for each other 
edge, check it doesn’t link two vertices of the same color. The first vertex in any connected component can be red or black! 

6. Finding Strongly Connected Components of a graph 
A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex. 

