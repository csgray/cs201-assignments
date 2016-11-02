// printprimes.cpp
// Corey Gray
// 26 Sep 2016
// CS 201 Assignment 3: Stores a list of all the prime numbers from 1 through 100 in a file

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
#include <fstream>
using std::ofstream;

bool isPrime(int num)
{
	for (int i = 2; i < num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		} 
	}
	return true;
}

int main()
{
	// File opening
	string filename = "primes.txt";
	ofstream fileout;
	fileout.open(filename);

	// Error checking
	if (!fileout)
	{
		cout << "File open error!" << endl;
		cout << endl;

		// Quit when user hits Enter
		cout << "Press ENTER to quit.";
		while (cin.get() != '\n');
		return 0;
	}
	
	cout << "Generating list of primes..." << endl;

	// Writing list of primes
	fileout << "Here is a list of all the prime numbers between 1 and 100: " << endl;
	for (int i = 2; i <= 100; ++i)
	{
		if (isPrime(i))
		{
			fileout << i << endl;
		}
		
		// Error checking
		if (!fileout)
		{
			cout << "File write error!" << endl;
			cout << endl;

			// Quit when user hits Enter
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');
			return 0;
		}
	}

	cout << "List complete. Look for " << filename << " in project directory." << endl;
}