#include <iostream>
#include <string>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

class List
{
	private:
		Node * mpHead;
		Node * makeNode(int data);
	
	public:
		// Default constructor //
		List(Node * node = nullptr);

		// Default destructor //
		~List();

		// Copy constructor //
		List(List const & refList);

		// Delete node at the front//
		bool deleteAtFront();

		// Delete node at the back //
		bool deleteAtBack();

		// Find and delete the node with the given data value //
		bool deleteNode(int toDel);

		// Insert node at the front //
		bool insertAtFront(int newData);

		// Insert node at back //
		bool insetAtBack(int newData);

		// search for a node //
		bool search(int toSearch);

};

