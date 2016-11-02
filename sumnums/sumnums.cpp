// sumnums.cpp
// Corey Gray
// 26 Sep 2016
// CS 201 Assignment 3: Receives a positive integer from the user then sums the integers 1 through the given integer.

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
	// Introduction
	cout << "This program sums the integers between 1 and the integer you enter." << endl;

	while(true)
	{
		// Prompt
		cout << "Enter a positive integer to sum to or type '0' to quit: ";
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

		// Line-oriented input
		istringstream in(input);
		int num;
		in >> num;

		// Error checking
		if (!in)
		{
			cout << "This program only accepts positive integers." << endl;
			continue;
		}

		if (num < 0)
		{
			cout << "This program only accepts positive integers." << endl;
			continue;
		}
		
		if (num > 1000363)
		{
			cout << "No integer overflow for you!" << endl;
			continue;
		}

		// Quit
		if (num == 0)
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		// Sum loop
		int sum = 0;
		for (int i = 1; i <= num; ++i)
		{
			sum += i;
		}
		cout << "The sum of 1 through " << num << " is: " << sum << endl;
	}
	
}