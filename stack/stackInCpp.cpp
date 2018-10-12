// stack implementation using the Vector data structure //
// Pushing and poping from the back, for constant time push and pop with vector //

#include "stackInCpp.h"

// Default constructor //
Stack::Stack(){}

// Push an item into the stack //
bool Stack::push(int data)
{
	mData.push_back(data);
	return true;

}

// Pop an item from the stack //
void Stack::pop()
{
	mData.pop_back();
}

// Get the item from the top of the stack //
int Stack::top()
{
	return mData.back();
}

// get the number of data items in the stack
int Stack::size()
{
	return mData.size();
}

