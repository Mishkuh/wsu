#include "MyHeader.h"

int main(void)
{
	int file_number = 0, number_of_files = 0, line = 0, i = 0;
	char filename[25] = {'\0'};
	char char_detect = '\0';
	char word_detect[] = {'\0'};
	FILE *input = NULL;
	File_Stats file_stats[10] = {0,0,0,0};
	File_Stats ftotal_stats = {0,0,0,0};
	
	//allow only ten files
	do
	{
		number_of_files = determine_number_of_files();
		system("cls");
	} while (number_of_files < 0 || number_of_files > 10);
	
	do
	{
		file_number++;
		get_file(filename, file_number);
		input = fopen(filename, "r");

		while(!feof(input))
		{
			line++;
			fscanf(input, "%c", &char_detect);
			//get chars
			file_stats[file_number].amt_chars++;
			//get lines
			if(char_detect == '\n' || line >= 125 )
			{
				file_stats[file_number].amt_lines++;
				//find longest line
				if(line > file_stats[file_number].amt_longestline)
				{file_stats[file_number].amt_longestline = line;}
				line = 0;
			}

			char_detect = '\0';
		}
		fclose(input);

		//get words
		file_stats[file_number].amt_words = get_word_amount(input, filename);

	} while(file_number < number_of_files);


	for( i = 1; i <= number_of_files; i++ )
	{
		//subtract null value offset
		file_stats[i].amt_longestline--;
		file_stats[i].amt_words--;
		//print stats
		printf("Number of chars in file %d: %d\n",i , file_stats[i].amt_chars);
		printf("Number of lines in file %d: %d\n",i , file_stats[i].amt_lines);
		printf("Number of chars in biggest line of file %d: %d\n",i , file_stats[i].amt_longestline);
		printf("Number of words in file %d: %d\n",i , file_stats[i].amt_words);
		putchar('\n');
	}

	//calculate totals
	for(i=0; i <= number_of_files; i++)
	{
		ftotal_stats.amt_chars += file_stats[i].amt_chars;
		ftotal_stats.amt_lines += file_stats[i].amt_lines;
		if(ftotal_stats.amt_longestline < file_stats[i].amt_longestline)
		{
			ftotal_stats.amt_longestline = file_stats[i].amt_longestline;
		}
		ftotal_stats.amt_words += file_stats[i].amt_words;
	}

	printf("Totals: %d chars, %d lines, %d chars in longest line, %d words\n",
		ftotal_stats.amt_chars, ftotal_stats.amt_lines, ftotal_stats.amt_longestline, ftotal_stats.amt_words);

	return 0;
}