#include "list.h"

/*
 * @brief: Default constructor for the list class 
 * @param: Pointer of the type Node, if not given nullptr passed by default. Use this to set this list to some already
 * existing list
 * @return: None
 *
*/
List::List()
{
	mpHead = nullptr;
	mpTail = nullptr;
}

/*
 * @brief: Destructor for the class list. Deletes all the nodes in the list 
 * @param: None
 * @return: None
 *
*/
List::~List()
{
	while(mpHead != nullptr)
	{
		Node * toDel = mpHead;
		mpHead = mpHead->getNextPtr();

		delete(toDel);
		cout << "Deleting node !" << endl;
	}
}

/*
 * @brief: Copy constructor for the class list
 * TODO: Implementation remaining
*/
List::List(List const & refList)
{
	// Copy one linked list to another using deep copy //
	Node * copyHead = refList.getHeadPtr();

	while(copyHead != nullptr)
	{
		this->insertAtFront(copyHead->getData());	
		copyHead = copyHead->getNextPtr();
	}
}

/*
 * @brief: 	Overloaded assignment operator for the list class 
 * @param: 	Reference to a list object
 * @return: 	Reference to a list object
*/
List & List::operator=(List const & rhs)
{
	// Deep copy //
	Node * tempNode = rhs.getHeadPtr();

	while(tempNode != nullptr)
	{
		this->insertAtFront(tempNode->getData());
		tempNode = tempNode->getNextPtr();
	}

	return (*this);
}

/*
 * @brief: Insert a new node with the given data at the front of the list 
 * @param: Data of type Int
 * @return: True for successful insertion else false
*/
bool List::insertAtFront(int newData)
{
	bool success = false;

	// create a node dynamically with the newData//
	Node * newNode = makeNode(newData);
	
	if(newNode != nullptr)
	{
		// add the new node to the list //
		newNode->setNextPtr(mpHead);
		if(mpHead == nullptr)
		{
			// this means no nodes in the list //
			mpTail = newNode; 	// tail nodes also point at this node //
		}
		else
		{
			mpHead->setPrevPtr(newNode);
		}

		mpHead = newNode;
		success = true;
	}

	return success;

}

/*
 * @brief: 	Insert a node in the back of the list 
 * @param: 	Data value, an integer
 * @return: 	True for successful insertion else false
*/
bool List::insertAtBack(int newData)
{
	bool success = false;

	// create a new node //
	Node * newNode = makeNode(newData);

	if(newNode)
	{
		// add the new node in the list //
		newNode->setPrevPtr(mpTail);

		if(mpTail == nullptr)
		{
			// if the list is empty //
			mpHead = newNode; 	// head node also point at this node //
		}
		else
		{
			mpTail->setNextPtr(newNode);
		}

		mpTail = newNode;
		success = true;
	}

	return success;
}


/* 
 * @brief: Make a new node dynamically and with the specified data value 
 * @param: Data of type Int
 * @return: Pointer to a Node
*/
Node * List::makeNode(int data)
{
	Node *pt = new Node(data);
	return pt;
}

/*
 * @brief: Print the list from head to tail
 * @param: None
 * @return: None
*/
void List::printListFromFront() const
{
	Node * tpNode = mpHead;

	while(tpNode != nullptr)
	{
		cout << tpNode->getData() << "\t";
		tpNode = tpNode->getNextPtr();
	}

	cout << endl;
}

/*
 * @brief: Print the list from tail to head 
 * @param: None
 * @return: None
*/
void List::printListFromBack() const
{
	Node * tpNode = mpTail;

	while(tpNode != nullptr)
	{
		cout << tpNode->getData() << "\t";
		tpNode = tpNode->getPrevPtr();
	}
	
	cout << endl;
}


/*
 * @brief: Delete a node at the front
 * @param: None
 * @return: True if successful else false 
 *
*/
bool List::deleteAtFront()
{
	bool success = false;

	if(mpHead != nullptr)
	{
		// If the head pointer not null, set it to the next node in the list //
		Node * nodeToDel = mpHead;

		mpHead = mpHead->getNextPtr();
		mpHead->setPrevPtr(nodeToDel->getPrevPtr());

		if(nodeToDel == mpTail)
		{
			// if the node to be deleted is the last node in the list //
			// set the tail pointer to null /
			mpTail = nullptr;
		}

		delete(nodeToDel);
		success = true;
	}

	return success;
}


/*
 * @brief: Delete a node at the back 
 * @param: None
 * @return: True if successful else false 
 *
*/
bool List::deleteAtBack()
{
	bool success = false;

	if(mpTail != nullptr)
	{
		// If the tail pointer not null, set it to the previous node in the list //
		Node * nodeToDel = mpTail;

		mpTail = mpTail->getPrevPtr();
		mpTail->setNextPtr(nodeToDel->getNextPtr());

		if(nodeToDel == mpHead)
		{
			// if the node to be deleted is the last node in the list //
			// set the head pointer to null /
			mpHead = nullptr;
		}

		delete(nodeToDel);
		success = true;
	}

	return success;
}


/*
 * @brief: Search for a node in the list with respect to the node value
 * @param: Int data value to search for 
 * @return: True is there is a node with given value in the list else false
 *
*/
bool List::search(int toSearch)
{
	bool success = false;
	Node * tempNode = mpHead;

	while(tempNode != nullptr)
	{
		if(tempNode->getData() == toSearch)
		{
			success = true;
			break;
		}

		tempNode = tempNode->getNextPtr();
	}
	
	return success;
}

/*
 * @brief: Delete a node that has the specified data
 * @param: Int data to search for in the list 
 * @return: True if found the node with the specified data else false
 *
*/
bool List::deleteNode(int toDelete)
{
	bool success = false;
	Node * tempNode = searchNode(toDelete);

	if(tempNode != nullptr)
	{
		Node * tmpPrev = tempNode->getPrevPtr();
		Node * tmpNext = tempNode->getNextPtr();

		// Consider the cases when the node to delete is 
		// 1. the head node
		// 2. the tail node
		// 3. not the head or tail node 

		if(tmpPrev != nullptr)
		{
			tmpPrev->setNextPtr(tmpNext);
		}
		else
		{
			mpHead = mpHead->getNextPtr();
		}

		if(tmpNext != nullptr)
		{
			tmpNext->setPrevPtr(tmpPrev);
		}
		else
		{
			mpTail = mpTail->getPrevPtr();
		}

		delete(tempNode);
	}
}

/*
 * @brief: Search for node that contain the specified data, if found return the node else return nullptr
 * @param: Int data to search for in the list 
 * @return: Pointer to a Node
 *
*/
Node * List::searchNode(int toSearch)
{
	Node * tempNode = mpHead;
	Node * retNode = nullptr;

	while(tempNode != nullptr)
	{
		if(tempNode->getData() == toSearch)
		{
			retNode = tempNode;
			break;
		}

		tempNode = tempNode->getNextPtr();
	}
	
	return retNode;
}

/*
 * @brief: 	Get the data value of the head node
 * @param: 	None
 * @return: 	Integer value, if head node is null returns a negative value
*/
int List::getHeadNodeValue() const
{
	int retVal = -1;

	if(mpHead != nullptr)
	{
		retVal = mpHead->getData();
	}

	return retVal;
}

/*
 * @brief: 	Get the data value of the tail node 
 * @param: 	None
 * @return: 	Integer value, if the tail node is null returns a negative value
*/
int List::getTailNodeValue() const
{
	int retVal = -1;
	
	if(mpTail != nullptr)
	{
		retVal = mpTail->getData();
	}

	return retVal;
}

/*
 * @brief: 	Get the head pointer of the list 
 * @param: 	None
 * @return: 	Pointer to an object of class Node
*/
Node * List::getHeadPtr() const
{
	return mpHead;
}

