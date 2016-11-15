// vectormax.cpp
// Corey Gray
// 14 Nov 2016
// CS 201 Assignment 7: vectorMax detects if a vector is empty and if not prints its contents and the item with the greatest value

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::max_element;

void vectorMax(vector<int> vector)
{
	if (vector.empty())
	{
		cout << "Vector is empty." << endl;
	}

	else
	{
		cout << "Items: ";
		
		for (unsigned int i = 0; i < vector.size(); ++i)
		{
			cout << vector[i] << " ";
		}

		cout << endl;
		cout << "Maximum item: " << *max_element(vector.begin(), vector.end()) << endl;
	}
}

int main()
{
	cout << "Demonstration of function vectorMax." << endl;
	cout << "Prints the contents of a vector and it's maximum value, or the fact that it is empty." << endl;
	cout << endl;

	vector<int> demo1{ 5, 2, 7, 3, 8, 4, 1, 6, 1 };
	vector<int> demo2;
	vector<int> demo3{ 6, 6, 6, 6, 6, 6, 6 };
	vector<int> demo4{ 4, 3, 2, 1 };
	vector<int> demo5{ -1, -5, -6, -9, -10, -4, -5, -7 };
	vector<int> demo6{ 3, 0, 4, 12, 96, -34, -42, 0, 68 };
	vector<int> demo7;
	vector<int> demo8{ -100, 100, -50, 50, -25, 25, -10, 10, -5, 5, -2, 2, -1, 1, 0 };

	cout << "Vector #1" << endl;
	vectorMax(demo1);
	cout << endl;

	cout << "Vector #2" << endl;
	vectorMax(demo2);
	cout << endl;

	cout << "Vector #3" << endl;
	vectorMax(demo3);
	cout << endl;

	cout << "Vector #4" << endl;
	vectorMax(demo4);
	cout << endl;

	cout << "Vector #5" << endl;
	vectorMax(demo5);
	cout << endl;

	cout << "Vector #6" << endl;
	vectorMax(demo6);
	cout << endl;

	cout << "Vector #7" << endl;
	vectorMax(demo7);
	cout << endl;

	cout << "Vector #8" << endl;
	vectorMax(demo8);
}