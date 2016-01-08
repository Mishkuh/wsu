#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

typedef struct stackNode
{
	char data;
	struct stackNode *next;
}StackNode;

StackNode *make_node(char data);
void push(StackNode **pStack, char data);
char pop(StackNode **pStack);
char peek(StackNode *pStack);
void initStack(StackNode **pStack);
void makePostfix(StackNode *pStack, char* infix, char *postfix);
int isOperator(char c);
int precedence (char op1, char op2);
void printStack(StackNode *pStack);
int evaluatePostfix(char *postfix, StackNode *pStack);
int calculate(int x, int y, char op);
void menu(int *entry);
