#ifndef BASECIPHER_H
#define BASECIPHER_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//Base cipher class to be derived from
class BaseCipher
{
public:
	BaseCipher();
	BaseCipher(string newClear, string newEncrypted);

	//getters
	string getClear();
	string getEncrypted();

	//setters
	void setClear(string newClear);
	void setEncrypted(string newEncrypted);

	~BaseCipher();

protected:
	//unencrypted message
	string clearText;
	//encrypted message
	string encrypted;
};

#endif