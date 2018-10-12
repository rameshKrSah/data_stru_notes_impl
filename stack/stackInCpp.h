#pragma once

#include <iostream>
#include <vector>

using std::vector;

class Stack 
{
	public:
		Stack();
		bool push(int data);
		void pop();
		int top();
		int size();

	private:
		vector<int> mData;
};



