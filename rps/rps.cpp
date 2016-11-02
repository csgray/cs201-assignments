// rps.cpp
// Corey Gray
// 26 Sep 2016
// CS 201 Assignment 3: Plays Rock-Paper-Scissors with the user.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <random>

// random_int from dierolls.cpp by Glenn G. Chappell
// Given integers a and b, with a <= b. Returns a random integer in the
// range [a, b]. Should generate different values each time the program
// is executed.
int random_int(int a,  // Minimum value for returned random number
	int b)  // Maximum value for returned random number
{
		// Construct a random-number generator object -- static, so it stays
		// around -- and seed it nondeterministically.
		static std::mt19937 rng((std::random_device())());
		// Generate a random number in the given range, using our
		// random-number generator. Then return the number.
		return std::uniform_int_distribution<int>(a, b)(rng);
}

// Receives input from the user and converts it to an integer
void choice(string input, int &user)
{
	if (input == "quit")
		user = 0;
	if (input == "rock")
		user = 1;
	if (input == "paper")
		user = 2;
	if (input == "scissors")
		user = 3;
}

// Generates a random number, assigns it, and tells the user what the computer chose
void compChoice(int &computer)
{
	int random = random_int(1, 3);
	if (random == 1)
	{
		computer = 1;
		cout << "I chose rock!" << endl;
	}
	if (random == 2)
	{
		computer = 2;
		cout << "I chose paper!" << endl;
	}
	if (random == 3)
	{
		computer = 3;
		cout << "I chose scissors!" << endl;
	}
}

// Compares the user's and computer's choices then announces the winner
void rps(int user, int computer)
{
	if (user == 1 && computer == 1) // User chose rock and computer chose rock
	{
		cout << "It's a tie! Let's play again." << endl;
		cout << endl;
	}
	if (user == 1 && computer == 2) // User chose rock and computer chose paper
	{
		cout << "Paper wraps rock! I win!" << endl;
		cout << endl;
	}
	if (user == 1 && computer == 3) // User chose rock and computer chose scissors
	{
		cout << "Rock smashes scissors! You win!" << endl;
		cout << endl;
	}
	if (user == 2 && computer == 1) // User chose paper and computer chose rock
	{
		cout << "Paper wraps rock! You win!" << endl;
		cout << endl;
	}
	if (user == 2 && computer == 2) // User chose paper and computer chose paper
	{
		cout << "It's a tie! Let's play again." << endl;
		cout << endl;
	}
	if (user == 2 && computer == 3) // User chose paper and computer chose scissors
	{
		cout << "Scissors cut paper! I win!" << endl;
		cout << endl;
	}
	if (user == 3 && computer == 1) // User chose scissors and computer chose rock
	{
		cout << "Rock smashes scissors! I win!" << endl;
		cout << endl;
	}
	if (user == 3 && computer == 2) // User chose scissors and computer chose paper
	{
		cout << "Scissors cut paper! You win!" << endl;
		cout << endl;
	}
	if (user == 3 && computer == 3) // User chose scissors and computer chose scissors
	{
		cout << "It's a tie! Let's play again." << endl;
		cout << endl;
	}
}

int main()
{
	// Intro
	cout << "Let's play a game: Rock-Paper-Scissors!" << endl;
	while (true)
	{
		// Prompt
		cout << "Enter either 'rock', 'paper', 'scissors', or 'quit': ";
		string input;
		getline(cin, input);

		// Error checking
		if (!cin)
		{
			cout << "That was not valid input." << endl;
			cout << "Press ENTER to quit.";
			while (cin.get() != '\n');

			return 0;
		}

		if (input != "rock" &&
			input != "paper" &&
			input != "scissors" &&
			input != "quit")
		{
			cout << "You can only enter 'rock', 'paper', 'scissors', or 'quit' without the quotes." << endl;
			cout << endl;
			continue;
		}

		// Input processing
		int user;
		choice(input, user);
		if (user == 0)
		{
			cout << "Goodbye!" << endl;
			return 0;
		}

		// Computer chooses
		int computer;
		compChoice(computer);

		// Rock-Paper-Scissors
		rps(user, computer);
	}
}

