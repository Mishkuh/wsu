#include "MyHeader.h"

/*
	Function: the_cipher
	Date Created: 9/8/14
	Date Last Modified: 9/8/14
	Description: shifts a letter to left or right a number of units
	Input Parameters: char *word-the word that you want to cipher 
					  int shift-the amount of letters you want to shift
	Output Parameters: void
	Returns: char * a string that contains the new ciphered string.
	Preconditions: none
	Postconditions: none
*/
char *the_cipher(char *word, int shift)
{
	char temp[50] = "\0";
	int i = 0;

	for(i = 0; i < strlen(word); i++)
	{
		if(islower(word[i]))
		{
			word[i] = toupper(word[i]);
		}

		if(word[i] + shift > 'Z')
		{
			temp[i] = word[i] + shift - 26;
		}
		else if(word[i] + shift < 'A')
		{
			temp[i] = word[i] + shift + 26;
		}
		else
		{
			temp[i] = word[i] + shift;
		}
	}

	return temp;
}