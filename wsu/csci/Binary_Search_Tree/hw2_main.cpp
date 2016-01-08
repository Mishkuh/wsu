// (put your name and ID number here)
// Unless you want to add extra things to this file for testing purposes, you shouldn't 
// modify this code. It is already set up to display a menu, get input from the user, 
// and call the appropriate tree functions.

#include "hw2_main.h"

using namespace std;

int main(int argc, char* argv[])
{
	HW2BST tree;
	
	if (argc < 2)
	{
		cout << "Input file name not found, reverting to menu mode" << endl;
		MenuMode();
	}
	else
	{
		FILE* f = fopen(argv[1], "r");
		if (f)
		{
			char line[4096];
			while (fgets(line, sizeof(line), f))
			{
				ProcessLine(tree, line);
			}
			fclose(f);
		}
		else
		{
			cout << "ERROR: Could not open file: " << argv[1] << endl;
		}
	}

	cout << "Done" << endl;
	return 0;
}

void MenuMode()
{
	HW2BST tree;
	
	while (true)
	{
		// Display a menu with options
		cout << "---------------------------------------------" << endl;
		cout << "HW2 - Binary Search Tree Review - Menu" << endl;
		cout << "  1 = Add a number to the binary search tree" << endl;
		cout << "  2 = Remove a number from the binary search tree" << endl;
		cout << "  3 = Display the binary search tree as a list" << endl;
		cout << "  4 = Display the binary search tree levels" << endl;
		cout << "  5 = Add sample numbers: 100, 50, 150, 25, 175, 75, 125, 122, 223" << endl;
		cout << "  0 = Quit" << endl;
		cout << "---------------------------------------------" << endl;

		int number = -1;
		cin >> number;

		if (1 == number)
		{
			number = -1;
			while (number < 0 || number > 999)
			{
				cout << "Enter a number in the range [0,999]: ";
				cin >> number;
				cout << endl;
			}
			
			if (tree.Add(number))
			{
				cout << "Added " << number << endl;
			}
			else
			{
				cout << "Failed to add " << number << endl;
			}
		}
		else if (2 == number)
		{
			number = -1;
			cout << "Enter a number to remove from the tree: ";
			cin >> number;
			cout << endl;

			if (tree.Remove(number))
			{
				cout << "Value was removed" << endl;
			}
			else
			{
				cout << "Value was NOT removed because it was not found in the tree" << endl;
			}
		}
		else if (3 == number)
		{
			tree.DisplayContents(cout);
		}
		else if (4 == number)
		{
			tree.DisplayLevels(cout);
		}
		else if (5 == number)
		{
			tree.Add(100);
			tree.Add(50);
			tree.Add(150);
			tree.Add(25);
			tree.Add(175);
			tree.Add(75);
			tree.Add(125);
			tree.Add(122);
			tree.Add(223);
		}
		else if (0 == number)
		{
			break;
		}
		else
		{
			cout << "Invalid option!" << endl << endl;
		}
	}
}

// Processes a line from the command file
void ProcessLine(HW2BST& tree, char* line)
{
	if (0 == strncmp("display_tree", line, strlen("display_tree")))
	{
		tree.DisplayLevels(cout);
	}
	if (0 == strncmp("display_list", line, strlen("display_list")))
	{
		tree.DisplayContents(cout);
	}
	else if (0 == strncmp("add:", line, strlen("add:")))
	{
		// Parse the numerical values from this line
		char* numString = strtok(&line[4], ",");
		while (numString)
		{
			int number = atoi(numString);
			if (tree.Add(number))
			{
				cout << "Added " << number << endl;
			}
			numString = strtok(NULL, ",");
		}
	}
	else if (0 == strncmp("remove:", line, strlen("remove:")))
	{
		// Parse the numerical values from this line
		char* numString = strtok(&line[7], ",");
		while (numString)
		{
			int number = atoi(numString);
			if (tree.Remove(number))
			{
				cout << "Removed " << number << endl;
			}
			numString = strtok(NULL, ",");
		}
	}
}