#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Node
{
	private:
		int mData;
		Node *mpNext;
	
	public:
		// Default constructor//
		Node(int newData = 0);

		// Default Destructor //
		~Node();

		// Copy constructor //
		Node(Node const & refNode);

		// Getters ///
		int getData() const;

		Node * getNextPtr() const;

		// Setters //
		void setData(int newData);

		void setNextPtr(Node * newNext);
};



