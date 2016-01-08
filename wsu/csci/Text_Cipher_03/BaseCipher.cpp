#include "BaseCipher.h"

//default constructor
BaseCipher::BaseCipher()
{
	clearText = "\0";
	encrypted = "\0";
}

//constructor with input
BaseCipher::BaseCipher(string newClear, string newEncrypted)
{
	clearText = newClear;
	encrypted = newEncrypted;
}

//default destructor
BaseCipher::~BaseCipher()
{}

//getters
string BaseCipher::getClear()
{
	return clearText;
}
string BaseCipher::getEncrypted()
{
	return encrypted;
}

//setters
void BaseCipher::setClear(string newClear)
{
	clearText = newClear;
}
void BaseCipher::setEncrypted(string newEncrypted)
{
	encrypted = newEncrypted;
}