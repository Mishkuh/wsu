#include "ReversibleStack.h"

ReversibleStack::ReversibleStack()
{
	pTop = NULL;
}

ReversibleStack::~ReversibleStack(){}

void ReversibleStack::push(int newData)
{
	StackNode *newNode = new StackNode(newData);
	newNode->pNext = pTop;
	pTop = newNode;
}

int ReversibleStack::pop()
{
	int data = 0;

	StackNode *deleted = pTop;
	data = pTop->data;
	pTop = pTop->pNext;
	delete deleted;
	deleted = NULL;

	return data;
}

bool ReversibleStack::isEmpty()
{
	bool result = false;
	if (pTop == NULL)
	{
		result = true;
	}

	return result;
}

void ReversibleStack::reverse()
{
	ReversibleStack *reversed = new ReversibleStack;

	while (pTop != NULL)
	{
		reversed->push(this->pop());
	}

	this->pTop = reversed->pTop;
	delete reversed;
}