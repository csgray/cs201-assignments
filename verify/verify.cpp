// verify.cpp
// Corey Gray
// 02 Nov 2016
// CS 201 Assignment 6: Verify a user's "password"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

int main()
{
	cout << "Your password must have the following characteristics:" << endl;
	cout << "It must be at least six character longs." << endl;
	cout << "It must contain at least one uppercase and at lease one lowercase letter." << endl;
	cout << "It must have at least one digit." << endl;
	cout << endl;

	while (true)
	{
		cout << "Please enter your password: ";

		string input;
		getline(cin, input);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			return 0;
		}

		// Parameters
		int size = input.size();
		int minsize = 6;
		bool uppercase = false;
		bool lowercase = false;
		bool digit = false;

		// Length check
		if (size < minsize)
		{
			cout << "Your password must be at least six characters long." << endl;
			continue;
		}

		// Uppercase letter check
		for (int i = 0; i < size; ++i)
		{
			if (input[i] >= 'A' && input[i] <= 'Z')
			{
				uppercase = true;
				break;
			}
		}

		if (uppercase == false)
		{
			cout << "Your password must contain at least one uppercase letter." << endl;
			continue;
		}

		// Lowercase letter check
		for (int i = 0; i < size; ++i)
		{
			if (input[i] >= 'a' && input[i] <= 'z')
			{
				lowercase = true;
				break;
			}
		}

		if (lowercase == false)
		{
			cout << "Your password must contain at least one lowercase letter." << endl;
			continue;
		}

		// Digit check
		for (int i = 0; i < size; ++i)
		{
			if (input[i] >= '0' && input[i] <= '9')
			{
				digit = true;
				break;
			}
		}

		if (digit == false)
		{
			cout << "Your password must contain at least one digit." << endl;
			continue;
		}
		
		cout << "Password accepted." << endl;
		return 0;
	}
}