#include "BaseCipher.h"

BaseCipher::BaseCipher()
{
	clearText = "\0";
	encrypted = "\0";
}

BaseCipher::BaseCipher(string newClear, string newEncrypted)
{
	clearText = newClear;
	encrypted = newEncrypted;
}

BaseCipher::~BaseCipher()
{}