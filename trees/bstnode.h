#pragma once

#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class W, class R>
class BSTNode
{
public:
	// constructor that accepts arguments to set the english text character and the Morse code //
	BSTNode(W newKey, R const & newValue);

	// destructor //
	~BSTNode();

	// copy constructor //
	BSTNode(BSTNode<W, R> const & copyNode);

	// overloaded assignment operator with reference //
	BSTNode<W, R> & operator=(BSTNode<W, R> const & rhs);

	// overloaded assignment operator with pointer //
	BSTNode<W, R> * operator=(BSTNode<W, R> const * rhs);

	// setters functions //
	void setRightChild(BSTNode<W, R> * rightChild);

	void setLeftChild(BSTNode<W, R> * leftChild);

	void setKey(W newKey);

	void setValue(R const & newValue);

	// getter functions //
	W getKey() const;

	R getValue() const;

	BSTNode<W, R> * & getRightChild();

	BSTNode<W, R> * & getLeftChild();

private:
	W mKey;		// holds the key for the node in the tree //
	R mValue;	// holds the value for the associated key //

	BSTNode <W, R> * mpLeft;	// left child pointer //
	BSTNode <W, R> * mpRight;	// right child pointer //
};


/*
@brief:		Constructor that sets the english character and the Morse string
@param:		A character and a string
@return:	None
*/
template <class W, class R>
BSTNode<W, R>::BSTNode(W newKey, R const & newValue)
{
	this->mKey = newKey;
	this->mValue = newValue;

	// set the left and right child pointer to null //
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

/*
@brief:		Default destructor
*/
template <class W, class R>
BSTNode<W, R>::~BSTNode() {}

/*
@brief:		Copy constructor
@param:		Reference to object of class BSTNode
@return:	None
*/
template <class W, class R>
BSTNode<W, R>::BSTNode(BSTNode<W, R> const & copyNode)
{
	setKey(copyNode.getKey());
	setValue(copyNode.getValue());

	setRightChild(copyNode.getRightChild());
	setLeftChild(copyNode.getLeftChild());
}

/*
@brief:		Overloaded assignment operator for the class BSTNode
@param:		Reference to object of class BSTNode
@return:	Reference to the object of class BSTNode
*/
template <class W, class R>
BSTNode<W, R> & BSTNode<W, R>::operator=(BSTNode<W, R> const & rhs)
{
	this->setKey(rhs.getKey());
	this->setValue(rhs.getValue());
	this->setRightChild(rhs.getRightChild());
	this->setLeftChild(rhs.getLeftChild());
	
	return (*this);
}

/*
@brief:		Overloaded assignment operator for the class BSTNode
@param:		Pointer to object of class BSTNode
@return:	Pointer to the object of class BSTNode
*/
template <class W, class R>
BSTNode<W, R> * BSTNode<W, R>::operator=(BSTNode<W, R> const * rhs)
{
	this = rhs;
	return (this);
}

// Getter functions //
template <class W, class R>
W BSTNode<W, R>::getKey() const
{
	return mKey;
}

template <class W, class R>
R BSTNode<W, R>::getValue() const
{
	return mValue;
}

template <class W, class R>
BSTNode<W, R> * & BSTNode<W, R>::getRightChild()
{
	return mpRight;
}

template <class W, class R>
BSTNode<W, R> * & BSTNode<W, R>::getLeftChild()
{
	return mpLeft;
}

// Setter functions //
template <class W, class R>
void BSTNode<W, R>::setKey(W newKey)
{
	this->mKey = newKey;
}

template <class W, class R>
void BSTNode<W, R>::setValue(R const & newValue)
{
	this->mValue = newValue;
}

template <class W, class R>
void BSTNode<W, R>::setRightChild(BSTNode<W, R> * rightChild)
{
	this->mpRight = rightChild;
}

template <class W, class R>
void BSTNode<W, R>::setLeftChild(BSTNode<W, R> * leftChild)
{
	this->mpLeft = leftChild;
}
