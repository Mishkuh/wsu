/*
	Michael Wiens
	PA_03_2014
	CSCI 122 SEC 4
	Benjamin Cheung
	A program that converts infix to postfix then evaluates the expression
*/

#include "MyHeader.h"

/*
	Function: make_node
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: makes a new node and returns pointer to it
	Input Parameters: the data held by node
	Output Parameters: none
	Returns: pointer to the new node
	Preconditions: none
	Postconditions: none
*/
StackNode *make_node(char data)
{
	StackNode *pTemp = NULL; 

	//allocate memory for a Stacknode pointer
	pTemp = (StackNode*) malloc (sizeof(StackNode));

	//if you were able to allocate memory
	if(pTemp != NULL)
	{
		pTemp->data = data;
		pTemp->next = NULL;
	}

	return pTemp;
}
/*
	Function: push
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: pushes a new node with new data to top of stack
	Input Parameters: pointer to top of stack, and new data
	Output Parameters: none
	Returns: void
	Preconditions: none
	Postconditions: none
*/
void push(StackNode **pStack, char data)
{
	StackNode *pMem = NULL;
	StackNode *pCur = NULL;

	//make a new node and put it on top of the stack
	pMem = make_node(data);
	pMem->next = *pStack;
	*pStack = pMem;
}
/*
	Function: pop
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: takes the data from the top node of a stack
	Input Parameters: top of stack
	Output Parameters: none
	Returns: data help by top node
	Preconditions: stack is not empty
	Postconditions: none
*/
char pop(StackNode **pStack)
{
	//char to hold return data
	char data = '\0';
	StackNode *pTemp = NULL;

	//set temp to top node
	pTemp = *pStack;

	//make sure stacks not empty
	if(*pStack != NULL)
	{
		//set return data to removed nodes data then free node
		*pStack = pTemp->next;
		data = pTemp->data;
		free(pTemp);
	}

	return data;
}
/*
	Function: peek
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: sees the top data in a stack
	Input Parameters: top of the stack
	Output Parameters: none
	Returns: data help by top node
	Preconditions: not empty stack
	Postconditions: none
*/
char peek(StackNode *pStack)
{
	char data = '\0';

	//make sure stack isnt empty
	if(pStack != NULL)
	{
		//set return data to tops data
		data = pStack->data;
	}

	return data;
}
/*
	Function: initStack
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: initializes the stack
	Input Parameters: top of stack
	Output Parameters: none
	Returns: void
	Preconditions: none
	Postconditions: none
*/
void initStack(StackNode **pStack)
{
	//initialize the stack to null
	*pStack = NULL;
}
/*
	Function: makePostFix
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: takes an infix expression and makes it post fix
	Input Parameters: top of the stack, infix string
	Output Parameters: postfix string
	Returns: void
	Preconditions: none
	Postconditions: none
*/
void makePostfix(StackNode *pStack, char* infix, char *postfix)
{
	//make integers to hold number chars
	int i = 0, j = 0;

	push(&pStack, '(');
	strcat(infix, " )");

	//make sure the stack isn't null
	while(pStack != NULL)
	{
		//read through the entire infix string
		for(i = 0; i <strlen(infix); i++)
		{
			//is current char a digit?
			if(isdigit(infix[i]))
			{
				//put it in the postfix string
				postfix[j] = infix[i];
				j++;
			}
			//is current char a left parentheses?
			else if(infix[i] == '(')
			{
				//push the '(' onto the stack
				push(&pStack, infix[i]);
			}
			//is current char an operator?
			else if(isOperator(infix[i]))
			{
				//while the top of the stack is an operator
				while(isOperator(pStack->data))
				{
					//is the current operators precedence greater than or equal to the stack top?
					if(precedence(pStack->data, infix[i]) >= 0)
					{
						//put the top data into the postfix string
						postfix [j] = pop(&pStack);
						j++;
					}
					//if the stack top operator has lower precedence than current then break
					else {break;}
				}
				//push the current operator onto the stack
				push(&pStack, infix[i]);
			}
			//is current char a right parentheses
			else if(infix[i] == ')')
			{
				//pop until the top data is a left parentheses
				while(pStack->data != '(')
				{
					//put popped chars into postfix string
					postfix[j] = pop(&pStack);
					j++;
				}
				//pop the left parentheses
				pop(&pStack);
			}
		}
	}
}
/*
	Function: isOperator
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: determines if a char is an operator
	Input Parameters: char to check
	Output Parameters: none
	Returns: 0 false 1 true
	Preconditions: none
	Postconditions: none
*/
int isOperator(char c)
{
	int result = 0;

	//is the current char an operator?
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
	{result = 1;}

	return result;
}
/*
	Function: precedence
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: determines if op1 has higher precedence than op2
	Input Parameters: operator 1, operator 2
	Output Parameters: none
	Returns: 1 if op1 > op2, 0 if op1=op2, -1 if op1<op2
	Preconditions: none
	Postconditions: none
*/
int precedence (char op1, char op2)
{
	//ints to hold result, precedence one and two
	int result = 0;
	int prec1 = 0;
	int prec2 = 0;

	//is operator1 + or -? make it lowest precedence
	if(op1 == '+' || op1 == '-')
	{prec1 = 1;}
	//is operator1 %, *, or /? make it next lowest precedence
	else if(op1 == '%' || op1 == '*' || op1 == '/')
	{prec1 = 2;}
	//is operator1 ^ ? make it highest precedence
	else if(op1 == '^')
	{prec1 = 3;}

	//do the same for operator 2
	if(op2 == '+' || op2 == '-')
	{prec2 = 1;}
	else if(op2 == '%' || op2 == '*' || op2 == '/')
	{prec2 = 2;}
	else if(op2 == '^')
	{prec2 = 3;}

	//if operator one has higher precedence than op2 return -1
	if(prec1 < prec2)
	{result = -1;}
	//if operator one has lower precedence than op2 return 1
	else if(prec1 > prec2)
	{result = 1;}
	//if operators are equal precedence then return 0
	else{result = 0;}

	return result;
}
/*
	Function: printStack
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: prints the stack recursively
	Input Parameters: top of stack
	Output Parameters: none
	Returns: none
	Preconditions: none
	Postconditions: none
*/
void printStack(StackNode *pStack)
{
	//base care : stack is null
	if(pStack == NULL)
	{printf("-->NULL ");}
	//make a recursive call with the next item in the stack
	else
	{
		printf("-->%c ",pStack->data);
		printStack(pStack->next);
	}
}
/*
	Function: evaluatePostFix
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: evaluates a postfix expression
	Input Parameters: top of stack and postfix string
	Output Parameters: none
	Returns: result of equation
	Preconditions: none
	Postconditions: none
*/
int evaluatePostfix(char *postfix, StackNode *pStack)
{
	// index value , two values , return value
	int i = 0;
	int x = 0, y = 0;
	int result = 0;

	//go through all the characters in the postfix array
	for(i = 0; i < strlen(postfix); i++)
	{
		//is the current char a digit?
		if(isdigit(postfix[i]))
		{
			//push the number on the stack
			push(&pStack, postfix[i]);
		}
		//is the current char an operator?
		else if(isOperator(postfix[i]))
		{
			//pop the top two items off the stack and hold them
			x = pop(&pStack) - '0';
			y = pop(&pStack) - '0';

			//calculate the result of x operator y
			result = calculate(x, y, postfix[i]);

			//push the result onto the stack
			push(&pStack, result + '0');
		}
	}
	//return the remaining number
	result = pop(&pStack);
	return result;
}
/*
	Function: calculate
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: performs desired operation on two numbers
	Input Parameters: number1 x, number2 y, operation op
	Output Parameters: none
	Returns: result of equation x op 2
	Preconditions: none
	Postconditions: none
*/
int calculate(int x, int y, char op)
{
	int result = 0;

	//find what the operator is and perform it on the numbers
	if(op == '-'){result = y - x;}
	else if(op == '+'){result = x + y;}
	else if(op == '/'){result = y / x;}
	else if(op == '*'){result = x * y;}
	else if(op == '%'){result = x % y;}
	else if(op == '^'){result = (int)pow((double)x,y);}

	//return the result of the operation
	return result;
}
/*
	Function: menu
	Date Created: 9/28/14
	Date Last Modified: 9/28/14
	Description: gets an entry from a user
	Input Parameters: none
	Output Parameters: entry
	Returns: void
	Preconditions: none
	Postconditions: none
*/
void menu(int *entry)
{
	//while the user entry isnt valid keep asking
	do
	{
		system("cls");
		printf("Please choose from the following:\n");
		printf("1) Convert and Evaluate infix\n");
		printf("2) Exit\n");
		scanf("%d", entry);
	}while(*entry > 2 || *entry < 1);
}