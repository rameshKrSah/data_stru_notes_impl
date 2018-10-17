#include "list.h"


int main()
{
	List list;


	list.insertAtFront(22);
	list.insertAtFront(909);
	list.insertAtFront(4343);
	list.insertAtFront(99);
	list.insertAtFront(434);
	list.insertAtFront(323);

	list.printListFromFront();

	cout << "Search for 22 is " << list.search(22) << endl;
	cout << "Search for 23232 is " << list.search(23232) << endl;

	list.deleteNode(22);
	
	list.printListFromFront();

	list.insertAtBack(4344);
	list.insertAtFront(99999);
	list.insertAtBack(101010);
	list.insertAtBack(423282);

	list.deleteNode(99);

	list.printListFromFront();

	list.deleteNode(434);

	list.printListFromFront();
	
	list.deleteAtFront();

	list.printListFromFront();

	list.deleteAtBack();

	list.printListFromBack();

	cout << "head node value " << list.getHeadNodeValue() << endl;

	cout << "tail node value " << list.getTailNodeValue() << endl;

	list.printListFromFront();
	return 0;

}

