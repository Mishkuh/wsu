#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <cstring>
#include <string>
#include "Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Bank
{
public:
	Bank();
	~Bank();

	void setBank(Account *newBank);

	Account * getBank() const;

	bool insertAccount();
	//void editAccount();
	void deleteAccount();
	void viewAccount();
	Account * findAccount(int acNumber);

private:
	Account * makeAccount();


	Account * bankHead;
};

#endif