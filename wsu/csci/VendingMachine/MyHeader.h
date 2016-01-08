#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct items
{
	char *name;
	char *id;
	int quantity;
	double price;

}Items;
typedef struct change
{
	int changeslot;
	double value;
	int quantity;
}Change;

void initializeItem(Items *the_item, char *id, char *name, double price, int quantity);
void take_input(char *line[]);