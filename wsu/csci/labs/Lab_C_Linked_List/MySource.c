#include "MyHeader.h"

int main(void)
{
	int selection = 0;

	Node *pList = NULL;
	Contact *newPerson = NULL;

	newPerson = make_contact();
	user_menu(&selection);
	pList = make_node(newPerson);

	return 0;
}