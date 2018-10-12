#include "list.h"

// Default constructor //
List::List(Node * node)
{
	mpHead = node;
}

// Default Destructor //
List::~List()
{
	cout << "In list destructor " << endl;
	
	while(mpHead != nullptr)
	{
		Node * toDel = mpHead;
		mpHead = mpHead->getNextPtr();

		delete(toDel);
		
		cout << "Deleting node !" << endl;
	}

}

// Copy Constructor //
List::List(List const & refList)
{
}

bool List::insertAtFront(int newData)
{
	// create a node dynamically and add the data to it //
	
	Node * newNode = makeNode(newData);

	newNode->setNextPtr(mpHead);
	mpHead = newNode;

	return true;

}

Node * List::makeNode(int data)
{
	Node *pt = new Node(data);

	return pt;
}

