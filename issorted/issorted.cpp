// issorted.cpp
// Corey Gray
// 25 Oct 2016
// CS 201 Assignment 5: Takes a vector<int> and bool then checks if the vector is sorted accordingly

#include "issorted.h"
#include <vector>
using std::vector;

// isSorted
// Takes a vector<int> and a bool.
// If the bool is true, it checks if the vector is sorted in ascending order.
// Otherwise, it checks if the vector is sorted in descending order.
bool isSorted(const vector<int> & data,
			  bool ascending)
{
	int size = data.size();
	
	if (size == 0 || size == 1)
	{
		return true;
	}

	if (ascending)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] > data[i + 1])
				return false;
		}

		return true;

	}

	else
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (data[i] < data[i + 1])
				return false;
		}

		return true;
	}
}