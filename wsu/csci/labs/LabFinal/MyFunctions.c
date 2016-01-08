#include "MyHeader.h"

int determine_number_of_files(void)
{
	int amount = 0;

	printf("Enter the number of text files to process: ");
	scanf("%d", &amount);

	return amount;
}
void get_file(char filename[], int file_number)
{
	do
	{
		printf("Enter the name of text file %d\n(Do not include \".txt\" extension)\n", file_number);
		scanf("%s", filename);
		strcat(filename, ".txt");
		system("cls");
	}while(fopen(filename, "r") == NULL);

	return;
}
int get_word_amount(FILE *input, char const *filename)
{
	char word_detect[100] = {'\0'};
	int word_amt = 0;

	input = fopen(filename, "r");
	while(!feof(input))
	{
		//count words
		fscanf(input, "%s", word_detect);
		word_amt++;
		//file_stats[file_number].amt_words++;
	}
	fclose(input);

	return word_amt;
}