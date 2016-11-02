// assoc.cpp
// Corey Gray
// 10 Oct 2016
// CS 201 Assignment 4: CRUD an associative dataset

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;

// Input
int input(string prompt)
{
	while (true)
	{
		cout << prompt;
		string line;
		getline(cin, line);

		// Error checking
		if (!cin)
		{
			cout << "Input error." << endl;
			while (cin.get() != '\n');

			return 0;
		}

		// Line-oriented input
		istringstream in(line);
		int num;
		in >> num;

		// Error checking
		if (!in)
		{
			cout << "This program only accepts positive integers." << endl;
			cout << endl;
			continue;
		}

		if (num < 1)
		{
			cout << "This program only accepts positive integers." << endl;
			cout << endl;
			continue;
		}

		return num;
	}

}

// Create and Update
void set(vector<int> &keys, vector<int> &values)
{
	int key = input("Enter a positive integer for the key: ");
	int value = input("Enter a positive integer for the associated value: ");

	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		if (key == keys[i])
		{
			cout << endl;
			cout << "Updating value." << endl;
			cout << endl;

			values[i] = value;
			return;
		}
	}

	cout << endl;
	cout << "Setting value." << endl;
	cout << endl;

	keys.push_back(key);
	values.push_back(value);
}

// Read
void view(vector<int> &keys, vector<int> &values)
{
	int key = input("Enter a positive integer for the key: ");

	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		if (key == keys[i])
		{
			cout << "The value associated with key " << key << " is: " << values[i] << endl;
			cout << endl;
			return;
		}
	}

	cout << "There is no key " << key << ". You will need to set it first." << endl;
	cout << endl;
}

// Delete
void del(vector<int> &keys, vector<int> &values)
{
	int key = input("Enter a positive integer for the key: ");

	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		if (key == keys[i])
		{
			keys.erase(keys.begin() + i);
			values.erase(values.begin() + i);
			cout << "Key " << key << " and its value have been deleted." << endl;
			cout << endl;
			return;
		}
	}

	cout << "There is no key " << key << " to delete." << endl;
	cout << endl;
}

int main()
{
	vector<int> keys;
	vector<int> values;

	cout << "This program creates an associative dataset of key-value pairs." << endl;

	while (true)
	{
		// Menu
		cout << "Select one of the options below by inputing its number." << endl;
		cout << endl;
		cout << "1. Set the value associated with a key." << endl;
		cout << "2. View the value associated with a key." << endl;
		cout << "3. Delete a key-value pair." << endl;
		cout << "4. Quit." << endl;
		cout << endl;

		int choice = input("Choice: ");

		// Create and Update
		if (choice == 1)
			set(keys, values);

		// Read
		if (choice == 2)
			view(keys, values);

		// Delete
		if (choice == 3)
			del(keys, values);

		// Quit
		if (choice == 4)
		{
			cout << "Goodbye." << endl;
			return 0;
		}

		// Invalid choice
		if (choice > 4)
		{
			cout << "That is not a valid option." << endl;
			cout << endl;
			continue;
		}

		// Error catching
		else
			continue;
	}
}