#include "MyHeader.h"

//prints a menu and gets a selection from the user
void menu(int *selection)
{
	//ask for a selection while the selection is invalid
	do{
		system("cls");
		*selection = 0;
		printf("Please select a number from the options below:\n");
		printf("1) Load\n");
		printf("2) Store\n");
		printf("3) Display\n");
		printf("4) Insert\n");
		printf("5) Delete\n");
		printf("6) Edit\n");
		printf("7) Sort\n");
		printf("8) Rate\n");
		printf("9) Exit\n");
		scanf("%d", selection);
		system("cls");
	}while(*selection < 1 || *selection > 9);
}

//asks user if they want to display all items or just searched items
void display(Record *pList)
{
	//variables for function
	int option = 0;
	char search[20] = "\0";

	//ask for a selection until a valid selection is given
	do
	{
		printf("Please select a display option:\n");
		printf("1) All Records\n");
		printf("2) Search\n");
		scanf("%d", &option);
		system("cls");
	}while(option < 1 || option > 2);

	switch(option)
	{
	//All Records
	case 1:
		printEntireList(pList);
		break;

	//Search
	case 2:
		printf("Search: ");
		scanf("%s", search);
		printf("\n");
		system("cls");
		printSearched(search, pList);
		break;

	}
}

// prints the searched field items
void printSearched(char *search, Record *pList)
{
	//recursively print searched items
	if(pList == NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("pause");
	}
	else
	{
		if(strcmp(search,pList->artist) == 0 || strcmp(search,pList->album) == 0 || strcmp(search,pList->genre) == 0 || strcmp(search,pList->song) == 0 )//|| atoi(search) == pList->rating)
		{
			printRecord(pList);
		}
		printSearched(search, pList->pNext);
	}
}

// prints the entire library
void printEntireList(Record *pList)
{
	if(pList == NULL)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		system("pause");
	}
	else
	{
		printRecord(pList);
		printEntireList(pList->pNext);
	}
}

//prints all parts of the record
void printRecord(Record *curRecord)
{
	printf("-------------------------------------------\n");
	printf("%s\n", curRecord->artist);
	printf("%s\n", curRecord->album);
	printf("%s\n", curRecord->song);
	printf("%s\n", curRecord->genre);
	printf("%d\n", curRecord->length.min);
	printf("%d\n", curRecord->length.sec);
	printf("%d\n", curRecord->plays);
	printf("%d\n", curRecord->rating);
	//printf("-------------------------------------------\n");
}

//inserts a new record into list
void insert(Record **pList)
{
	Record *pTemp = NULL;
	Record *pCur = NULL;

	pCur = *pList;
	pTemp = userCreate();

	if(!isEmpty(*pList))
	{
		while(strcmp(pCur->artist, pTemp->artist) > 0);
		{
			pCur = pCur->pNext;
		}
		pTemp->pPrev = pCur;
		pTemp->pNext = pCur->pNext;
		pCur->pNext = pTemp;
		pTemp->pNext->pPrev = pTemp;
	}
	else
	{
		*pList = pTemp;
	}
}

//deletes a record based on title
void deleteRecord(Record **pList)
{
	char titleDelete[20] = "\0";
	Record *pCur = NULL;
	Record *pTemp = NULL;

	pCur = *pList;

	system("cls");
	printf("What Song did you want to delete?\n");
	printf("Song Title: ");
	scanf("%s", titleDelete);

	while(strcmp(pCur->song, titleDelete) != 0)
	{
		pCur = pCur->pNext;
	}

	pTemp = pCur;

	if(pCur->pNext != NULL && pCur->pPrev != NULL)
	{
		pCur->pPrev->pNext = pCur->pNext;
		pCur->pNext->pPrev = pCur->pPrev;
	}

	free(pTemp->album);
	free(pTemp->artist);
	free(pTemp->genre);
	free(pTemp->song);
	free(pTemp);
}

//find a record to edit
void editRecord(Record *pList)
{
	char search[20] = "\0";
	int option = 0;
	Record *pCur = pList;

	printf("Search Song Title: ");
	scanf("%s", search);
	printf("\n");
	system("cls");

	while(strcmp(search,pCur->song) != 0)
	{
		pCur = pCur->pNext;
	}

	if(strcmp(search,pCur->artist) == 0 || strcmp(search,pCur->album) == 0 || strcmp(search,pCur->genre) == 0 || strcmp(search,pCur->song) == 0 )
	{
		printf("What would you like to change?\n");
		printf("1) Artist\n");
		printf("2) Album\n");
		printf("3) Genre\n");
		printf("4) Song Title\n");
		scanf("%d", &option);
	}

	edit(option, pCur);
}

//change values of a record
void edit(int option, Record *pCur)
{
	char newData[20] = "\0";

	switch(option)
	{
	case 1:
		printf("Enter new artist name: ");
		scanf("%s", newData);
		strcpy(pCur->artist, newData);
		break;
	case 2:
		printf("Enter new album name: ");
		scanf("%s", newData);
		strcpy(pCur->album, newData);
		break;
	case 3:
		printf("Enter new genre: ");
		scanf("%s", newData);
		strcpy(pCur->genre, newData);
		break;
	case 4:
		printf("Enter new song title: ");
		scanf("%s", newData);
		strcpy(pCur->song, newData);
		break;
	}
}

//sorts records based on song title
void sortRecords(Record **pList)
{
	Record *pCur = *pList, *pTemp = NULL;
	int items = 0, i = 0;

	while(pCur != NULL)
	{
		pCur = pCur->pNext;
		items++;
	}

	pCur = *pList;

	if(*pList != NULL)
	{
		if(pCur->pNext != NULL)
		{
			for(i = 0; i < items -1; i++)
			{
				if(strcmp(pCur->song, pCur->pNext->song) < 0)
				{
					pCur->pNext->pPrev = pCur->pPrev;
					pCur->pPrev = pCur->pNext;
					pCur->pNext->pPrev->pNext = pCur->pNext;
					pCur->pNext = pCur->pNext->pNext;
					pCur->pPrev->pNext = pCur;
				}
			}
		}
		else
		{
			printf("Only one item in library");
		}
	}
}

//rates record
void rateRecord(Record **pList)
{
	char search[20] = "\0";
	int rating = 0;
	Record *pCur = *pList;

	printf("Search Song Title: ");
	scanf("%s", search);
	printf("\n");
	system("cls");

	while(strcmp(search,pCur->song) != 0)
	{
		pCur = pCur->pNext;
	}

	if(strcmp(search,pCur->song) == 0 )
	{
		printf("What would you like to rate this song? (1-5)\n");
		scanf( "%d", &rating);
		pCur->rating = rating;
	}

}

//creates a new record
Record *userCreate(void)
{
	Record *pTemp = NULL;
	char artist[20] = "\0";
	char album[20] = "\0";
	char song[20] = "\0";
	char genre[20] = "\0";
	char min[10] = "\0";
	char sec[10] = "\0";
	char plays[5] = "0";
	char rating[10] = "\0";

	printf("Please enter information about the record\n\n");
	printf("Artist Name: ");
	scanf("%s", artist);
	printf("Album Title: ");
	scanf("%s", album);
	printf("Song Title: ");
	scanf("%s", song);
	printf("Genre: ");
	scanf("%s", genre);
	printf("Song Length \n");
	printf("minutes: ");
	scanf("%s", min);
	printf("seconds: ");
	scanf("%s",sec);
	printf("Rating (1-5):");
	scanf("%d", &rating);

	pTemp = make_Record(artist, album, song, genre, min, sec, plays, rating);

	return pTemp;
}

void file_init(FILE **input)
{
	char fileName[20] = "\0";

	do
	{
		system("cls");
		printf("Please enter the name of the input file: ");
		scanf("%s", fileName);

		*input = fopen(fileName, "r");

	}while(*input == NULL);
}

Record *make_Record(char *artist, char *album, char *song, char *genre, char *min, char *sec, char *plays, char *rating)
{
	Record *pMem = NULL;
	char *pTemp = NULL;
	int dTemp = 0;

	pMem = (Record *) malloc (sizeof(Record));

	if(pMem != NULL)
	{
		pTemp = (char *) malloc (sizeof (char) * strlen(artist));
		pMem->artist = pTemp;
		strcpy(pMem->artist, artist);
		pTemp = (char *) malloc (sizeof (char) * strlen(album));
		pMem->album = pTemp;
		strcpy(pMem->album, album);
		pTemp = (char *) malloc (sizeof (char) * strlen(song));
		pMem->song = pTemp;
		strcpy(pMem->song, song);
		pTemp = (char *) malloc (sizeof (char) * strlen(genre));
		pMem->genre = pTemp;
		strcpy(pMem->genre, genre);

		dTemp = atoi(min);
		pMem->length.min = dTemp;
		dTemp = atoi(sec);
		pMem->length.sec = dTemp;
		dTemp = atoi(plays);
		pMem->plays = dTemp;
		dTemp = atoi(rating);
		pMem->rating = dTemp;

		pMem->pNext = NULL;
		pMem->pPrev = NULL;

	}
}

int isEmpty(Record *pList)
{
	int result = 0;
	if(pList == NULL)
	{
		result = 1;
	}
	return result;
}

void read_record(FILE *input, char temp[][20])
{
	int i = 0;

	for(i = 0; i < 8; i++)
	{
		fgets(temp[i], 20, input);
	}
}

void load(Record **pList)
{
	FILE *input = NULL;
	Record *pMem = NULL;
	Record *pCur = NULL;
	char filename[20] = "\0";
	char artist[20] = "\0";
	char album[20] = "\0";
	char song[20] = "\0";
	char genre[20] = "\0";
	char min[10] = "\0";
	char sec[10] = "\0";
	char plays[5] = "\0";
	char rating[10] = "\0";

	printf("please enter the name of the file you'd like to load from: ");
	scanf("%s", filename);

	input = fopen(filename, "r");

	fscanf(input, "%s", artist);
	fscanf(input, "%s", album);
	fscanf(input, "%s", song);
	fscanf(input, "%s", genre);
	fscanf(input, "%s", &min);
	fscanf(input, "%s", &sec);
	fscanf(input, "%s", &plays);
	fscanf(input, "%s", &rating);

	pMem = make_Record(artist, album, song, genre, min, sec, plays, rating);

	if(!isEmpty(*pList))
	{
		while(strcmp(pCur->artist, pCur->artist) > 0);
		{
			pCur = pCur->pNext;
		}
		pMem->pPrev = pCur;
		pMem->pNext = pCur->pNext;
		pCur->pNext = pMem;
		pMem->pNext->pPrev = pMem;
	}
	else
	{
		*pList = pMem;
	}

	fclose(input);
}

void store(Record *pList)
{
	FILE *output = NULL;
	char filename[20] = "\0";

	printf("please enter the name of the file you'd like to save to: ");
	scanf("%s", filename);

	output = fopen(filename, "w");

	while(pList != NULL)
	{
		fprintf(output, "%s\n", pList->artist);
		fprintf(output, "%s\n", pList->album);
		fprintf(output, "%s\n", pList->song);
		fprintf(output, "%s\n", pList->genre);
		fprintf(output, "%d\n", pList->length.min);
		fprintf(output, "%d\n", pList->length.sec);
		fprintf(output, "%d\n", pList->plays);
		fprintf(output, "%d\n", pList->rating);
		pList = pList->pNext;
	}

	fclose(output);
}