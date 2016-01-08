#pragma once
// DO NOT MODIFY THIS FILE
#include <string>

using namespace std;

// Class for an immutable Student object
class Student
{
private:
	int m_id;
	string m_name;

public:
	Student(int studentID, const char* studentName);
	Student(int studentID, string& studentName);
	Student(const Student& copyMe);
	
	int GetID() const;
	int GetKey() const;
	string GetName() const;
	string ToString() const;
};

