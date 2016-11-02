// boxprint2.cpp
// Corey Gray
// 17 Sep 2016
// CS 201 Assignment 2: Receives input from a user then prints that input with a box around it with a width specified by the user.

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
	while (true)
	{
		// Text inside the box
		cout << "Enter a line of text or type 'quit' to quit: ";
		string text;
		getline(cin, text);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		// Quit
		if (text == "quit")
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		// Number of characters in line
		int n = text.size();

		// Checks for an empty line
		if (n == 0)
		{
			cout << "You entered an empty line. Please input something more substantial." << endl;
			continue;
		}

		// Thickness of the box
		cout << "Enter a positive integer for how thick the box should be or type '0' to quit: ";
		string thick;
		getline(cin, thick);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		istringstream in(thick);
		int box;
		in >> box;
		
		// Error checking
		if (!in)
		{
			cout << "The thickness must be a positive integer." << endl;
			continue;
		}

		if (box < 0)
		{
			cout << "The thickness must be a positive integer." << endl;
			continue;
		}

		// Quit
		if (box == 0)
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		// Top of box
		for (int i = 1; i <= box; ++i)
		{
			for (int i = 1; i <= n + 2 + box*2; ++i)
			{
				cout << "*";
			}
			cout << endl;
		}

		// Blank line inside box
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		for (int i = 1; i <= n + 2; ++i)
		{
			cout << " ";
		}
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		cout << endl;

		// Input line within box
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		cout << " " << text << " ";
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		cout << endl;

		// Another blank line inside box
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		for (int i = 1; i <= n + 2; ++i)
		{
			cout << " ";
		}
		for (int i = 1; i <= box; ++i)
		{
			cout << "*";
		}
		cout << endl;

		// Bottom of box
		for (int i = 1; i <= box; ++i)
		{
			for (int i = 1; i <= n + 2 + box*2; ++i)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}