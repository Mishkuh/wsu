#include "Header.h"

int isEmpty(StackNode *pTop)
{
	int result = 0;

	if(pTop == NULL)
	{
		result = 1;
	}

	return result;
}

StackNode * makeNode(double data)
{
	StackNode *pMem = NULL;

	pMem = (StackNode*) malloc (sizeof(StackNode));

	if(pMem != NULL)
	{
		pMem->data = data;
		pMem->pNext = NULL;
	}

	return pMem;
}

void push(StackNode **pTop, double data)
{
	StackNode *pMem = NULL;

	pMem = makeNode(data);

	pMem->pNext = *pTop;
	*pTop = pMem;
}

double pop(StackNode **pTop)
{
	StackNode *pTemp = NULL;
	double retdata = 0.0;

	pTemp = *pTop;

	if(*pTop != NULL)
	{
		retdata = pTemp->data;
		*pTop = pTemp->pNext;
		free(pTemp);
	}

	return retdata;
}

double peek(StackNode *pTop)
{
	int retdata = 0.0;

	if(pTop != NULL)
	{
		retdata = pTop->data;
	}

	return retdata;
}

void hanoi (int n, StackNode **A, StackNode **B, StackNode **C)
{
	int i = 0;

	if(n <= 1)
	{

	}
	else
	{
		for(i = n-1; i > 0; i--)
		{
			push(B, pop(A));
		}

	}
}