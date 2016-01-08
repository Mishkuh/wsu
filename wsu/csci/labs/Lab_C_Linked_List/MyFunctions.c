#include "MyHeader.h"

void user_menu(int *selection)
{
	do
	{
		printf("1) Add\n");
		printf("2) Remove\n");
		printf("3) Edit\n");
		printf("4) Print\n");
		printf("5) Store\n");
		printf("6) Load\n");
		printf("Please select one of the above choices: ");
		scanf("%d", selection);
		system("cls");

	}while(*selection < 1 || *selection > 6);
}
Contact *make_contact(void)
{
	Contact *pMem = NULL;
	pMem = (Contact *) malloc (sizeof (Contact));

	if(pMem != NULL)
	{
		read_input(pMem->name, pMem->phone, pMem->email, pMem->title);
	}

}

Node *make_node(Contact *person)
{
	Node *pMem = NULL;
	pMem = (Node *) malloc (sizeof (Node)); // tried to allocate memory

	if (pMem != NULL) // able to allocate memory
	{
		pMem->person = person;
		pMem->next = NULL;
	}

	return pMem;
}
void read_input(char *name, char *phone, char *email, char *title)
{
	printf("Please enter a name: ");
	scanf("%s", name);
	printf("\nPlease enter a phone number: ");
	scanf("%s", phone);
	printf("\nPlease enter an email: ");
	scanf("%s", email);
	printf("\nPlease enter a title: ");
	scanf("%s", title);
}

void initList (Node **pList)
{
	*pList = NULL;
}