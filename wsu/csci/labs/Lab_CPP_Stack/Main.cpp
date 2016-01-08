//#include "Stack.h"
#include "StackNode.h"

int main(void)
{
	Stack myStack;
	
	myStack.push('a');
	
	cout << myStack.peek() << endl;
	
	myStack.push('b');
	myStack.push('c');
	
	cout << myStack << endl;
	
	myStack.pop();
	
	cout << myStack << endl;

	return 0;
}