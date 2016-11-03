// dateprint.cpp
// Corey Gray
// 02 Nov 2016
// CS 201 Assignment 6: Converts a mm/dd/yyyy date

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;

int main()
{
	while (true)
	{

		cout << "Enter a date in the format MM/DD/YYYY including leading zeroes or an empty line to quit: ";

		string input;
		getline(cin, input);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			continue;
		}

		// Quit
		if (input.empty())
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		if (input.size() != 10)
		{
			cout << "This date is the wrong size. There are ten characters in the MM/DD/YYYY format." << endl;
			continue;
		}

		// Format checking
		if ((input[0] < '0' || input[0] > '1') ||
			(input[1] < '1' || input[1] > '9') ||
			input[2] != '/' ||
			(input[3] < '0' || input[3] > '3') ||
			(input[4] < '0' || input[4] > '9') ||
			input[5] != '/' ||
			(input[6] < '0' || input[6] > '9') || // Technically, the year 3,000-something or higher is possible
			(input[7] < '0' || input[7] > '9') ||
			(input[8] < '0' || input[8] > '9') ||
			(input[9] < '0' || input[9] > '9'))
		{
			cout << "Date must be in the MM/DD/YYYY format with valid month, day, and year." << endl;
			continue;
		}



		string mm = input.substr(0, 2);
		string dd = input.substr(3, 2);
		string yyyy = input.substr(6, 4);

		// Month conversion
		if (mm == "01")
			mm = "January";
		if (mm == "02")
			mm = "February";
		if (mm == "03")
			mm = "March";
		if (mm == "04")
			mm = "April";
		if (mm == "05")
			mm = "May";
		if (mm == "06")
			mm = "June";
		if (mm == "07")
			mm = "July";
		if (mm == "08")
			mm = "August";
		if (mm == "09")
			mm = "September";
		if (mm == "10")
			mm = "October";
		if (mm == "11")
			mm = "November";
		if (mm == "12")
			mm = "December";

		// Concatenate
		string date = mm + " " + dd + ", " + yyyy;
		cout << "Converted date: " << date << endl;
		cout << endl;
	}
	
}