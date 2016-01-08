#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact
{
	char *name;
	char *phone;
	char *email;
	char *title;
}Contact;

typedef struct Node
{
	Contact *person;
	struct Node *next;
}Node;

void user_menu(int *selection);
Node *make_node(Contact *person);
void read_input(char *name, char *phone, char *email, char *title);
void initList (Node **pList);
Contact *make_contact(void);