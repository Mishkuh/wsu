#ifndef BASECIPHER_H
#define BASECIPHER_H

#include <iostream>
#include <string>

using std::string;

class BaseCipher
{
public:
	BaseCipher();
	BaseCipher(string newClear, string newEncrypted);
	~BaseCipher();

protected:
	string clearText;
	string encrypted;
};

#endif