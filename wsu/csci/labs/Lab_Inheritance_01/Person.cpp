#include "Person.h"

Person::Person()
{
	age = 0;
	meters = 0.0;
	gender = '\0';
	name = "\0";
}
Person::Person(int newAge, double newMeters, char newGender, string newName)
{
	age = newAge;
	meters = newMeters;
	gender = newGender;
	name = newName;
}
Person::Person(Person& p)
{
	age = p.age;
	meters = p.meters;
	gender = p.gender;
	name = p.name;
}
Person::~Person()
{

}

// GETTERS
int Person::getAge()
{
	return age;
}
char Person::getGender()
{
	return gender;
}
string Person::getName()
{
	return name;
}
double Person::getMeters()
{
	return meters;
}

// SETTERS
void Person::setName(string newName)
{
	name = newName;
}
void Person::setAge(int newAge)
{
	age = newAge;
}
void Person::setMeters(double newMeters)
{
	meters = newMeters;
}
void Person::setGender(char newGender)
{
	gender = newGender;
}

Person& Person::operator=(Person& p)
{
	name = p.name;
	age = p.age;
	meters = p.meters;
	gender = p.gender;

	return (*this);
}

istream& operator >> (istream& in, Person& p)
{
	cout << "name: ";
	in >> p.name;
	cout << "age: ";
	in >> p.age;
	cout << "meters: ";
	in >> p.meters;
	cout << "gender: ";
	in >> p.gender;

	return in;
}
ostream& operator << (ostream& out, Person& p)
{
	out << "name: " << p.name << endl;
	out << "age: " << p.age << endl;
	out << "meters: " << p.meters << endl;
	out << "gender: " << p.gender << endl;
	return out;
}

void TestPerson::TestAssignment()
{
	cout << "Testing Assignment\n";
	Person doppel = *this;
	cout << doppel;
}
void TestPerson::TestExtraction()
{
	cout << "Testing Extraction\n";
	cin >> *this;
}
void TestPerson::TestInsertion()
{
	cout << "Testing Insertion\n";
	cout << *this;
}