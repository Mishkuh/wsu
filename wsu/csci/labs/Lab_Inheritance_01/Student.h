#ifndef	STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

class Student : public Person
{
public:
	Student();
	~Student();

	int totalCredits();
	double gpa();

	int getNumCoursesFinished();
	int getCumulativeCredits();

	void setNumCoursesFinished(int newNum);
	void setCumulativeCredits(int newCredits);

	Student& operator=(Student& s);
	friend istream& operator >> (istream& in, Student& s);
	friend ostream& operator << (ostream& out, Student& s);

private:
	int numCoursesFinished;
	int cumulativeCredits;
	Course currentsCArr[20];
};

typedef struct course
{
//public:
	/*friend class Student;
	Course();
	Course(string newName, int newCredits, double newGrade);
	~Course();

	void setName(string newName);
	void setCredits(int newCredits);
	void setGrade(double newGrade);

	string getName();
	int getCredits();
	double getGrade();*/

	string courseName;
	int creditsAwarded;
	double grade;
}Course;

#endif