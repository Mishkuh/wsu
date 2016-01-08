/*
	Michael Wiens
	PA_02
	September 22nd
	Benjamin Cheung 122 sec 4
*/

#include "MyHeader.h"

int main(void)
{
	int selection = 0;
	int running = 1;
	FILE *input = NULL;
	Record *pList = NULL;
	char holder[][20] = {"\0"};
	char word[20] = "\0";

	while(running)
	{
		menu(&selection);

		switch(selection)
		{
			//load
			case 1:
				load(&pList);
				break;
			//store
			case 2:
				store(pList);
				break;
			//display
			case 3:
				display(pList);
				break;
			//insert
			case 4:
				insert(&pList);
				break;
			//delete
			case 5:
				deleteRecord(&pList);
				break;
			//edit
			case 6:
				editRecord(pList);
				break;
			//sort
			case 7:
				sortRecords(&pList);
				break;
			//rate
			case 8:
				rateRecord(&pList);
				break;
			//exit
			case 9:
				running = 0;
				break;
		}
	}
	return 0;
}