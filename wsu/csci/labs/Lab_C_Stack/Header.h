#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct stackNode
{
	double data;
	struct stackNode *pNext;
}StackNode;

int isEmpty(StackNode *pTop);
StackNode * makeNode(double data);
void push(StackNode **pTop, double data);
double pop(StackNode **pTop);
double peek(StackNode *pTop);