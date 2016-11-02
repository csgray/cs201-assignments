// collatzfile.cpp
// Corey Gray
// 25 Oct 2016
// CS 201 Assignment 5: Writes a series of Collatz sequences to cseqs.txt

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ofstream;

// Collatz sequence
void collatz(int seq, ofstream & file)
{
	while (seq)
	{
		if (seq == 1)
		{
			file << seq << endl;
			if (!file)
			{
				cout << "File write error!" << endl;
				exit(1); // Can't return 0 in a void function, so exit!
			}
			break;
		}
		if ((seq % 2) == 1)
		{
			file << seq << ", ";
			if (!file)
			{
				cout << "File write error!" << endl;
				exit(1);
			}
			seq = 3 * seq + 1;
		}
		if ((seq % 2) == 0)
		{
			file << seq << ", ";
			if (!file)
			{
				cout << "File write error!" << endl;
				exit(1);
			}
			seq = seq / 2;
		}
	}
}

int main()
{
	// File opening
	string filename = "cseqs.txt";
	ofstream fileout;
	fileout.open(filename);

	// Error checking
	if (!fileout)
	{
		cout << "File open error!" << endl;
		return 0;
	}

	// Prompt
	cout << "This program writes a series of Collatz sequences to " << filename << " starting and ending with integers that you provide." << endl;
	cout << "Each integer must be positive, and the second integer must be greater than or equal to the first." << endl;
	
	// Input A
	int a;
	while (true)
	{
		cout << "Enter the first integer or a blank line to quit: ";

		string inputA;
		getline(cin, inputA);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			return 0;
		}

		// User quit
		if (inputA == "")
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		istringstream inA(inputA);
		inA >> a;

		// User-error checking
		if (!inA)
		{
			cout << "The first integer must actually be an integer." << endl;
			continue;
		}

		if (a <= 0)
		{
			cout << "The first integer must be positive." << endl;
			continue;
		}

		else
			break;
	}

	// Input B
	int b;
	while (true)
	{
		cout << "Enter the second integer or a blank line to quit: ";

		string inputB;
		getline(cin, inputB);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			exit(1);
		}

		// User quit
		if (inputB == "")
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		istringstream inB(inputB);
		inB >> b;

		// User-error checking
		if (!inB)
		{
			cout << "The second integer must actually be an integer." << endl;
			continue;
		}

		if (b <= 0)
		{
			cout << "The second integer must be positive." << endl;
			continue;
		}

		if (b < a)
		{
			cout << "The second integer must be greater than or equal to the first." << endl;
			continue;
		}

		else
			break;
	}

	// Write Collatz sequences to file
	for (int i = a; i <= b; ++i)
	{
		collatz(i, fileout);
	}

	cout << "Output to file " << filename << " complete." << endl;
}