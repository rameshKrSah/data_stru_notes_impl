#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


class Graph
{
	private:
		// Adjacency list representation //
		vector <int> * mpAdj;
		unsigned int mVertices;
		unsigned int mEdges;

	public:
		// Functions //
		Graph(unsigned int V = 0, unsigned int E = 0);

		~Graph();

		Graph(Graph const & copyGraph);

		void setVertices(unsigned int V);

		void setEdges(unsigned int E);

		unsigned int getVertices() const;

		unsigned int getEdges() const;

		void buildGraph(vector <int> * pAdj = nullptr);

		void showAdjacencyList() const;

		void breadthFirstSearch(unsigned int sourceNode);

		void addEdge(unsigned int fromNode, unsigned int toNode);

		void depthFirstSearch(unsigned int sourceNode);

	private:
		bool createAdjList(void);

		bool deleteAdjList(void);

		void depthFirstSearchStack(unsigned int s, bool visited[], int parent[]);

		void depthFirstSearchRecursive(unsigned int s, bool visited[], int parent[]);


};




