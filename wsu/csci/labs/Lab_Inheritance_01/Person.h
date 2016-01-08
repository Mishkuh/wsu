#ifndef	PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::endl;
using std::string;
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

class Person
{
public:
	Person();
	Person(int newAge, double newMeters, char newGender, string newName);
	Person(Person& p);
	~Person();

	void setName(string newName);
	void setAge(int newAge);
	void setGender(char newGender);
	void setMeters(double newMeters);

	string getName();
	int getAge();
	char getGender();
	double getMeters();

	Person& operator = (Person& p);
	friend istream& operator >> (istream& in, Person& p);
	friend ostream& operator << (ostream& out, Person& p);

protected:
	string name;
	int age;
	char gender;
	double meters;
};

class TestPerson : public Person
{
public:
	void TestAssignment();
	void TestExtraction();
	void TestInsertion();
};

#endif