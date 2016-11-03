// words.cpp
// Corey Gray
// 02 Nov 2016
// CS 201 Assignment 6: Separates a CamelCase string and reprints it

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

int main()
{
	cout << "Enter a sentence consisting of one long word with no spaces but the first character of each word capitalized:" << endl;

	string input;
	getline(cin, input);

	// Error checking
	if (!cin)
	{
		cout << "That was not valid input." << endl;
		return 0;
	}

	for (unsigned int i = 1; i < input.size(); ++i)
	{
		if (input[i] == ' ')
		{
			cout << "No spaces." << endl;
			return 0;
		}
	}

	string output;

	// Convert first character to uppercase if lowercase then concatenate
	if (input[0] >= 'a' && input[0] <= 'z')
	{
		input[0] = input[0] - 32;
		output += input[0];
	}

	// Concatenate if not
	else
		output += input[0];

	// Convert and concatenate the rest of the string
	for (unsigned int i = 1; i < input.size(); ++i)
	{
		if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] = input[i] + 32;
			output += " ";
			output += input[i];
		}

		else
			output += input[i];
	}

	cout << "Converted sentence: " << endl;
	cout << output << endl;
}