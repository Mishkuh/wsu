#include "Header.h"

int main(void)
{
	StackNode * pStack1 = NULL;
	StackNode * pStack2 = NULL;
	StackNode * pStack3 = NULL;

	int i = 0;

	push(&pStack1, 3.0);
	push(&pStack1, 2.0);
	push(&pStack1, 1.0);

	push(&pStack3, pop(&pStack1));
	push(&pStack2, pop(&pStack1));
	push(&pStack2, pop(&pStack3));
	push(&pStack1, pop(&pStack3));
	push(&pStack1, pop(&pStack2));
	push(&pStack3, pop(&pStack2));

	return 0;
}