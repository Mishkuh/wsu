#include "Student.h"

Student::Student()
{
	numCoursesFinished = 0;
	cumulativeCredits = 0;
	age = 0;
	name = "\0";
	meters = 0.0;
	gender = '\0';
}
Student::~Student()
{

}

int Student::totalCredits()
{
	int total = 0;

	return total;
}
double Student::gpa()
{
	double gpa = 0.0;

	return gpa;
}

int Student::getNumCoursesFinished()
{
	return numCoursesFinished;
}
int Student::getCumulativeCredits()
{
	return cumulativeCredits;
}

void Student::setNumCoursesFinished(int newNum)
{
	numCoursesFinished = newNum;
}
void Student::setCumulativeCredits(int newCredits)
{
	cumulativeCredits = newCredits;
}

Student& Student::operator=(Student& s)
{
	name = s.name;
	age = s.age;
	meters = s.meters;
	gender = s.gender;
	numCoursesFinished = s.numCoursesFinished;
	cumulativeCredits = s.cumulativeCredits;

	return *this;
}

istream& operator >> (istream& in, Student& s)
{
	cout << "name: ";
	in >> s.name;
	cout << "age: ";
	in >> s.age;
	cout << "meters: ";
	in >> s.meters;
	cout << "gender: ";
	in >> s.gender;
	cout << "number of courses finished: ";
	in >> s.numCoursesFinished;
	cout << "cumulative credits: ";
	in >> s.cumulativeCredits;

	return in;
}
ostream& operator << (ostream& out, Student& s)
{
	out << "name: " << s.name << endl;
	out << "age: " << s.age << endl;
	out << "meters: " << s.meters << endl;
	out << "gender: " << s.gender << endl;
	out << "number of courses finished: " << s.numCoursesFinished << endl;
	out << "cumulative credits: " << s.cumulativeCredits << endl;
	return out;
}

/*Course::Course()
{
	grade = 0.0;
	courseName = "\0";
	creditsAwarded = 0;
}
Course::Course(string newName, int newCredits, double newGrade)
{
	courseName = newName;
	creditsAwarded = newCredits;
	grade = newGrade;
}
Course::~Course()
{

}

void Course::setName(string newName)
{
	courseName = newName;
}
void Course::setCredits(int newCredits)
{
	creditsAwarded = newCredits;
}
void Course::setGrade(double newGrade)
{
	grade = newGrade;
}

string Course::getName()
{
	return courseName;
}
int Course::getCredits()
{
	return creditsAwarded;
}
double Course::getGrade()
{
	return grade;
}*/