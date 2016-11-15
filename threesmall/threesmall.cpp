// threesmall.cpp
// Corey Gray
// 14 Nov 2016
// CS 201 Assignment 7: Receives multiple integers from the user and prints the three smallest

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

int main()
{
	cout << "This program receives a series of integers from the user then prints the three smallest ones." << endl;
	
	while (true)
	{
		vector<int> values;
		
		cout << "Type an integer (empty line or non-integer to quit program): ";
		string line;
		getline(cin, line);

		// Error checking
		if (!cin)
		{
			cout << "Input error." << endl;
			return 0;
		}

		// Line-oriented input
		istringstream in(line);
		int num;
		in >> num;

		// Quit
		if (!in)
		{
			cout << endl <<  "Bye!" << endl;
			return 0;
		}

		else
		{
			while (true)
			{
				values.push_back(num);
				sort(values.begin(), values.end());

				cout << "Type an integer (empty line or non-integer to end input): ";
				getline(cin, line);

				// Error checking
				if (!cin)
				{
					cout << "Input error." << endl;
					return 0;
				}

				// Line-oriented input
				istringstream in(line);
				in >> num;

				// End input
				if (!in)
				{
					if (values.size() < 3)
					{
						cout << endl << "Values typed: ";

						for (unsigned int i = 0; i < values.size(); ++i)
						{
							cout << values[i] << " ";
						}

						cout << endl << endl;
						break;
					}

					else
					{
						cout << endl << "Three smallest values typed: ";
						
						for (int i = 0; i < 3; ++i)
						{
							cout << values[i] << " ";
						}

						cout << endl << endl;
						break;
					}
				}
			}
		}
	}
}