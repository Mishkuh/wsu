// Cpt S 223 Homework Assignment - Hash table implementation


/////////////////////////////////////////////////////////
//////////////// Michael Wiens 11383291 /////////////////
////////////////         Cpts 223       /////////////////
/////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Gradebook.h"

using namespace std;

void ProcessLine(string line, Gradebook& gradebook)
{
	if (line.substr(0, 4) == "add,")
	{
		int secondCommaIndex = line.find(',', 4);
		string name = line.substr(4, secondCommaIndex - 4);
		string gradeString = line.substr(secondCommaIndex + 1);
		char* term;
		double grade = strtod(gradeString.c_str(), &term);
		gradebook.AddEntry(name, grade);
	}
	else if (line.substr(0, 7) == "lookup,")
	{
		string nameString = line.substr(7);
		double grade = 0.0;
		if (gradebook.GetGrade(nameString, grade))
		{
			cout << "Found grade of " << grade;
			cout << " for student " << nameString << endl;
		}
		else
		{
			cout << "Could not find student: " << nameString << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	srand(time(NULL));
	Gradebook gb;

	if (argc > 1)
	{
		cout << "Opening file " << argv[1] << endl;
		ifstream ifs;
		ifs.open(argv[1], ifstream::in);

		string line;
		while (true)
		{
			getline(ifs, line);
			ProcessLine(line, gb);
			if (line.empty() || ifs.eof())
			{
				break;
			}
		}

		cout << "Closing input file" << endl;
		ifs.close();
		cout << "Done" << endl;
		return 0;
	}

	cout << "Missing input file name" << endl;
	return -1;
}