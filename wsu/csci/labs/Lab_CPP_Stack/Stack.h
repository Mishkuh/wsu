#include "StackNode.h"
#include <iostream>

class Stack
{
public:
	Stack();
	~Stack();
	void push(char c);
	char pop();
	char peek();
	bool isEmpty();

	friend ostream& operator<< (ostream& output, const Stack& s);

private:
	StackNode *top;
	int size;
};