// Michael Wiens //
// October 17th 2014//
// Programming assignment 5//
// csci 122 sec 4 Benjamin Cheung//

#include "Bank.h"
#include "Header.h"

//default constructor and destructor
Bank::Bank()
{ bankHead = NULL; } 
Bank::~Bank()
{}

//setter
void Bank::setBank(Account *newBank)
{ bankHead = newBank; }

//getter
Account * Bank::getBank() const
{ return bankHead; }

//makes a new account and inserts it into bank
bool Bank::insertAccount()
{
	bool result = false;
	Account *newAccount = makeAccount();

	system("cls");

	//if able to make new account
	if(newAccount != NULL)
	{
		result = true;
		
		//if bank is not empty put new in front
		if(bankHead != NULL)
		{
			newAccount->setNext(bankHead);
			bankHead = newAccount;
		}
		//bank is empty
		else
		{
			bankHead = newAccount;
		}
	}

	return result;
}

/////////not needed for assignment//////////
//allows you to edit an account
/*void Bank::editAccount()
{
	int acNumber = 0, option = 0;
	Account *pCur = NULL;
	pCur = bankHead;

	system("cls");

	cout << "Please enter your account number: " << endl;
	cin >> acNumber;

	while(pCur != NULL)
	{
		if(pCur->getAccntNumber() == acNumber)
		{
			option = editMenu();
		}
	}
}*/

//makes an account
Account * Bank::makeAccount()
{
	string name, date;
	double balance;
	int acNumber;
	Account * newAccount;

	system("cls");

	cout << "So, you want to open an account at WiensBank?" << endl;
	cout << "First We'll need your name: " << endl;
	cin >> name;
	cout << "Now what would you like your account number to be: " << endl;
	cin >> acNumber;
	cout << "Todays Date(mm/dd/yyyy): " << endl;
	cin >> date;
	cout << "How much money do you want to initally deposit: " << endl;
	cin >> balance;

	//creates new account and sets all it's values
	newAccount = new Account();
	newAccount->setBalance(balance);
	newAccount->setAccntNumber(acNumber);
	newAccount->setDate(date);
	newAccount->setName(name);

	return newAccount;
}

//deletes an account
void Bank::deleteAccount()
{
	int number = 0;
	Account *pCur = NULL;
	Account *pPrev = NULL;

	pCur = bankHead;

	system("cls");

	cout << "What is the account number of the account you want to delete: " << endl;
	cin >> number;

	pCur = findAccount(number);
	//set previous pointer
	while(pPrev->getNext() != pCur)
	{ pPrev = pPrev->getNext(); }

	//account exists
	if(pCur != NULL)
	{
		//if its the only item
		if(pCur->getNext() == NULL)
		{
			delete pCur;
		}
		//front of list
		else if(pPrev != NULL)
		{
			bankHead = pCur->getNext();
			delete pCur;
		}
		//if its somewhere in the middle
		else if(pPrev != NULL)
		{
			pPrev->setNext(pCur->getNext());
			delete pCur;
		}
		//last item
		else
		{
			pPrev->setNext(NULL);
			delete pCur;
		}
	}

	if(pCur == NULL)
	{
		cout << "Sorry, that account doesnt exist" << endl;
		system("pause");
	}
}

//views an accounts info
void Bank::viewAccount()
{
	int number = 0;
	Account *pCur = NULL;

	pCur = bankHead;

	system("cls");

	cout << "What is the account number of the account you want to view: " << endl;
	cin >> number;

	//find the account and print it
	pCur = findAccount(number);
	if(pCur != NULL)
	{
		pCur->printAccountInfo();
		system("pause");
	}
}
//finds the account based on account number
Account * Bank::findAccount(int acNumber)
{
	Account *pTemp = bankHead;

	while(pTemp != NULL)
	{
		if(pTemp->getAccntNumber() == acNumber)
		{
			break;
		}
		else
		{
			pTemp = pTemp->getNext();
		}
	}

	//notifies that account doesnt exist
	if(pTemp == NULL)
	{
		cout << "Sorry, that account doesn't exist" << endl;
		system("pause");
	}

	return pTemp;
}