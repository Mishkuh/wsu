#include "Student.h"
// DO NOT MODIFY THIS FILE
Student::Student(int studentID, const char* studentName)
{
	m_id = studentID;
	m_name = studentName;
}

Student::Student(int studentID, string& studentName)
{
	m_id = studentID;
	m_name = studentName;
}

Student::Student(const Student& copyMe)
{
	m_id = copyMe.m_id;
	m_name = copyMe.m_name;
}

int Student::GetID() const
{
	return m_id;
}

// The "key" for an object is its unique identifier. In this case the student ID 
// is used as the key. Two students could potentially have the same name, but all 
// should have unique IDs.
int Student::GetKey() const
{
	return m_id;
}

string Student::GetName() const
{
	return m_name;
}

string Student::ToString() const
{
	char* buf = new char[m_name.length() + 128];
	sprintf(buf, "Name=\"%s\", ID=%d", m_name.c_str(), m_id);
	string theString = buf;
	delete [] buf;
	return theString;
}
