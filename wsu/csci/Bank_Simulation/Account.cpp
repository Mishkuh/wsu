#include "Account.h"

//default constructor
Account::Account()
{
	accountBalance = 0.0;
	accountNumber = 0;
	customerName = "new customer";
	dateOpened = "October 9th, 2014";
	aNext = NULL;
}
//constructor with values
Account::Account(double newBalance, int newAccntNumber, string newName, string curDate)
{
	accountBalance = newBalance;
	if(accountBalance < 0)
	{
		cout << "Can't have negative number. \nBalance set to $0.0" << endl;
	}
	accountNumber = newAccntNumber;
	customerName = newName;
	dateOpened = curDate;

	aNext = NULL;
}
//default destructor
Account::~Account(){}

//deposits money into account
void Account::credit()
{
	double creditAmount = 0.0;

	// if current account exists then deposit
	if(this != NULL)
	{
		cout << "Amount to deposit: " << endl;
		cin >> creditAmount;
		accountBalance += creditAmount;
	}
}
//withdraws money from an account
void Account::debit()
{
	double debitAmount = 0.0;

	//if account exists then deposit
	if(this != NULL)
	{
		cout << "Amount to withdraw: " << endl;
		cin >> debitAmount;

		if(debitAmount > accountBalance)
		{
			cout << "Insufficient funds. Current Balance: $" << accountBalance << endl;
			system("pause");
		}
		else
		{
			accountBalance -= debitAmount;
		}
	}
}
//prints account info
void Account::printAccountInfo()
{
	cout << "Hello " << customerName << ", here is your account info" << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << accountBalance << endl;
	cout << "Date Opened: " << dateOpened << endl;
}

//getters
double Account::getBalance()
{   return accountBalance;   }
int Account::getAccntNumber()
{  return accountNumber;   }
string Account::getName()
{   return customerName;   }
string Account::getDate()
{   return dateOpened;   }
Account *Account::getNext()
{  return aNext;  }

//setters
void Account::setBalance(double newBalance)
{  accountBalance = newBalance;  }
void Account::setAccntNumber(int newNumber)
{  accountNumber = newNumber;  }
void Account::setName(string newName)
{  customerName = newName;  }
void Account::setDate(string newDate)
{  dateOpened = newDate;  }
void Account::setNext(Account *newNext)
{  aNext = newNext;  }