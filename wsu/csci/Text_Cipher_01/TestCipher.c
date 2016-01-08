#include "TestCipher.h"

/*
	Function: void test_left_shift(void)
	Date Created: 9/8/14
	Date Last Modified: 9/8/14
	Description: tests the function to shift the cipher left
	Input Parameters: void
	Output Parameters: void
	Returns: void
	Preconditions: none
	Postconditions: none
*/
void test_left_shift(void)
{
	char word[50] = "abcdWxYZ";

	strcpy(word,the_cipher(word, -4));

	printf("%s\n", word);
}
/*
	Function: void test_right_shift(void)
	Date Created: 9/8/14
	Date Last Modified: 9/8/14
	Description: tests if function can shift chipher right
	Input Parameters: void
	Output Parameters: void
	Returns: void
	Preconditions: void
	Postconditions: void
*/
void test_right_shift(void)
{
	char word[50] = "AbCdWxYZ";

	strcpy(word,the_cipher(word, 4));

	printf("%s\n", word);
}