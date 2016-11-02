// boxprint.cpp
// Corey Gray
// 11 Sep 2016
// CS 201 Assignment 1: Receives input from a user then prints that input with a box around it.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

int main()
{
	cout << "Enter a line of text: ";
	string line;
	getline(cin, line);

	// Error checking
	if (!cin)
	{
		cout << "That was not valid input." << endl;
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');

		return 0;
	}

	// Number of characters in line
	int n = line.size(); 

	// Checks for an empty line
	if (n == 0)
	{
		cout << "You entered an empty line. Please input something more next time." << endl;
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');

		return 0;
	}

	// Top of box
	for (int i = 1; i <= n + 4; ++i)
	{
		cout << "*";
	}
	cout << endl;
	// Blank line inside box
	cout << "*";
	for (int i = 1; i <= n + 2; ++i)
	{
		cout << " ";
	}
	cout << "*" << endl;
	// Input line within box
	cout << "* " << line << " *" << endl;
	// Another blank line inside box
	cout << "*";
	for (int i = 1; i <= n + 2; ++i)
	{
		cout << " ";
	}
	cout << "*" << endl;
	// Bottom of box
	for (int i = 1; i <= n + 4; ++i)
	{
		cout << "*";
	}
	cout << endl;

	cout << "Press ENTER to quit.";
	while (cin.get() != '\n');
}