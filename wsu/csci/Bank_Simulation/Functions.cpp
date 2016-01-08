#include "Header.h"

//calls bank menu until recieves a valid option
void bankMenu(int *option)
{
	do
	{
		system("cls");
		printMenu();
		cin >> *option;
	}while(*option > 6 || *option < 0);
}
//prints the menu
void printMenu()
{
	cout << "Welcome to Wiens Bank!\n" <<  "What can we help you with today?" << endl;
	cout << "1) View account info" << endl;
	cout << "2) Deposit money" << endl;
	cout << "3) Withdraw money" << endl;
	cout << "4) Create an account" << endl;
	cout << "5) Delete an account" << endl;
	cout << "6) Exit" << endl;
}

//prints edit menu *****not used in assignment*****
/*int editMenu(void)
{
	int option = 0;

	do
	{
		cout << "What would you like to change?" << endl;
		cout << "1) Name" << endl;
		cout << "2) Account Number" << endl;
		cin >> option;
	}while(option < 1 || option > 2);

	return option;
}*/
//gets account number from user
int getAcNumber()
{
	int number = 0;
	cout << "Please enter your account number:" << endl;
	cin >> number;
	return number;
}