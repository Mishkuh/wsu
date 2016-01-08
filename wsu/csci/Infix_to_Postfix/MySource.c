#include "MyHeader.h"

int main(void)
{
	StackNode *stack1 = {NULL};
	char infix[50] = "\0";
	char postfix[50] = "\0";
	int number = 0;
	int entry = 0;
	initStack(&stack1);

	do
	{
		menu(&entry);

		if(entry == 1)
		{
			system("cls");

			printf("enter an infix expression with single digit numbers\n");
			scanf("%s", infix);

			makePostfix(stack1, infix, postfix);
			printf("\nPost fix expression: %s\n", postfix);
			number = evaluatePostfix(postfix, stack1);
			printf("Result of expression: %d\n", number - '0');
			system("pause");
		}

	}while(entry != 2);

	system("cls");
	printf("Thank you for using this Program!! \n");

	return 0;
}