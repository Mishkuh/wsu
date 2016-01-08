#include "BaseCipher.h"
#include "CaesarCipher.h"
#include "SubstitutionCipher.h"

int main(void)
{
	CaesarCipher testCaesar("Encode this text", "\0", 0);
	SubstitutionCipher testSub("I see trees of green red roses too I see them bloom for me and you And I think to myself what a wonderful world The colors of the rainbow pretty in the sky the quick brown fox jumps over the lazy dog", "\0");

	//print clear text
	cout << "Clear Text: " << testCaesar.getClear() << endl;

	//encode text
	testCaesar.encodeMessage();

	//print encoded text
	cout << "Encoded Text: " << testCaesar.getEncrypted() << endl;

	//decode text
	testCaesar.decodeMessage();

	//print decoded text
	cout << "Clear Text: " << testCaesar.getClear() << endl;

	system("pause");
	system("cls");

	//encode the message
	testCaesar.encodeMessage();

	//brute force decode
	testCaesar.setKey(0);
	testCaesar.decodeMessage();

	system("pause");
	system("cls");

	//print clear text
	cout << "\nClear Text: " << testSub.getClear() << endl;

	//encode text
	testSub.encode();

	//print encoded text
	cout << "\nEncoded Text: " << testSub.getEncrypted() << endl;

	//decode text
	testSub.decode();

	//print decoded text
	cout << "\nClear Text: " << testSub.getClear() << endl;

	return 0;
}