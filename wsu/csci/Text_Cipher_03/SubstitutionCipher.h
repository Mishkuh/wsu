#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include "BaseCipher.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//inherits from base cipher
class SubstitutionCipher : public BaseCipher
{
public:
	SubstitutionCipher();
	SubstitutionCipher(string newClear, string newEncrypted);
	~SubstitutionCipher();

	void encode();

	void decode();

	string getSubKey();
	string getAlphabet();

private:
	string alphabet;
	string subKey;
	string commonLetters;
	string subLetters;
};

//class to hold text wrappers (real alphabet vs substitution alphabet)
class TextWrap
{
	friend class SubstitutionCipher;

public:
	TextWrap();
	TextWrap(string newSubAlphabet);
	~TextWrap();

	//getters
	string getSubAlpha();
	string getAlphabet();
	string getCommonLetters();

private:
	//holds strings for wrapper
	string alphabet;
	string subAlphabet;
	string commonLetters;
};

#endif