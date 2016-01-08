// Cpt S 223 Homework Assignment - MyString class
// Michael Wiens

#include "MyString.h"

using namespace std;

MyString::MyString()
{
	m_str = new char[1];
	m_str[0] = 0;
}

MyString::MyString(const MyString &copyMe)
{
	int length = copyMe.Length();
	this->m_str = new char[length + 1];

	Copy(m_str, copyMe.m_str, copyMe.Length()); // use a predefined function

	this->m_str[length] = '\0';
}

MyString::MyString(const char* str)
{
    // Special case for a null string
	if (!str)
	{
		m_str = new char[1];
		m_str[0] = 0;
		return;
	}
	
	int len = Length(str);    
    m_str = new char[len + 1];
    Copy(m_str, str, len + 1);
}

// This is a private constructor that assumes both parameters are valid, 
// thus there isn't any error checking done on these parameters.
MyString::MyString(const char* str, int charCount)
{
	m_str = new char[charCount + 1];
	Copy(m_str, str, charCount);
	m_str[charCount] = 0;
}

MyString::~MyString()
{
    if (m_str)
	{
		delete [] m_str;
		m_str = NULL;
	}
#if defined(DEBUG) || defined(_DEBUG)
	else
	{
		std::cout << "DEBUG: WARNING, destructor called when m_str is NULL!" << std::endl;
	}
#endif
}

// Compares the desired number of characters in two strings and returns true if
// they are all equal. If the null-terminator on either string is encountered
// before the desired number of characters have been compared, then false
// will be returned.
bool MyString::AreEqual(const char* str1, const char* str2, int numCharsToCompare)
{
    while (numCharsToCompare--)
    {
        if (!str1[0])
        {
            return (0 == str2[0] && 0 == numCharsToCompare);
        }
        
        if (str1[0] != str2[0])
        {
            return false;
        }
        
        str1++;
        str2++;
    }
    
    // Coming here means we compared the desired number of characters
    // and didn't encounter a mismatch, so we return true.
    return true;
}

// Copies the specified number of characters from the source to destination. 
// No null terminators are used for anything. The specified number of characters 
// will be copied exactly and this could potentially go past a null terminator.
void MyString::Copy(char* destination, const char* source, int count)
{
	while (count--)
	{
		*destination++ = *source++;
	}
}

int MyString::GetAnagrams(vector<MyString>& candidates, vector<MyString>& output)
{
	int *table1, *table2;
	int i = 0, j = 0;

	table1 = BuildFreqTable(this->m_str);

	while(i < candidates.size())
	{
		table2 = BuildFreqTable(candidates[i].m_str);

		while(table1[j] == table2[j])
			j++;
		if (j >= 256) // if j reaches the last index then the tables are equal
			output.push_back(candidates[i]);
		j = 0; // reset j

		i++;
	}

	return 1;
}

// helper function to build frequency table
int * BuildFreqTable(const char*s)
{
	int i;
	int* table = new int[256];
	for (int i=0; i<256; i++) 
		table[i] = 0;

	while (*s)
	{
		table[*s]++;
		s++;
	}

return table;
}

int MyString::IndexOf(char c, int startIndex) const
{
	while(c != this->m_str[startIndex])
	{
		startIndex++;
	}
	if(startIndex <= Length(m_str))
		return startIndex;

	return -1;
}

int MyString::IndexOf(const char* str, int startIndex) const
{
	int i = 0, length = Length(str), thisLength = this->Length();

	while(!AreEqual(str, m_str + i, length) && i + length <= thisLength)
		i++;

	if(i + length > thisLength)
		return -1;
	else
		return i;
}

int MyString::Length() const
{
    return Length(m_str);
}

int MyString::Length(const char* str)
{
    int len = 0;
    while (*str++)
    {
        len++;
    }
    return len;
}

// Sets the string to a new string value. This is the kind of function 
// that only a mutable string class would have.
void MyString::Set(const char* str)
{
	// First delete the old string
	if (m_str)
	{
		delete [] m_str;
	}

	if (str)
	{
		int len = Length(str);    
		m_str = new char[len + 1];
		char* dst = m_str;
		while (*dst++ = *str++);
	}
	else
	{
		m_str = new char[1];
		m_str[0] = 0;
	}
}

void MyString::Split(char c, std::vector<MyString>& outputVector) const
{
	int i = 0, cur = 0, length = this->Length();
	char *temp = new char[length+1];

	while(i < length + 1)
	{
		if(c == m_str[i] && m_str[i] != '\0')
		{
			temp[cur] = '\0';
			cur = 0;
			outputVector.push_back(MyString(temp));
		}
		else
			temp[cur++] = this->m_str[i];

		i++;
	}
	temp[cur] = '\0';
	outputVector.push_back(MyString(temp));

}

// Gets a substring from this string and stores it in the output string. If 
// the substring cannot be parsed, then false is returned and the output 
// string is not modified.
bool MyString::Substring(int startIndex, int length, MyString& output) const
{
	int thisLength = this->Length(), i = 0;
	char *temp = new char[thisLength+1];

	while(startIndex < thisLength && length--)
	{
		temp[i] = m_str[startIndex];
		startIndex++;
		i++;
	}

	temp[i] = '\0';

	output.Set(temp);

	return true;
}

void MyString::Write(std::ostream& stream)
{
	stream << m_str;
}