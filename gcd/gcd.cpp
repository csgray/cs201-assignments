// gcd.cpp
// Corey Gray
// 9 Oct 2016
// CS 201 Assignment 4: Prints the greatest common denominator of two nonnegative integers input by the user.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;

// Finds the greatest common denominator
int euclid(int a, int b)
{
	int remainder;
	
	while (true)
	{
		if (a == 0)
			return b;

		remainder = b % a;
		b = a;
		a = remainder;
	}
}

// Converts user's input and performs error-checking
int input(string line)
{
	// Line-oriented input
	istringstream in(line);
	int num;
	in >> num;

	// Error checking
	if (!in)
	{
		cout << "This program only accepts positive integers." << endl;
		cout << endl;
		return -1;
	}

	if (num < 0)
	{
		cout << "This program only accepts positive integers." << endl;
		cout << endl;
		return -1;
	}

	// Quit
	if (num == 0)
	{
		cout << "Goodbye." << endl;
		return 0;
	}

	return num;
}

int main()
{
	cout << "This program finds the Great Common Denominator of two nonnegative integers." << endl;
	
	while (true)
	{
		// Prompt
		cout << "Type the first nonnegative integer or 0 to quit: ";
		string lineA;
		getline(cin, lineA);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		int a;
		a = input(lineA);

		if (a == -1)
			continue;
		if (a == 0)
			break;

		// Prompt
		cout << "Type the second nonnegative integer or 0 to quit: ";
		string lineB;
		getline(cin, lineB);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		int b;
		b = input(lineB);
		
		if (b == -1)
			continue;
		if (b == 0)
			break;

		int gcd;
		gcd = euclid(a, b);

		cout << "The greatest common denominator of " << a << " and " << b << " is: " << gcd << endl;
		cout << endl;
	}
}