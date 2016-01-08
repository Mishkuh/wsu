#include "TestPalindorme.h"

void test_non_palindrome(void)
{
	char word[50] = "madam i’m adam!";

	int palindrome = 0;

	printf("%s\n", word);

	strcpy(word, remove_extra(word));

	palindrome = is_palindrome(word, strlen(word));

	if(palindrome == 1)
	{
		printf("This is a palindrome!\n");
	}
	else
	{
		printf("This is not a palindrome!\n");
	}
}
void test_palindrome(void)
{
	char word[50] = "sorry madam!";

	int palindrome = 0;

	printf("%s\n", word);

	strcpy(word, remove_extra(word));

	palindrome = is_palindrome(word, strlen(word));

	if(palindrome == 1)
	{
		printf("This is a palindrome!\n");
	}
	else
	{
		printf("This is not a palindrome!\n");
	}
}