#include "Account.h"
#include "Bank.h"
#include "Header.h"

int main(void)
{
	//variables storing info for program
	int option = 0;
	Bank wiensBank;
	bool running = true;

	//while user didn't exit
	while(running)
	{
		//print menu and get option
		bankMenu(&option);

		switch(option)
		{
			case 1:
				//view account info
				wiensBank.viewAccount();
				break;
			case 2:
				//deposit money into account
				wiensBank.findAccount(getAcNumber())->credit();
				break;
			case 3:
				//withdraw money from account
				wiensBank.findAccount(getAcNumber())->debit();
				break;
			case 4:
				//make a new account and put it in the bank
				wiensBank.insertAccount();
				break;
			case 5:
				//delete an account
				wiensBank.deleteAccount();
				break;
			case 6:
				//print exit message and exit
				system("cls");
				cout << "Thank you for visiting WiensBank! Goodbye!" << endl;
				running = false;
				break;
		}
	}

	return 0;
}