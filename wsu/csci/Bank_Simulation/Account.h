#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Account
{
public:
	Account();
	Account(double accountBalance, int accountNumber, string customerName, string dateOpened);
	~Account();

	void credit();
	void debit();
	void printAccountInfo();
	
	//getters
	double getBalance();
	int getAccntNumber();
	string getName();
	string getDate();
	Account *getNext();

	//setters
	void setBalance(double newBalance);
	void setAccntNumber(int newNumber);
	void setName(string newName);
	void setDate(string newDate);
	void setNext(Account *newNext);

private:
	double accountBalance;
	int accountNumber;
	string customerName;
	string dateOpened;

	Account *aNext;
};

#endif