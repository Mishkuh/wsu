#include "Header.h"

void insert(BSTnode **pRoot, char cur, char *line)
{
	BSTnode *pMem = NULL;
	BSTnode *pCur = NULL;

	pCur = *pRoot;

	if(*pRoot == NULL)
	{
		pMem = makeNode(line, cur);
		*pRoot = pMem;
	}
	else if(cur > pCur->c)
	{
		insert(&pCur->pRight, cur, line);
	}
	else if(cur < pCur->c)
	{
		insert(&pCur->pLeft, cur, line);
	}
}

BSTnode *makeNode(char *morse, char c)
{
	BSTnode *pMem = NULL;
	char *temp = NULL;

	temp = (char*)malloc(sizeof(strlen(morse) +1));

	morse = temp;

	pMem = (BSTnode *) malloc (sizeof(BSTnode));

	if(pMem != NULL)
	{
		pMem->c = c;
		strcpy(pMem->line, morse);
		pMem->pLeft = NULL;
		pMem->pRight = NULL;
	}

	return pMem;
}

void inOrder(BSTnode *pRoot)
{
	if(pRoot == NULL)
	{
		printf("<");
	}
	else
	{
		printf("  %c  ", pRoot->c);
		inOrder(pRoot->pLeft);
		
		inOrder(pRoot->pRight);

	}
}

void insertInTree(BSTnode **pRoot)
{
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
	insert(pRoot, '5', ".....");
}
