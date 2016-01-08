#include "Header.h"

int main (void)
{
	List<int> newList;
	Stack<int> newStack;
	int removed;

	newStack.push(10);
	newStack.push(20);
	newStack.pop(removed);

	cout << removed;

	/*newList.insertAtFront(2);
	newList.insertAtFront(1);
	newList.insertAtFront(0);
	newList.insertAtBack(3);
	newList.insertAtBack(4);

	newList.print();

	int removed = 0;

	newList.removeFromBack(removed);
	newList.removeFromFront(removed);

	newList.print();

	cout << removed << endl;*/

	return 0;
}