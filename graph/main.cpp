#include "graph.h"



int main()
{
	Graph G;

	unsigned int nodes, edges;

	nodes = 6;
	edges = 10;

	G.setVertices(nodes);
	G.setEdges(edges);

	G.addEdge(0, 1);
	G.addEdge(0, 3);


	G.addEdge(1, 2);
	G.addEdge(1, 3);

	G.addEdge(2, 3);
	G.addEdge(2, 4);
	G.addEdge(2, 5);

	G.addEdge(3, 4);
	G.addEdge(3, 5);

	G.addEdge(4, 5);

	G.showAdjacencyList();
	cout << endl;

	cout << endl << "Breadth first search with source node 0 " << endl;
	G.breadthFirstSearch(0);
	cout << endl;

	cout << "Depth first search with source node 0 " << endl;
	G.depthFirstSearch(0);
	cout << endl;

	cout << "Topological Ordering " << endl;
	G.topologicalSort();
	cout << endl;

	cout << "Dijkstra From Node 0" << endl;
	G.Dijkstra(0);
	cout << endl;

	return 0;

}

