// printprimes.cpp
// Corey Gray
// 10 Oct 2016
// CS 201 Assignment 4: Reads lines.txt then prints the lines in alphabetical order

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;

// Alphabetizes the strings based on ASCII order
void alphabetize(vector<string> &lines)
{
	for (int top = lines.size(); top >= 2; --top)
	{
		for (int high = 0; high + 1 < top; ++high)
		{
			int low = high + 1;
			string line1 = lines[high];
			string line2 = lines[low];
			
			for (unsigned int i = 0; i < line1.size(); ++i)
			{
				// Checks for same [i] character
				if (line1[i] == line2[i])
				{
					continue;
				}

				// Checks for line1 being a non-alphabet character while line2 is an alphabet character
				// TODO: Make this iterate more
				if ((line1[i] < 'A' || (line1[i] > 'Z' && line1[i] < 'a') || line1[i] > 'z') &&
					((line2[i] >= 'A' && line2[i] <= 'Z') || (line2[i] >= 'a' && line2[i] <= 'z')))
				{
					int num1 = line1[i];
					int num2 = line2[i];
					cout << "1: " << line1[i] << " " << num1 << endl;
					cout << "2: " << line2[i] << " " << num2 << endl;
					string swap = lines[low];
					lines[low] = lines[high];
					lines[high] = swap;
					break;
				}

				// Sorts characters by ASCII values
				if (line1[i] > line2[i])
				{
					string swap = lines[high];
					lines[high] = lines[low];
					lines[low] = swap;
					break;
				}

				// Prevents items that are in order from running continuously
				else
					break;
			}
		}
	}
}

int main()
{	
	string filename = "lines.txt";
	cout << "This program reads " << filename << " to a vector, alphabetizes its lines, then prints them." << endl;

	// File opening
	ifstream input;
	input.open(filename);

	// Error checking
	if (!input)
	{
		cout << "File read error!" << endl;
		return 0;
	}

	// Read file lines to vector
	vector<string> lines;
	string line;
	while (getline(input, line))
	{
		if (!line.empty())
			lines.push_back(line);
	}

	// Alphabetize
	alphabetize(lines);

	// Print
	cout << "Results:" << endl;
	for (unsigned int i = 0; i < lines.size(); ++i)
	{
		cout << lines[i] << endl;
	}
}