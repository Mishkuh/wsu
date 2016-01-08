#include "CaesarCipher.h"

//default constructor
CaesarCipher::CaesarCipher() : BaseCipher()
{
	key = 0;
}

//constructor with inputs inherits base cipher constructor
CaesarCipher::CaesarCipher(string newClear, string newEncrypted, int newKey) : BaseCipher(newClear, newEncrypted)
{
	clearText = newClear;
	encrypted = newEncrypted;
	key = newKey;
}

//default destructor
CaesarCipher::~CaesarCipher()
{}

//encodes message
void CaesarCipher::encodeMessage()
{
	//if key is provided
	if(key)
	{
		keyEncode();
	}
	//key not provided
	else
	{
		noKeyEncode();
	}
}

//obtain key value
void CaesarCipher::noKeyEncode()
{
	//ask user for key value
	do
	{
		key = 0;
		cout << "Enter a key for encoding: ";
		cin >> key;
	} while(key == 0);

	//use key to encode
	keyEncode();
}

//encode using key
void CaesarCipher::keyEncode()
{
	//variables for the function
	char encoded[100] = "\0";
	int i = 0;

	//encode each letter
	for(i=0 ; i < clearText.length() ; i++)
	{
		//if the character is capital
		if(clearText[i] > 'A' && clearText[i] < 'Z')
		{
			clearText[i] = clearText[i] + 32;
		}

		if(clearText[i] < 'a' || clearText[i] > 'z' )
		{
			encoded[i] = clearText[i];
		}
		//if goes past Z
		else if((clearText[i] + key) > 'z')
		{
			encoded[i] = clearText[i] + key - 26;
		}
		//if goes past A
		else if((clearText[i] + key) < 'a')
		{
			encoded[i] = clearText[i] + key + 26;
		}
		//if key stays within bounds
		else
		{
			encoded[i] = clearText[i] + key;
		}

		//capitalize
		if(clearText[i] > 'a' && clearText[i] < 'z')
		{
			encoded[i] = encoded[i] - 32;
		}
	}
	encrypted = encoded;
}

//decodes
void CaesarCipher::decodeMessage()
{
	//key provided
	if( key != 0 )
	{
		keyDecode();
	}
	//no key
	else
	{
		noKeyDecode();
	}
}

//decode with key
void CaesarCipher::keyDecode()
{
	//variables for the function
	char clear[100] = "\0";
	int i = 0;

	//encode each letter
	for(i=0 ; i < encrypted.length() ; i++)
	{
		//if the character is capital
		if(encrypted[i] > 'A' && encrypted[i] < 'Z')
		{
			clear[i] = encrypted[i] + 32;
		}

		if(clearText[i] < 'a' || clearText[i] > 'z')
		{
			clear[i] = encrypted[i];
		}
		//if goes past Z
		else if((clear[i] - key) < 'a')
		{
			clear[i] = clear[i] - key + 26;
		}
		//if goes past A
		else if((clear[i] - key) > 'z')
		{
			clear[i] = clear[i] - key - 26;
		}
		//if key stays within bounds
		else
		{
			clear[i] = clear[i] - key;
		}
	}
	clearText = clear;
}

//brute force decode
void CaesarCipher::noKeyDecode()
{
	//user entry
	char entry = '\0';

	//shift side to side until user finds desired decoded message
	do
	{
		system("cls");
		cout << clearText << "\n" << endl;
		cout << "Enter '<' to shift left and '>' to shift right" << endl;
		cout << "Once you have your desired message enter 'y':  ";
		cin >> entry;

		//decode using key--
		if (entry == '<')
		{
			this->key -= 1;
			keyDecode();
		}
		//decode using key++
		else if(entry == '>')
		{
			this->key += 1;
			keyDecode();
		}

		//user enters y to escape
	}while ( entry != 'y');
}

//getter
int CaesarCipher::getKey()
{
	return key;
}

void CaesarCipher::setKey(int newKey)
{
	key = newKey;
}