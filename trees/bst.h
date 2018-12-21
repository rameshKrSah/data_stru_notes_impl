#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "bstnode.h"
#include "random.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::size_t;

template <class W, class R>
class BST
{
private:
	BSTNode<W, R> * mpRoot;
	
	// overloaded private insert function //
	bool insert(BSTNode<W, R> * & pRoot, W newKey, R const & newValue);

	// overloaded private print function //
	void print(BSTNode<W, R> * pRoot) const;

	// overloaded private search function //
	bool search(BSTNode<W, R> * pRoot, W key, R & value) const;

	// destory the tree by deleting all the node in POST-ORDER //
	void destroy(BSTNode<W, R> * pRoot);

public:
	// Constructor //
	BST(string const & fileName);

	// Default constructor //
	BST();

	// Destructor //
	~BST();

	// Copy Constructor //
	BST(BST const & copyBST);

	// Overloaded assignment operator //
	BST & operator=(BST const & rhs);

	// Insert into the tree //
	bool insert(W newKey, R const & newValue);

	// Serach in the tree //
	bool search(W toFind, R & toCopy) const;

	// Print the tree : Inorder ( LEFT - NODE - RIGHT) //
	void print() const;
};


/*
	@brief:		Default constructor 
	@param:		None
	@return:	None
*/
template <class W, class R>
BST<W, R>::BST()
{
	mpRoot = nullptr;
}

/*
	@brief:		Constructor with the file name argument : used to build the tree if fileName is passed into the constructor argument 
	@param:		Reference to the object of type string
	@return:	None
*/
template <class W, class R>
BST<W, R>::BST(string const & fileName)
{
	mpRoot = nullptr;

	srand((unsigned)time(0));	// Initialise random seed based on current time

	// object for the randombag class
	RandomBag randomBag;

	// Open the file //
	ifstream file(fileName);

	if (file.is_open())
	{
		// there are 39 lines of morse code //
		for (int i = 0; i < 39; i++)
		{
			int randomLine = randomBag.NextValue();
			string line;

			// move to the first character in the file //
			file.seekg(0, file.beg);

			while (randomLine--)
			{
				// keep on moving untill the desired line is reached //
				std::getline(file, line);
			}

			// get the desired line //
			std::getline(file, line);

			// find the position of the key //
			size_t keyPos = line.find_first_of(' ');

			if (keyPos != string::npos)
			{
				// key found //
				W key;

				// extract the key //
				line.copy(&key, 1);

				// extract the value //
				R value = line.substr(keyPos + 1);

				// insert the key and value into the tree //
				if (insert(mpRoot, key, value))
				{
					//cout << "Insert successful for key " << key << endl;
				}
			}
		}

		// close the file now //
		file.close();
	}
	else
	{
		cout << "ERROR : Failed to open the file for Tree construction " << endl;
	}
}

/*
	@brief:		Helper function for the BST destructor
	@param:		Pointer to the object of class BSTNode
	@return:	None
*/
template <class W, class R>
void BST<W, R>::destroy(BSTNode<W, R> * pRoot)
{
	if (pRoot == nullptr)
	{
		return;
	}
	else
	{
		destroy(pRoot->getLeftChild());
		destroy(pRoot->getRightChild());
		delete(pRoot);
	}
}

/*
	@brief:		Default Destructor
*/
template <class W, class R>
BST<W, R>::~BST() 
{
	// Destroy the tree in post order :: LEFT-RIGHT-ROOT
	destroy(mpRoot);
}

/*
	@brief:		Copy constructor for the class BST
	@param:		Reference to the object of class BST
	@return:	None
*/
template<class W, class R>
BST<W, R>::BST(BST<W, R> const & copyBST)
{
	this->mpRoot = copyBST.mpRoot;
}

// Overloaded assignment operator //
template<class W, class R>
BST<W, R> & BST<W, R>::operator=(BST<W, R> const & rhs)
{
	this->mpRoot = rhs.mpRoot;

	return (*this);
}

/*
	@brief:		Insert a node into the tree
	@param:		Key of type W and value of type R
	@return:	Boolean; True if successful else false
*/
template <class W, class R>
bool BST<W, R>::insert(W newKey, R const & newValue)
{
	bool success = false;

	success = insert(mpRoot, newKey, newValue);

	return success;
}

/*
	@brief:		Overloaded insert function 
	@param:		Refernce to Pointer of object of class BSTNode, key and value
	@return:	True if insert successful else false
*/
template <class W, class R>
bool BST<W, R>::insert(BSTNode<W, R> * & pRoot, W newKey, R const & newValue)
{
	bool success = false;

	if (pRoot == nullptr)
	{
		// found the position to insert the node in the tree //
		
		// create a new node //
		BSTNode<W, R> * newNode = new BSTNode<W, R>(newKey, newValue);
		
		// insert it into the tree //
		pRoot = newNode;

		success = true;
	}
	else if (newKey > pRoot->getKey())
	{
		// go to the right sub tree //
		return insert(pRoot->getRightChild(), newKey, newValue);
	}
	else if (newKey < pRoot->getKey())
	{
		// go to the left subtree //
		return insert(pRoot->getLeftChild(), newKey, newValue);
	}
	else
	{
		// Duplicate keys :: Cannot insert duplicate values //
	}

	return success;
}

/*
	@brief:		Print the BST
	@param:		None
	@return:	None
*/
// Print the tree : Inorder ( LEFT - NODE - RIGHT) //
template <class W, class R>
void BST<W, R>::print() const
{
	print(mpRoot);
}

/*
	@brief:		Overloaded private print function to print the BST in order
	@param:		Pointer to the root node
	@return:	None
*/
template <class W, class R>
void BST<W, R>::print(BSTNode<W, R> * pRoot) const
{
	if (pRoot == nullptr)
	{
		return;
	}
	else
	{
		print(pRoot->getLeftChild());
		cout << pRoot->getKey() << "\t" << pRoot->getValue() << endl;
		print(pRoot->getRightChild());
	}
}

/*
	@brief:		Search for a node in the BST
	@param:		Key of the node to be searched and the container to copy the value
*/
template <class W, class R>
bool BST<W, R>::search(W toFind, R & toCopy) const
{
	return search(mpRoot, toFind, toCopy);
}

/*
	@brief:		Overloaded private search function
	@param:		Pointer to the root, key to look for in the tree and the caontainer to copy the value
	@return:	boolean
*/
template <class W, class R>
bool BST<W, R>::search(BSTNode<W, R> * pRoot, W key, R & value) const
{
	bool success = false;

	if (pRoot == nullptr)
	{
		// do nothing, just return back from here //
	}
	else
	{
		W nodeKey = pRoot->getKey();
		if (nodeKey == key)
		{
			// found the node we are looking for, copy the value //
			value = pRoot->getValue();
			success = true;
		}
		else if (key > nodeKey)
		{
			// go to the right subtree //
			return search(pRoot->getRightChild(), key, value);
		}
		else
		{
			// go to the left subtree //
			return search(pRoot->getLeftChild(), key, value);
		}
	}

	return success;
}