#include "queueInCpp.h"

// Enqueue ooperation : insertion at the back //
void Queue::enqueue(int data)
{
	mData.push_back(data);
}

// Dequeue operation : Deletion from the front //
int Queue::dequeue()
{
	int temp = mData.front();
	mData.pop_front();

	return temp;
}

// Get the seize of the queue //
int Queue::getSize()
{
	return mData.size();
}

