#include "Header.h"

Node *make_node(char *value)
{
	Node *pTemp = NULL;
	char *temp = NULL;

	pTemp = (Node *) malloc (sizeof(Node));

	if(pTemp != NULL)
	{
		temp = (char *) malloc (sizeof (char) * strlen(value) + 1);
		pTemp->data = temp;
		strcpy(pTemp->data,value);
		pTemp->pNext = NULL;
	}

	return pTemp;
}
void enqueue(Queue *q, char *data)
{
	Node *pTemp = NULL;
	
	pTemp = make_node(data);

	if(pTemp != NULL)
	{
		if(q->pHead == NULL)
		{
			q->pHead = pTemp;
			q->pTail = pTemp;
		}
		else
		{
			q->pTail->pNext = pTemp;
			q->pTail = pTemp;
		}
	}
}
int is_empty(Queue *q)
{
	int result = 0;

	if(q->pHead == NULL)
	{
		result = 1;
	}

	return result;
}
void dequeue(Queue *q, char *word)
{
	Node *pTemp = NULL;
	
	pTemp = q->pHead;
	q->pHead = q->pHead->pNext;

	strcpy(word,pTemp->data);
	free(pTemp->data);
	free(pTemp);
	pTemp = NULL;

	if(q->pTail == pTemp);
	{
		q->pTail = NULL;
	}
}
