#ifndef GRADEBOOK223_H
#define GRADEBOOK223_H

#include <string>
#include <unordered_map>
#include <vector>

using std::string;

class List;
class Student;

class Student
{
	friend class List;
public:
	// constuctors and assignment operator
	Student()
	{
		pNext = NULL;
		name = "\0";
		grade = 0.0;
		hashCode = 0;
	}
	Student(string newName, double newGrade)
	{
		name = newName;
		grade = newGrade;
		pNext = NULL;
		hashCode = makeHashCode(newName);
	}
	Student(Student &copy)
	{
		pNext = copy.pNext;
		name = copy.name;
		grade = copy.grade;
	}
	Student & operator= (Student &copy)
	{
		pNext = copy.pNext;
		name = copy.name;
		grade = copy.grade;

		return *this;
	}

	// getters
	string getName(){ return name; }
	double getGrade(){ return grade; }
	int getHashCode(){ return hashCode; }
	Student *getNext(){ return pNext; }

	// setters
	void setName(string newName){ name = newName; }
	void setGrade(double newGrade){ grade = newGrade; }
	void setHashCode(int newHC){ hashCode = newHC; }

	// generates a unique hash code
	int makeHashCode(string name)
	{
		int hashCode = 0;
		int i = 0;

		// adds every other characters ascii value and ascii val *2
		while (name[i++])
		{
			if (i % 2)
				hashCode += name[i];
			else
				hashCode += 2 * name[i];
		}
		hashCode += i;

		return hashCode;
	}

private:
	Student *pNext;
	string name;
	double grade;
	int hashCode;
};

// List class for linked list
class List
{
public:
	// constructors and overloaded assignment
	List()
	{
		pHead = NULL;
	}
	List(List &copy)
	{
		pHead = copy.pHead;
	}
	List & operator=(List &copy)
	{
		pHead = copy.pHead;
	}

	// inserts student to front of list
	void insertFront(Student &newStudent)
	{
		newStudent.pNext = pHead;
		pHead = &newStudent;
	}

	// indicates whether list is empty
	bool isEmpty(){ return (!pHead); }

	// getter
	Student * getHead(){ return pHead; }
	// setter
	void setHead(Student *newHead){ pHead = newHead; }
	
private:
	Student *pHead = NULL;
};

class Gradebook
{
	friend class Student;

private:
	// hash table implementation with lists
	List data[1009];

public:
	Gradebook(void);

	void AddEntry(std::string& studentName, double grade);
	bool GetGrade(std::string& studentName, double& out_gradeIfFound);
};

#endif