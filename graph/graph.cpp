#include "graph.h"

/*
 * @brief: 	Constructor with arguments 
*/
Graph::Graph(unsigned int V, unsigned int E)
{
	mpAdj = nullptr;
	setVertices(V);
	setEdges(E);
	createAdjList();
}


/*
 * brief: 	Default Destructor
*/
Graph::~Graph()
{
	deleteAdjList();
}

/*
 * brief: 	Copy Constructor 
 *
*/
Graph::Graph(Graph const & copyGraph)
{
	deleteAdjList();
	setVertices(copyGraph.getVertices());
	setEdges(copyGraph.getEdges());
	createAdjList();
	buildGraph(copyGraph.mpAdj);
}

/*
 * brief: 	Set number of Vertices
 * param: 	unsigned int 
 * return; 	None
*/
void Graph::setVertices(unsigned int V)
{
	if(!(V < 0))
	{
		mVertices = V;
	}
}

/*
 * brief: 	Set number of edges
 * param: 	unsigned int
 * return: 	None
 */
void Graph::setEdges(unsigned int E)
{
	if(!(E < 0))
	{
		mEdges = E;
	}
}

/*
 * brief: 	Get the number of vertices
 * param: 	None
 * return: 	unsigned int
 */
unsigned int Graph::getVertices() const
{
	return mVertices;
}


/*
 * brief: 	Get the number of edges
 * param: 	None
 * return: 	unsigned int
 */
unsigned int Graph::getEdges() const
{
	return mEdges;
}


/*
 * brief: 	Create adjacency list for the graph
 * param: 	None
 * return: 	Boolean, 1 success 0 failure
 */
bool Graph::createAdjList()
{
	bool success = false;

	if(mVertices != 0)
	{

		if(mpAdj != nullptr)
		{
			deleteAdjList();
		}

		mpAdj = new vector <int> [this->getVertices()];
		cout << "Size of Adjacency list " << (mpAdj)->size() << endl;

		if(mpAdj != nullptr)
		{
			success = true;
		}
	}

	return success;
}

/*
 * brief: 	Delete the adjacency list
 * param: 	None
 * return: 	Boolean, 1 for success 0 for failure
 */
bool Graph::deleteAdjList()
{
	bool success = false;

	if(mpAdj != nullptr)
	{
		delete(mpAdj);
		success = true;
	}

	return success;
}


/*
 * brief: 	Build graph using from the user input
 * param: 	Pointer to the adjacency list if any else nullptr
 * return: 	None
 */
void Graph::buildGraph(vector <int> * pAdj)
{
	if(pAdj == nullptr)
	{
		if(mpAdj == nullptr)
		{
			if(!this->createAdjList())
			{
				cout << "Memory allocation failed " << endl;
				return;
			}
		}

		// graph from scratch
		for(int i = 0; i < getEdges(); i++)
		{
			int v1, v2;
			
			cout << "From Vertex : ";
			cin >> v1;
			cout << "To Vertex : ";
			cin >> v2;

			// insert the edge from v1 and v2
			(*(mpAdj + v1)).push_back(v2);
		}
	}
	else
	{
		// if there is an adjacency list given 
		for(int i = 0; i < (*pAdj).size(); i++)
		{
			for(int j = 0; j < (*(pAdj + i)).size(); j++)
			{
				(*(mpAdj + i)).push_back((*(pAdj + j)).at(j));
			}
		}
	}

}


/*
 * brief: 	Show the adjacency list
 * param: 	None
 * return: 	None
 */
void Graph::showAdjacencyList() const
{
	for(int i = 0; i < getVertices(); i++)
	{
		cout << "Adjacency list of node " << i << " : ";

		for(int j = 0; j < (*(mpAdj + i)).size() - 1; j++)
		{
			cout << (*(mpAdj + i)).at(j) << " --> ";
		}

		cout << (*(mpAdj + i)).at((*(mpAdj + i)).size() - 1) << endl;
	}
}

