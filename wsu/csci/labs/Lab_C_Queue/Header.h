#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	char *data;
	struct node *pNext;
}Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
}Queue;

Node *make_node(char *value);
int is_empty(Queue *q);
void enqueue(Queue *q, char *data);
void dequeue(Queue *q, char *word);