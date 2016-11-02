// diamond.cpp
// Corey Gray
// 11 Sep 2016
// CS 201 Assignment 1: Receives input from a user then prints an appropriately sized diamond.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

int main()
{
	cout << "Enter a positive integer to make a diamond: " << endl;
	string line;
	getline(cin, line);
	cout << endl;

	// Error checking
	if (!cin)
	{
		cout << "That was not valid input." << endl;
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');

		return 0;
	}

	istringstream in(line);
	int radius;
	in >> radius;

	// Error checking
	if (!in)
	{
		cout << "The radius must be a positive integer." << endl;
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');

		return 0;
	}
	if (radius < 1)
	{
		cout << "The radius must be a positive integer." << endl;
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');

		return 0;
	}

	// Print the diamond's dimensions
	int height;
	height = radius * 2 - 1;
	cout << "You entered: " << radius << endl;
	cout << "This creates a diamond " << height  << " rows high." << endl;
	cout << endl;

	// Make the top of the diamond
	int width;
	for (int row = 1; row <= radius; ++row)
	{
		width = row * 2 - 1;
		for (int blank = 0; blank <= ((height - width) / 2) - 1; ++blank)
		{
			cout << " ";
		}
		for (int column = 1; column <= width; ++column)
		{
			cout << "#";
		}
		for (int blank = 0; blank <= ((height - width) / 2) - 1; ++blank)
		{
			cout << " ";
		}
		cout << endl;
	}
	
	// Make the bottom of the diamond
	for (int row = radius - 1; row >= 1; --row)
	{
		width = row * 2 - 1;
		for (int blank = 0; blank <= ((height - width) / 2) - 1; ++blank)
		{
			cout << " ";
		}
		for (int column = 1; column <= width; ++column)
		{
			cout << "#";
		}
		for (int blank = 0; blank <= ((height - width) / 2) - 1; ++blank)
		{
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Press ENTER to quit.";
	while (cin.get() != '\n');

	return 0;
}