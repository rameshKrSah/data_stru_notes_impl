#pragma once

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

class Queue
{
	public:
		// Consructor and destructor for the class //
		Queue(){}
		~Queue(){}

		//Enqueue opearation //
		void enqueue(int data);

		// Dequeue operation ///
		int dequeue();

		// Get the size of the queue //
		int getSize();

	private:
		list <int> mData;
};

