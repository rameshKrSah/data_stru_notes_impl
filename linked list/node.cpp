#include "node.h"

// Default constructor //
Node::Node(int newData)
{
	mData = newData;
	mpNext = nullptr;
}

// Default destructor //
Node::~Node()
{
}

// Copy constructor //
Node::Node(Node const & refNode)
{
	this->mData = refNode.getData();
	this->mpNext = refNode.getNextPtr();
}

// Getters//
int Node::getData() const
{
	return this->mData;
}

Node * Node::getNextPtr() const
{
	return this->mpNext;
}


// Setters //
void Node::setData(int newData)
{
	mData = newData;
}

void Node::setNextPtr(Node * newNext)
{
	mpNext = newNext;
}


