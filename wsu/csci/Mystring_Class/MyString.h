// Cpt S 223 Homework Assignment - MyString class
// Michael Wiens 11383291

#ifndef MYSTRINGH
#define MYSTRINGH

#include <iostream>
#include <vector>

class MyString
{
private:
    char* m_str;

	MyString(const char* str, int charCount);
    
    static bool AreEqual(const char* str1, const char* str2, int numCharsToCompare);

	// Copies the specified number of characters from the source to destination
	static void Copy(char* destination, const char* source, int count);
    
    // Utility function to compute the length of a string. The null-terminating 
	// character is NOT counted.
    static int Length(const char* str);
    
public:
    MyString();
	MyString(const MyString &copyMe);
	MyString(const char* str);
	~MyString();
    
    int GetAnagrams(std::vector<MyString>& candidates, std::vector<MyString>& output);
	int IndexOf(char c, int startIndex = 0) const;
	int IndexOf(const char* str, int startIndex = 0) const;
    int Length() const;
	void Set(const char* str);
	void Split(char c, std::vector<MyString>& outputVector) const;
	bool Substring(int startIndex, int length, MyString& output) const;
	void Write(std::ostream& stream);
};

int * BuildFreqTable(const char*s);

#endif