// Cpt S 223 - 2-3-4 Tree Homework Assignment
// DO NOT MODIFY THIS FILE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "CS223_234Tree.h"
#include "Student.h"

using namespace std;

void ProcessLine(string line, CS223_234Tree<Student>& tree)
{
	if (line.substr(0, 4) == "add,")
	{
		int secondCommaIndex = line.find(',', 4);
		string name = line.substr(4, secondCommaIndex - 4);
		string idString = line.substr(secondCommaIndex + 1);
		int id = atoi(idString.c_str());
		tree.Add(Student(id, name));
	}
	else if (line.substr(0, 7) == "remove,")
	{
		string idString = line.substr(7);
		int id = atoi(idString.c_str());
		tree.Remove(id);
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	CS223_234Tree<Student> tree;

	if (argc > 1)
	{
		ifstream ifs;
		ifs.open(argv[1], ifstream::in);

		string line;
		while (true)
		{
			getline(ifs, line);
			ProcessLine(line, tree);
			if (line.empty() || ifs.eof())
			{
				break;
			}
		}

		// Do one final display of the tree
		tree.Display(cout);
		cout << endl;
		tree.DisplayLevelKeys(cout);

		cout << "Closing input file" << endl;
		ifs.close();
		cout << "Done" << endl;
		return 0;
	}

	while (true)
	{
		cout << "Menu" << endl;
		cout << " 1 = Display tree contents in order" << endl;
		cout << " 2 = Display keys on tree levels" << endl;
		cout << " 3 = Find a student by ID number and display their info" << endl;
		cout << " 4 = Find student with minimum ID number and display their info" << endl;
		cout << " 5 = Add up to 40 random students to the tree" << endl;
		cout << " 6 = Remove a student by ID number" << endl;
		cout << " 0 = Quit" << endl;

		string s;
		getline(cin, s);

		if (s == "1")
		{
			tree.Display(cout);
			cout << endl;
		}
		else if (s == "2")
		{
			tree.DisplayLevelKeys(cout);
			cout << endl;
		}
		else if (s == "3")
		{
			cout << "ID of student to find=";
			getline(cin, s);
			int id = atoi(s.c_str());
			Student* s = tree.Find(id);
			if (s)
			{
				cout << "Found student: " << s->ToString() << endl;
			}
			else
			{
				cout << "Student not found" << endl;
			}
		}
		else if (s == "4")
		{
			Student* s = tree.GetMin();
			if (s)
			{
				cout << "Found student: " << s->ToString() << endl;
			}
			else
			{
				cout << "Student not found" << endl;
			}
		}
		else if (s == "5")
		{
			int added = 0;
			for (int i = 0; i < 40; i++)
			{
				char nameBuf[256];
				sprintf(nameBuf, "Student %c", 'A' + (i % 26));
				int num = rand() % 100 + 1;
				//Student *newStudent = new Student(num, nameBuf);
				if (tree.Add(Student(num, nameBuf)))
				{
					added++;
				}

#if defined(DEBUG) || defined(_DEBUG)
				if (!tree.IsTreeValid())
				{
					cout << "DEBUG ERROR: Tree is not valid after insertion of student ";
					cout << "with key=" << num << endl;
				}
#endif
			}
			cout << "Added " << added << " objects to the tree" << endl;
		}
		else if (s == "6")
		{
			cout << "ID of student to delete=";
			getline(cin, s);
			int id = atoi(s.c_str());
			if (tree.Remove(id))
			{
				cout << "Student removed" << endl;
			}
			else
			{
				cout << "Student not found" << endl;
			}

#if defined(DEBUG) || defined(_DEBUG)
			if (!tree.IsTreeValid())
			{
				cout << "DEBUG ERROR: Tree is not valid after deletion of student ";
				cout << "with id=" << id << endl;
			}
#endif
		}
		else if (s == "0")
		{
			break;
		}
	}

	cout << "Done" << endl;
}