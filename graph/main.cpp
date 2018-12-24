#include "graph.h"



int main()
{
	Graph G;

	unsigned int nodes, edges;

	nodes = 4;
	edges = 6;

	G.setVertices(nodes);
	G.setEdges(edges);

	G.addEdge(0, 1);
	G.addEdge(1, 2);
	G.addEdge(0, 2);
	G.addEdge(2, 0);
	G.addEdge(2, 3);
	G.addEdge(3, 3);

	G.showAdjacencyList();

	cout << "Breadth first search with source node 2 " << endl;
	G.breadthFirstSearch(2);
	cout << endl;


	cout << "Depth first search with source node 2 " << endl;
	G.depthFirstSearch(2);
	cout << endl;


	return 0;

}

