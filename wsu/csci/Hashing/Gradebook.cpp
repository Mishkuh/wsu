#include "Gradebook.h"

using namespace std;

Gradebook::Gradebook(void)
{
	for (int i = 0; i < 1009; i++)
	{
		data[i].setHead(NULL);
	}
}

void Gradebook::AddEntry(string& studentName, double grade)
{
	Student *newStudent = new Student(studentName, grade);

	int index = newStudent->getHashCode() % 1009;

	if (data[index].isEmpty())
	{
		data[index].insertFront(*newStudent);
	}
	else
	{
		Student *pCur = data[index].getHead();

		while (pCur)
		{
			if (pCur->getName() == newStudent->getName())			
				return;
			else
				pCur = pCur->getNext();
		}

		data[index].insertFront(*newStudent);
	}

}

bool Gradebook::GetGrade(std::string& studentName, double& out_gradeIfFound)
{
	Student newNode;
	int search = newNode.makeHashCode(studentName);

	int index = search % 1009;

	if (data[index].isEmpty())
	{
		return false;
	}
	else
	{
		Student *pCur = data[index].getHead();
		while (pCur)
		{
			if (pCur->getName() == studentName)
			{
				out_gradeIfFound = pCur->getGrade();
				return true;
			}
			else
			{
				pCur = pCur->getNext();
			}
		}

		return false;
	}
}