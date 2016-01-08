#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bstnode
{
	char c;
	char line[10];
	struct bstnode *pRight;
	struct bstnode *pLeft;
}BSTnode;

void insert(BSTnode **pRoot, char cur, char *line);
BSTnode *makeNode(char *morse, char c);
void inOrder(BSTnode *pRoot);
void insertInTree(BSTnode **pRoot, int size , char *line[], char *c);