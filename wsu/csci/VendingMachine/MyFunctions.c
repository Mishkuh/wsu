#include "MyHeader.h"

void initializeItem(Items *the_item, char *id, char *name, double price, int quantity)
{
	strcpy(the_item->id, id);
	strcpy(the_item->name, name);
	the_item->price = price;
	the_item->quantity = quantity;
}

void take_action(char *action, Items *the_item)
{
	double payment = 0;

	while(the_item->price < payment)
	{

	}
}

void take_input(char *line[])
{
	FILE *input = fopen("test_input.txt", "r");
	int i = 0;

	while (!feof(input))
	{
		fscanf(input, line[i], "%s");
		i++;
	}

}