#include "graph.h"



int main()
{
	Graph G;

	unsigned int nodes, edges;

	cout << "Number of Nodes : ";
	cin >> nodes;

	cout << "Number of Edges : ";
	cin >> edges;

	G.setVertices(nodes);
	G.setEdges(edges);

	G.buildGraph();

	G.showAdjacencyList();

	return 0;

}

