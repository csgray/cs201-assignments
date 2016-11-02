// spaceroot.cpp
// Corey Gray
// 25 Oct 2016
// CS 201 Assignment 5: Receives an integer from a user then prints its square root to exactly eight decimal places with spaces

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <cmath>
using std::sqrt;


int main()
{
	cout << "This program receives a nonnegative integer then provides the square root." << endl;
	cout << "There will be eight digits after the decimal point and a space between each character." << endl;

	while (true)
	{
		cout << "Enter a nonnegative integer or a blank line to quit: ";

		string input;
		getline(cin, input);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			return 0;
		}

		// User quit
		if (input == "")
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		double number;
		istringstream in(input);
		in >> number;

		// User-error checking
		if (!in)
		{
			cout << "The integer must actually be an integer." << endl;
			continue;
		}

		if (number < 0)
		{
			cout << "The integer must be nonnegative." << endl;
			continue;
		}

		// Square root out to eight digits after the decimal
		double root = sqrt (number);
		ostringstream output;
		output << fixed << setprecision(8) << root;
		string spaced = output.str();

		// Inserts spaces
		for (string::size_type i = 1; i < spaced.size(); i+=2)
		{
			spaced.insert(i, " ");
		}

		cout << "Spaced-out square root: " << spaced << endl;

	}
}