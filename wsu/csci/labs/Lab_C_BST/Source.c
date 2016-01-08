#include "Header.h"

int main (void)
{
	FILE *input = NULL;
	char trash = '\0';
	char inputname[50] = "\0";
	char curString[100] = "\0";
	BSTnode *pRoot = NULL;
	int lineCount = 0, i = 0;
	char line[100]; 
	char *morse[100];
	char chars[100];

	/*do
	{
		printf("Enter a filename: ");
		scanf("%s", inputname);
	}while(fopen(inputname, "r") == NULL);*/

	input = fopen("morse_alphabet.txt", "r");

	while(!feof(input))
	{
		fscanf(input, "%c", &chars[lineCount]);
		fscanf(input, "%s", curString);
		morse[lineCount] = curString;
		fscanf(input, "%c", &trash);

		lineCount++;
	}

	insertInTree(&pRoot, lineCount, morse, chars);

	inOrder(pRoot);

	return 0;
}