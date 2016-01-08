// Cpt S 223 - Homework 4 - Sorting (part 2)
// If you modify this file do so only for testing purposes then revert 
// back to the original version before submitting your homework.
// You should not NEED to change anything in this file. The implementation 
// that you need to complete is the ArraySorter class.

#include "main.h"

using namespace std;

// Generates an array with random numbers in the range [0,1000]
int* GenArr(int count)
{
	int* arr = new int[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % 1001;
	}
	return arr;
}

int main(int argc, char* argv[])
{
	// Seed the random number generator
	srand(time(NULL));
	
	int count = 200000;
	int* numsOriginal = GenArr(count);

	// Create the sorter object
	ArraySorter sorter;

	while (true)
	{
		// Ask for an action
		cout << "Choose option:" << endl;
		cout << "  1 = Display array contents (may be VERY long)" << endl;
		cout << "  2 = Sort with insertion sort (may be slow)" << endl;
		cout << "  3 = Sort with shell sort (gap 5 then gap 1)" << endl;
		cout << "  4 = Sort with shell sort (gap 12, then gap 7, then 3, then 1)" << endl;
		cout << "  5 = Sort with mergesort" << endl;
		cout << "  6 = Sort with quicksort" << endl;
		cout << "  7 = Evan's sorting algorithm" << endl;
		cout << "  (anything else) = quit" << endl;
		cout << "? ";
		int opt = -1;
		cin >> opt;

		// Make a copy of the number array
		int* nums = new int[count];
		for (int i = 0; i < count; i++)
		{
			nums[i] = numsOriginal[i];
		}

		clock_t time = clock();

		bool didSort = true;
		if (1 == opt)
		{
			// Show the contents
			cout << "Array contents (" << count << " items):";
			for (int i = 0; i < count; i++)
			{
				cout << " " << nums[i];
			}
			cout << endl << endl;
			didSort = false;
		}
		else if (2 == opt)
		{
			sorter.InsertionSort(nums, count);
		}
		else if (3 == opt)
		{
			int gaps[2] = {5, 1};
			sorter.ShellSort(nums, count, gaps, 2);
		}
		else if (4 == opt)
		{
			int gaps[4] = {12, 7, 3, 1};
			sorter.ShellSort(nums, count, gaps, 4);
		}
		else if (5 == opt)
		{
			sorter.MergeSort(nums, count);
		}
		else if (6 == opt)
		{
			sorter.QuickSort(nums, count);
		}
		else if (7 == opt)
		{
			EvanSort(nums, count);
		}
		else
		{
			delete [] nums;
			break;
		}

		if (didSort)
		{
			// Stop the timer
			time = clock() - time;
			
			// Show the contents of the array
			/*
			cout << "Array contents after sorting:";
			for (int i = 0; i < count; i++)
			{
				cout << " " << nums[i];
			}
			cout << endl;
			*/

			// Verify
			if (!ArraySorter::IsSorted(nums, count))
			{
				cout << endl << "ERROR: Array is NOT correctly sorted!" << endl << endl;
			}
			else
			{
				cout << "Array contents verified as correctly sorted" << endl;
			}

			cout << "Sorted in " << ((double)time / CLOCKS_PER_SEC) << " seconds";
		}

		cout << endl << endl;

		// Free the copy (it will be rebuilt in the next loop iteration)
		delete [] nums;
	}

	delete [] numsOriginal;
}

void EvanSort(int* arr, int n)
{
	int min = 0x7fFFffFF;
	int max = 0x80000000;

	// First pass: find min and max
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) { min = arr[i]; }
		if (arr[i] > max) { max = arr[i]; }
	}

	// Allocate frequency table
	int count = max - min + 1;
	int* freq = new int[count];
	if (!freq)
	{
		cout << "Not enough memory to use my awesome sorting algorithm" << endl;
		return;
	}

	// Initialize frequency table to all zeros
	for (int i = 0; i < count; i++)
	{
		freq[i] = 0;
	}

	// Count the frequency for each number in the array
	for (int i = 0; i < n; i++)
	{
		freq[arr[i] - min]++;
	}

	// Produce the sorted output
	int* output = arr;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < freq[i]; j++)
		{
			*output++ = (min + i);
		}
	}

	// Free memory
	delete [] freq;
}