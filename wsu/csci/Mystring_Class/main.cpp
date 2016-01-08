// Cpt S 223 Homework Assignment - MyString class

// DO NOT MODIFY THIS FILE
// Do your work in the MyString.h and MyString.cpp classes

#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int GetInt(const char* prompt)
{
	cout << prompt;
	string s;
	getline(cin, s);
	return atoi(s.c_str());
}

void AnagramsTest(MyString& key, const char* candidatesCStr[], int count)
{
	// Create strings and add them to a vector
    vector<MyString> candidates;    
    for (int i = 0; i < count; i++)
    {
        candidates.push_back(MyString(candidatesCStr[i]));
    }
    
    // Create the output vector and call the anagram finding function
    vector<MyString> output;
    key.GetAnagrams(candidates, output);
    
    // Display each one
    cout << "Anagrams for ";
    key.Write(cout);
    cout << " are:" << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << "  ";
        output[i].Write(cout);
        cout << endl;
    }
}

void AnagramsTest1()
{
    MyString key("least");
    // Anagrams are:
    // setal, slate, stale, steal, stela, taels, tales, teals, tesla
    const char* candidatesCStr[] = {
        "setal", "sseettaall", "abcde", "slate", "stale", "steal", "blah", "stela", 
		"taels", "it's pretty obvious that you shouldn't be seeing this one",
        "tales", "false", "true", "leas", "teals", "tesla"};
    
	int count = sizeof(candidatesCStr) / sizeof(char*);
	AnagramsTest(key, candidatesCStr, count);
}

void AnagramsTest2()
{
    MyString key("retains");
    // Anagrams are:
    // anestri, asterin, eranist, nastier, ratines, resiant, restain, retinas, 
	// retsina, sainter, stainer, starnie, stearin
    const char* candidatesCStr[] = {
        "aanestri", "anestri", "asterin", "nope", "saint", "staing", "eranist", 
		"nastier", "ratines", "resiant", "cs 223", "is", "awesome", "restain", 
		"retinas", "retsina", "sainter", "stainer", "starnie", "stearin"};
    
	int count = sizeof(candidatesCStr) / sizeof(char*);
	AnagramsTest(key, candidatesCStr, count);
}

int main(int argc, const char* argv[])
{
    MyString str("This is the default string");

	while (true)
	{		
		cout << endl << "Menu" << endl;
		cout << "Current string is: ";
		str.Write(cout);
		cout << endl;
		cout << "1 = Enter a new string to work with" << endl;
		cout << "2 = Find the index of a specific character (IndexOf function)" << endl;
		cout << "3 = Search for a substring (IndexOf function)" << endl;
		cout << "4 = Display a substring (Substring function)" << endl;
		cout << "5 = Split into string array (Split function)" << endl;
        cout << "6 = Anagrams test #1" << endl;
		cout << "7 = Anagrams test #2" << endl;
		cout << "0 = Quit" << endl;

		// Get an option from the user
		string stringSTL;
		getline(cin, stringSTL);

		if ("1" == stringSTL)
		{
			cout << "New string: ";
			getline(cin, stringSTL);
			str.Set(stringSTL.c_str());
			cout << endl;
		}
		else if ("2" == stringSTL)
		{
			cout << "Enter a character to search for: ";
			getline(cin, stringSTL);

			if (stringSTL.length() > 0)
			{
				// Find the starting index and display it
				int index = str.IndexOf(stringSTL.c_str()[0]);
				cout << "Index is: " << index << endl;
			}
		}
		else if ("3" == stringSTL)
		{
			cout << "Enter string to search for: ";
			getline(cin, stringSTL);

			// Find the starting index
			int index = str.IndexOf(stringSTL.c_str());

			cout << "Index is: " << index << endl;
		}
		else if ("4" == stringSTL)
		{
			int startIndex = GetInt("Enter starting index for substring: ");
			int length = GetInt("Enter length for substring: ");
			MyString temp;
			if (str.Substring(startIndex, length, temp))
			{
				cout << "Substring is: ";
				temp.Write(cout);
				cout << endl;
			}
			else
			{
				cout << "Could not get substring, parameters invalid." << endl;
			}
		}
		else if ("5" == stringSTL)
		{
			cout << "Enter a character to use for split: ";
			getline(cin, stringSTL);

			if (stringSTL.length() > 0)
			{
				vector<MyString> strings;
				str.Split(stringSTL.c_str()[0], strings);
				cout << strings.size() << " string(s) returned from split: " << endl;
				for (int i = 0; i < strings.size(); i++)
				{
					cout << "  ";
					strings[i].Write(cout);
					cout << endl;
				}
			}
			else
			{
				cout << "(split operation cancelled)" << endl;
			}
		}
        else if ("6" == stringSTL)
        {
            AnagramsTest1();
        }
		else if ("7" == stringSTL)
        {
            AnagramsTest2();
        }
		else if ("0" == stringSTL)
		{
			break;
		}
		else
		{
			cout << "Unknown menu option" << endl;
		}
	}

	cout << "Done" << endl;
}