// collatz.cpp
// Corey Gray
// 17 Sep 2016
// CS 201 Assignment 2: Receives a positive integer from the user then prints the Collatz sequence starting at that integer.

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
		cout << "Enter a positive integer to start the Collatz sequence or type '0' to quit: ";
		string input;
		getline(cin, input);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		istringstream in(input);
		int seq;
		in >> seq;

		// Error checking
		if (!in)
		{
			cout << "The sequence must start with a positive integer." << endl;
			continue;
		}

		if (seq < 0)
		{
			cout << "The sequence must start with a positive integer." << endl;
			continue;
		}

		// Quit
		if (seq == 0)
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		// Collatz sequence
		while (seq)
		{
			if (seq == 1)
			{
				cout << seq << endl;
				break;
			}
			if ((seq % 2) == 1)
			{
				cout << seq << " ";
				seq = 3 * seq + 1;
			}
			if ((seq % 2) == 0)
			{
				cout << seq << " ";
				seq = seq / 2;
			}
		}
	}
}
