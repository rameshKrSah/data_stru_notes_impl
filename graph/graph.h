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


	private:
		bool createAdjList(void);

		bool deleteAdjList(void);

};




