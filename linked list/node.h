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
		Node * mpNext;
		Node * mpPrev;
	
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

		Node * getPrevPtr() const;

		// Setters //
		void setData(int newData);

		void setNextPtr(Node * newNext);

		void setPrevPtr(Node * newPrev);
};



