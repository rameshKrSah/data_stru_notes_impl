#include "graph.h"
#include <queue>
#include <stack>
#include <cmath>
#include <bits/stdc++.h>
#include <set>

/*
 * @brief: 	Constructor with arguments 
*/
Graph::Graph(unsigned int V, unsigned int E, bool isWeighted)
{
	mpAdj = nullptr;
	setVertices(V);
	setEdges(E);
	mIsWeighted = isWeighted;
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

		mpAdj = new vector <std::pair <int, int> > [this->getVertices()];

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
void Graph::buildGraph(vector <std::pair <int, int> > * pAdj)
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
			int weight = 1;
			
			cout << "From Vertex : ";
			cin >> v1;
			cout << "To Vertex : ";
			cin >> v2;

			if(mIsWeighted)
			{
				cout << "Weight value : ";
				cin >> weight;
			}

			// insert the edge from v1 and v2
			(*(mpAdj + v1)).push_back(std::make_pair(v2, weight));
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
 * brief: 	Add an edge in the graph
 * param: 	To vertex and From vertex.
 * return: 	None
 */
void Graph::addEdge(unsigned int fromNode, unsigned int toNode, int weight)
{
	if(mpAdj == nullptr)
	{
		if(!this->createAdjList())
		{
			cout << "Memory allocation failed " << endl;
			return;
		}
	}


	if((fromNode < mVertices) && (toNode < mVertices))
	{
		for(int i = 0; i < (*(mpAdj + fromNode)).size(); i++)
		{
			if((*(mpAdj + fromNode)).at(i).first == toNode)
			{
				// edge already present in the graph
				return;
			}

		}

		if(mIsWeighted == false)
		{
			weight = 1;
		}

		// the edge is not present in the graph, add it now
		(*(mpAdj + fromNode)).push_back(std::make_pair(toNode, weight));
	}
	else
	{
		cout << "Invalid vertices, cannot add the edge. " << endl;
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

		if(!(*(mpAdj + i)).empty())
		{
			for(int j = 0; j < (*(mpAdj + i)).size() - 1; j++)
			{
				cout << (*(mpAdj + i)).at(j).first << " --> ";
			}

			cout << (*(mpAdj + i)).at((*(mpAdj + i)).size() - 1).first << endl;
		}
	}
}

/*
 * brief: 	Perfrom Breadth first search from the given source node 
 * param: 	Source node, unsigned int
 * return: 	None
 */
void Graph::breadthFirstSearch(unsigned int sourceNode)
{
	if(sourceNode < getVertices())
	{
		// given source node within the vertices in the Graph
		// data structures for keeping track of distance, parent, and visited flag
		int * distance = new int[getVertices()];
		int * parent =  new int[getVertices()];
		bool * visited = new bool[getVertices()];

		// Queue to hold the nodes as they are explored 
		std::queue <int> Q;

		// default values for all the nodes
		for(int i = 0; i < getVertices(); i++)
		{
			distance[i] = int(std::nan("o"));
			parent[i] = int(std::nan("i"));
			visited[i]= false;
		}

		// set the values for the source node 
		distance[sourceNode] = 0;
		visited[sourceNode] = true;

		// push the source node in the queue
		Q.push(sourceNode);

		// the traversal
		while(!Q.empty())
		{
			unsigned int u = Q.front();
			Q.pop();

			cout << u << "  ";

			vector <std::pair <int, int> > * Adj = (mpAdj + u);

			for(int i = 0; i < (*Adj).size(); i++)
			{
				unsigned int w = (*Adj).at(i).first;

				if(visited[w] == false)
				{
					visited[w] = true;
					parent[w] = u;
					distance[w] = distance[u] + 1;
					Q.push(w);
				}
			}
		}


		delete distance;
		delete parent;
		delete visited;

	}
	else
	{
		cout << "BFS : Invalid source vertex." << endl;
	}
}

/*
 * brief: 	Depth first search using stack 
 * param: 	Source node, visited array, and parent array
 * return: 	None
 */
void Graph::depthFirstSearchStack(unsigned int s, bool visited[], int parent[])
{

	// empty stack
	std::stack <int> S;
	
	visited[s] = true;
	S.push(s);

	while(!S.empty())
	{
		unsigned int u = S.top();
		S.pop();

		cout << u << "  ";
		vector <std::pair <int, int> > * adj = (mpAdj + u);

		for(int i = 0; i < (*adj).size(); i++)
		{
			unsigned int w = (*adj).at(i).first;
			if(visited[w] == false)
			{
				S.push(u);
				visited[w] = true;
				parent[w] = u;
				S.push(w);
			}
		}
	}

}

/*
 * brief: 	Depth first search recusive approach
 * param: 	Source node, visited array, and parent array
 * return: 	None
 */
void Graph::depthFirstSearchRecursive(unsigned int s, bool visited[], int parent[])
{
	visited[s] = true;
	cout << s << "  ";

	vector <std::pair <int, int> > * u = (mpAdj + s);

	for(int i = 0; i < (*u).size(); i++)
	{
		unsigned int w = (*u).at(i).first;

		if(visited[w] == false)
		{
			parent[w] = s;
			depthFirstSearchRecursive(w, visited, parent);
		}
	}
}

/*
 * brief: 	Depth Search from the given source node
 * param: 	Source node, unsigned int
 * return: 	None
 */
void Graph::depthFirstSearch(unsigned int sourceNode)
{
	if(sourceNode < getVertices())
	{
		// given source node within the vertices in the Graph
		// data structures for keeping track of parent, and visited flag
		int * parent =  new int[getVertices()];
		bool * visited = new bool[getVertices()];


		// default values for all the nodes
		for(int i = 0; i < getVertices(); i++)
		{
			parent[i] = int(std::nan("i"));
			visited[i]= false;
		}

		// call either the recursive or the stack function for DFS
		depthFirstSearchRecursive(sourceNode, visited, parent);

		/*
		for(int i = 0; i < getVertices(); i++)
		{
			if(visited[i] == false)
			{
				depthFirstSearchRecursive(i, visited, parent);
			}
		}
		*/

		delete parent;
		delete visited;

	}
	else
	{
		cout << "DFS : Invalid source vertex" << endl;
	}
}

/*
 * brief: 	Run topological sort
 * param: 	Vertex, visited boolean array, and a Stack 
 * return: 	None
 */
void Graph::topologicalSort(unsigned int vertex, bool visited[], std::stack<int> & Stack)
{
	visited[vertex] = true;

	vector <std::pair <int, int> > * u = (mpAdj + vertex);

	for(int i = 0; i < (*u).size(); i++)
	{
		unsigned int w = (*u).at(i).first;

		if(visited[w] == false)
		{
			topologicalSort(w, visited, Stack);
		}
	}


	// finally push the vertex to the stack
	Stack.push(vertex);
}


/*
 * brief: 	Topological sort of the given graph
 * param: 	None
 * Return: 	None
 */
void Graph::topologicalSort()
{
	if(mpAdj != nullptr)
	{
		// A valid graph present 
		
		bool * visited = new bool[getVertices()];

		// default values
		for(int i = 0; i < getVertices(); i++)
		{
			visited[i] = false;
		}


		// stack to hold tht topological ordering
		std::stack <int> Stack;

		// run the topological sort
		for(unsigned int i = 0; i < getVertices(); i++)
		{
			if(visited[i] == false)
			{
				topologicalSort(i, visited, Stack);
			}
		}

		// show the ordering
		while(!Stack.empty())
		{
			cout << Stack.top() << "  ";
			Stack.pop();
		}

		cout << endl;

	}
	else
	{
		cout << "Topological sort : Invalid graph " << endl;
	}
}



/*
 * brief: 	Run single source shortest path algorithm i.e., Dijkstra's Algorithm from the given source node 
 * param: 	Source node, unsigned int
 * return: 	None
 */
void Graph::Dijkstra(unsigned int sourceNode)
{
	if(sourceNode < getVertices())
	{
		// given source node within the vertices in the Graph
		// data structures for keeping track of distance, parent
		int * distance = new int[getVertices()];
		int * parent =  new int[getVertices()];

		// Multiset to do the job of min-priority queue 
		std::multiset<std::pair <int, int> > Q;

		// default values for all the nodes
		for(int i = 0; i < getVertices(); i++)
		{
			distance[i] = 999999999; 
			parent[i] = 999999999; 
		}

		// set the values for the source node 
		distance[sourceNode] = 0;

		// push the source node in the queue
		Q.insert(std::make_pair(sourceNode, 0));

		// the traversal
		while(!Q.empty())
		{
			std::pair<int, int> p = *Q.begin();

			Q.erase(Q.begin());

			unsigned int node = p.first;
			vector <std::pair <int, int> > * Adj = (mpAdj + node);

			for(int i = 0; i < (*Adj).size(); i++)
			{
				unsigned int u = (*Adj).at(i).first;
				int weight = (*Adj).at(i).second;

				int temp = distance[node] + weight;

				if(temp < distance[u])
				{
					parent[u] = node;
					distance[u] = temp;
					Q.insert(std::make_pair(u, temp));
				}
			}
		}

		// show the shortest paths from source to all nodes 
		for(int i = getVertices() - 1; i > 0; i--)
		{
			int v = i;
			
			// Stack to hold the node sequences 
			std::stack <int> Q;

			if(parent[v] != 999999999) 
			{
				while(v != 999999999) 
				{

					Q.push(v);
					v = parent[v];
				}
			}

			cout << "Shortest path from node " << sourceNode << " to node " << i << endl; 
			while(!Q.empty())
			{
				cout << Q.top() << " ---> ";
				Q.pop();
			}
			cout << endl;

		}

		delete distance;
		delete parent;
	}
	else
	{
		cout << "Dijkstra : Invalid source vertex." << endl;
	}
}






















































