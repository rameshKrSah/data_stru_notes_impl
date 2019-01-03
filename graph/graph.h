#include <iostream>
#include <vector>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


class Graph
{
	private:
		// Adjacency list representation //
		vector <std::pair <int, int> > * mpAdj;
		unsigned int mVertices;
		unsigned int mEdges;
		bool mIsWeighted;

	public:
		// Functions //
		Graph(unsigned int V = 0, unsigned int E = 0, bool isWeighted = false);

		~Graph();

		Graph(Graph const & copyGraph);

		void setVertices(unsigned int V);

		void setEdges(unsigned int E);

		unsigned int getVertices() const;

		unsigned int getEdges() const;

		void buildGraph(vector <std::pair <int, int> > * pAdj = nullptr);

		void showAdjacencyList() const;

		void breadthFirstSearch(unsigned int sourceNode);

		void addEdge(unsigned int fromNode, unsigned int toNode, int weight = 1);

		void depthFirstSearch(unsigned int sourceNode);

		void Dijkstra(unsigned int sourceNode);

		void topologicalSort();

	private:
		bool createAdjList(void);

		bool deleteAdjList(void);

		void depthFirstSearchStack(unsigned int s, bool visited[], int parent[]);

		void depthFirstSearchRecursive(unsigned int s, bool visited[], int parent[]);

		void topologicalSort(unsigned int vertex, bool visited[], std::stack <int> & Stack);


};




