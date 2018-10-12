#include "queueInCpp.h"

int main()
{
	Queue q;

	cout << "Enqueuing now .. " << endl;

	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	cout << "Queue size " << q.getSize() << endl;

	cout << "Dequeuing now ... " << endl;
	while(q.getSize())
	{
		cout << "Element " << q.dequeue() << endl;
		cout << "Queue size " << q.getSize() << endl;
	}

	return 0;
}

