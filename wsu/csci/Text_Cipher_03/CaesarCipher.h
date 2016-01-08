#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <iostream>
#include <string>
#include "BaseCipher.h"

using std::string;

//derives from base cipher
class CaesarCipher : public BaseCipher
{
public:
	CaesarCipher();
	CaesarCipher(string newClear, string newEncrypted, int newKey);
	~CaesarCipher();

	//getter
	int getKey();
	//setter
	void setKey(int newKey);

	//encodes whatever message is in clear text field
	void encodeMessage();
	//encodes based on key
	void keyEncode();
	//if no key is provided asks for key then encodes
	void noKeyEncode();

	//decodes whatever message is in encrypted text field
	void decodeMessage();
	//decodes based on key
	void keyDecode();
	//brute force decoder
	void noKeyDecode();

private:
	//value for text to be shifted by
	int key;
};

#endif