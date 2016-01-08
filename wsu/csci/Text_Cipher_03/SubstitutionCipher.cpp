#include "SubstitutionCipher.h"

//default constructor
SubstitutionCipher::SubstitutionCipher()
{
	TextWrap newSubKey;

	clearText = "\0";
	encrypted = "\0";
	subKey = newSubKey.getSubAlpha();
	subKey.resize(26);

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	commonLetters = "etaoinshrdlcumwfgypbvkjxqz";
}

//constructor with parameters
SubstitutionCipher::SubstitutionCipher(string newClear, string newEncrypted) : BaseCipher(newClear, newEncrypted)
{
	TextWrap newSubKey;

	clearText = newClear;
	encrypted = newEncrypted;
	subKey = newSubKey.getSubAlpha();
	subKey.resize(26);

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	commonLetters = "etaoinshrdlcumwfgypbvkjxqz";
}

//default destructor
SubstitutionCipher::~SubstitutionCipher()
{}

//getters
string SubstitutionCipher::getSubKey()
{
	return subKey;
}
string SubstitutionCipher::getAlphabet()
{
	return alphabet;
}

//encodes based on random substitution
void SubstitutionCipher::encode()
{
	//variables for function
	int i = 0;
	int swapLocation = -1;
	string newEncrypted = "\0";

	//swap letters for substitutes
	for(i = 0 ; i < clearText.size() ; i++)
	{
		//find what letter needs to be swapped in
		swapLocation = alphabet.find_first_of(clearText[i]);
		
		//if the letter is found
		if(swapLocation >= 0)
		{
			//append to new string
			newEncrypted += subKey[swapLocation];
		}
	}

	encrypted = newEncrypted;
}

//decodes message based on frequency
void SubstitutionCipher::decode()
{
	//variables for function
	int counter[26] = {0};
	int i = 0, j = 0, intTemp = 0;
	int found = -1;
	char newSubKey[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string tempKey = newSubKey;
	char newClear[1000] = "\0";
	char charTemp = '\0';

	//count how many times each letter comes up in the string
	for (i=0 ; i<encrypted.size() ; i++)
	{
		//make sure its a capital letter
		if(encrypted[i] < 'z' && encrypted[i] > 'a')
		{
			encrypted[i] = encrypted[i] - 32;
		}

		//increment the counter related to the letter
		found = alphabet.find_first_of(encrypted[i] + 32);
		counter[found]++;
	}

	//bubble sort the letters to get the most frequent in front
	for (i=0 ; i<26 ; i++)
	{
		for (j=0; j<25; j++)
		{
			if(counter[j] <= counter[j+1])
			{
				//based on counter
				intTemp = counter[j];
				counter[j] = counter[j+1];
				counter[j+1] = intTemp;
				//swaps the letter corresponding to counter
				charTemp = newSubKey[j];
				newSubKey[j] = newSubKey[j+1];
				newSubKey[j+1] = charTemp;
			}
		}
		
	}


	//text wrapper for ket becomes the new sub key
	subLetters = newSubKey;

	//swap letters for the letter based on frequency
	for(i=0 ; i<encrypted.size() ; i++)
	{
		found = subLetters.find_first_of(encrypted[i]);
		if(found < 26 && found >= 0)
		{
			newClear[i] = commonLetters[found];
		}
	}

	clearText = newClear;
}

//default constructor
TextWrap::TextWrap()
{
	int i = 0;
	int random = rand() % 26;
	char newSub [27] = "\0";

	srand(time(NULL));

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	commonLetters = "etaoinshrdlcumwfgypbvkjxqz";

	for(i = 0; i< alphabet.length() ; i ++)
	{
		random = rand() % 25;

		while(newSub[random] != '\0')
		{
			random++;
			if(random > 25)
			{
				random = 0;
			}
		}

		newSub[random] = alphabet[i] - 32;
	}

	subAlphabet = newSub;
}

//constructor with arguments
TextWrap::TextWrap(string newSubAlphabet)
{
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	subAlphabet = newSubAlphabet;
	commonLetters = "etaoinshrdlcumwfgypbvkjxqz";
}

//default destructor
TextWrap::~TextWrap()
{

}

//getter
string TextWrap::getSubAlpha()
{
	return subAlphabet;
}