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
		Node * mpTail;
		Node * makeNode(int data);
		Node * searchNode(int toSearch);
	
	public:
		// Default constructor //
		List();

		// Default destructor //
		~List();

		// Copy constructor //
		List(List const & refList);

		// Overloaded assignment operator //
		List & operator=(List const & rhs);

		// Delete node at the front//
		bool deleteAtFront();

		// Delete node at the back //
		bool deleteAtBack();

		// Find and delete the node with the given data value //
		bool deleteNode(int toDel);

		// Insert node at the front //
		bool insertAtFront(int newData);

		// Insert node at back //
		bool insertAtBack(int newData);

		// search for a node //
		bool search(int toSearch);

		// print the list //
		void printListFromBack() const;

		void printListFromFront() const;

		// Get data of the front and back node //
		int getHeadNodeValue() const;

		int getTailNodeValue() const;

		// Get the head pointer of the list //
		Node * getHeadPtr() const;
};

