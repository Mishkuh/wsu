#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_length
{
	int min;
	int sec;
}Song_Length;
typedef struct record
{
	struct record *pNext;
	struct record *pPrev;
	char *artist;
	char *album;
	char *song;
	char *genre;
	Song_Length length;
	int plays;
	int rating;

}Record;

void menu(int *selection);
void display(Record *pList);
void printEntireList(Record *pList);
void printSearched(char *search, Record *pList);
void printRecord(Record *curRecord);
void insert(Record **pList);
void deleteRecord(Record **pList);
void editRecord(Record *pList);
void edit(int option, Record *pList);
void sortRecords(Record **pList);
void rateRecord(Record **pList);
Record *userCreate(void);
int isEmpty(Record *pList);
void file_init(FILE *input);
void read_record(FILE *input, char temp[][20]);
Record *make_Record(char *artist, char *album, char *song, char *genre, char *min, char *sec, char *plays, char *rating);
void load(Record **pList);
void store(Record *pList);