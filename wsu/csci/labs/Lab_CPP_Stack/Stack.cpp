#include "StackNode.h"

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	StackNode *pTemp = top, *pMem = NULL;

	while (pTemp != NULL)
	{
		pMem = pTemp;
		pTemp->setNext(pTemp->getNext());
		delete pMem;
	}
}

void Stack::push(char c)
{
	StackNode *pMem;

	if(top == NULL)
	{
		pMem = new StackNode(c, NULL);
		top = pMem;
	}
	else
	{
		pMem = new StackNode(c, top);
		top = pMem;
	}
}

char Stack::pop()
{
	StackNode *ptemp = new StackNode;
	char c = '\0';

	ptemp = top;

	if(ptemp != NULL)
	{
		c = ptemp->getData();

		top = ptemp->getNext();
		delete ptemp;
	}

	return c;
}

char Stack::peek()
{
	char data = '\0';

	if(top != NULL)
	{
		data = top->getData();
	}

	return data;
}
bool Stack::isEmpty()
{
	bool result = false;

	if(top == NULL)
	{
		result = true;
	}

	return result;
}

ostream& operator<< (ostream& output, const Stack& s)
{
	StackNode *pTemp = new StackNode;

	pTemp = s.top;

	while(pTemp != NULL)
	{
		output << pTemp->getData();
		pTemp = pTemp->getNext();
	}

	return output;
}