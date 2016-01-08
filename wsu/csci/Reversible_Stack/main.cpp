// Michael Wiens
// 11383291
// CptS 223 - Advanced Data Structures
// Homework assignment #1

#include "ReversibleStack.h" // You need to create ReversibleStack.h

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

void Display(ReversibleStack& rs)
{
	int temp;
	ReversibleStack *tempArray = new ReversibleStack;

	if (!rs.isEmpty())
	{
		temp = rs.pop();
		printf("%d ", temp);
		tempArray->push(temp);
		Display(rs);
		rs.push(tempArray->pop());
	}

	// Implement this function (use only Push, Pop and IsEmpty member functions of stack)
	// After the function completes, the stack should be unmodified (see assignment instructions)
}

int main(int argc, char* argv[])
{
	ReversibleStack rs;
	ifstream inFile;
	inFile.open(argv[2], ifstream::in);
	if (!inFile.is_open())
	{
		cout << "Could not open: " << argv[2] << endl;
		return 0;
	}

	while (!inFile.eof())
	{
		string line;
		getline(inFile, line);

		// Process the command here
		if (0 == line.compare(0, 6, "header"))
		{
			// Display the header line here, as the instructions describe
			cout << "Michael Wiens - 11383291\n" << endl;
		}
		else if (0 == line.compare(0, 7, "display"))
		{
			Display(rs);
			cout << endl;
		}
		else if (0 == line.compare(0, 4, "push"))
		{
			int pushValue = 0;
			string tempString = line.substr(4);
			pushValue = stoi(tempString);
			rs.push(pushValue);
		}
		else if (0 == line.compare(0, 3, "pop"))
		{
			rs.pop();
		}
		else if (0 == line.compare(0, 7, "reverse"))
		{
			rs.reverse();
		}
		else if (0 == line.compare(0, 7, "isempty"))
		{
			if (rs.isEmpty())
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
		// You'll need to implement several other commands in here
		else
		{
			cout << "Unknown command: " << line;
		}
	}

	// Complete
	inFile.close();
	cout << endl << "Done" << endl;
	system("pause");
	return 1;
}