#include "MyHeader.h"

/*
	Function: remove_extra
	Date Created: 9/8/14
	Date Last Modified: 9/8/14
	Description: removes unnecessary characters from a string
	Input Parameters: the string to remove chars from
	Output Parameters: none
	Returns: a string that doesnt contain any extra characters
	Preconditions: none
	Postconditions: none
*/
char *remove_extra(char *myString)
{
	char tempString[50] = {"\0"};
	int i = 0, j = 0;

	for(i = 0; i < strlen(myString); i++)
	{
		if(myString[i] >= 65 && myString[i] <= 90 || myString[i] >= 97 && myString[i] <= 122)
		{
			tempString[j] = myString[i];
			j++;
		}
	}

	return tempString;
}

/*
	Function: is_palindrome
	Date Created: 9/8/14
	Date Last Modified: 9/8/14
	Description: checks to see if a string is a palindrome
	Input Parameters: the string to check and the length of the string
	Output Parameters: none
	Returns: one if it is a palindrome and zero if not
	Preconditions: the string must not have any extra characters
	Postconditions: none
*/
int is_palindrome(char *myString, int length)
{
	if (length < 1)
	{
		return 1;
	}
	else if(myString[0] == myString[length-1])
	{
		is_palindrome(myString+1, length-2);
	}
	else
	{
		return 0;
	}
}