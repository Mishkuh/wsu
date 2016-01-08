#include "ArraySorter.h"


ArraySorter::ArraySorter(void)
{
}

void ArraySorter::InsertionSort(int* arr, int n)
{
	InsertionSort(arr, n, 0, 1);
}

void ArraySorter::InsertionSort(int* arr, int n, int startIndex, int gap)
{
	// You implemented this function in the last homework assignment.
	// If you want to paste it here you can, but it will not be graded for 
	// this homework assignment.
}

// Checks to see if the array is in sorted order
bool ArraySorter::IsSorted(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		// If an item is less than the one before it, then we're not sorted
		if (arr[i] < arr[i - 1])
		{
			return false;
		}
	}

	return true;
}

void ArraySorter::MergeSort(int* arr, int n)
{
	// You must implement this function
}

void ArraySorter::QuickSort(int* arr, int n)
{
	// You must implement this function
}

void ArraySorter::ShellSort(int* arr, int n, int* gapVals, int gapValsCount)
{
	// You implemented this function in the last homework assignment.
	// If you want to paste it here you can, but it will not be graded for 
	// this homework assignment.
}
