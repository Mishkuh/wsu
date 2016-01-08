#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct file_stats
{
	int amt_chars;
	int amt_lines;
	int amt_longestline;
	int amt_words;
}File_Stats;

int determine_number_of_files(void);
void get_file(char filename[], int file_number);
int get_word_amount(FILE *input, char const *filename);