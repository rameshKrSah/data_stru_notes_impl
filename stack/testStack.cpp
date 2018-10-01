#include <iostream>
#include "stackInCpp.h"

using std::cout;
using std::endl;

int main()
{
	Stack st;
	
	cout << "Pushing into the stack " << endl;

	st.push(232);

	st.push(122);

	st.push(155);

	st.push(88);

	cout << "Stack size " << st.size() << endl;

	cout << "Poping from the stack " << endl;
	while(st.size())
	{
		cout << "Current item " << st.top() << endl;
		st.pop();
		cout << "Stack size " << st.size() << endl;
	}

	return 0;
}

