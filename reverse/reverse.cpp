// reverse.cpp
// Corey Gray
// 02 Nov 2016
// CS 201 Assignment 6: Demonstrates a function that takes an array and its size then reverses the arrays elements

#include <iostream>
using std::cout;
using std::endl;

 int * reverseArray(const int arr[], int size)
{
	int * copy;
	copy = new int[size]();

	for (int i = 0; i < size; ++i)
	{
		int position = size - 1 - i; // Size counts from 1 but arrays count from 0 so there's an adjustment
		copy[i] = arr[position];
	}

	return copy;
}

int main()
{
	int test[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	cout << "This is the original array: ";
	
	for (int i = 0; i < 10; ++i)
	{
		cout << test[i] << ", ";
	}

	cout << endl;

	int * output = reverseArray(test, 10);

	cout << "This is the reversed array: ";

	for (int i = 0; i < 10; ++i)
	{
		cout << output[i] << ", ";
	}

	cout << endl;
}