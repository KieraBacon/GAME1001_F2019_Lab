/*
Implement a C++ console application that simulates a Rock - Paper - Scissor game against 
the computer. When played between two people, each person picks one of three options
(usually shown by hand gesture) at the same time, and a winner is determined. In the
game, Rock beats Scissors, Scissors beats Paper, and Paper beats Rock. The program
should randomly choose one of the three options (without revealing it), then ask for user
input (choice of Rock, Paper or Scissor), and finally compare with user’s choice. At that
point, the program reveals both choices and prints a statement indicating if the user won,
the computer won, or it was a tie. Application should keep track of the current score (i.e.
the number of user wins, losses, and ties) and update the screen after every play. User
should be prompted after every game if they want to continue playing. At the beginning
of the game the program should also ask the user for their name and display this name
when showing the score.

You do not need to use any user - defined functions for this assignment but you can add
whatever you like so long as the criteria at the end of this document has been met. No
bonus marks will be given, however.

In addition to the requirements above, as part of this assignment you are to implement
storing of game data into a text file. Game should always ask for a username (it has to be
at least 8 characters) and store game results in a file with the same name as the username
(username.txt). If the user has played the game before, the data should be read from the
file and displayed on screen before starting a new game.At the end of the game the
statistics should be saved on the same file.

Game should not allow for same usernames unless it is the same user. This means that the
game should check for existing usernames and prompt the new user for further
authentication if needed. This would also guarantee that every user will have a unique
game data statistics stored and not overridden by another user with the same username.
You can do this assignment individually or in pairs. Plagiarism penalties will apply so do
NOT copy code from the Internet or other sources aside from in - class labs or exercises.

Marks : 10 % of course grade
Game AI 30: Game logic and choosing the right winner works properly. Maximum marks will be awarded for simple and efficient code.
UI: 15 Interaction with the user is seamless and well planned. Game Results 15 Properly keeping track of the score and updating the player.
Data Persistence 20: Storing and retrieving game data.
Code documentation and convention: 20 Follow proper documentation of your code and best coding practices and conventions discussed in class.
Total : 100
Submission : Filenames : GAME1001_A1_Lastname1_Lastname2.cpp
*/
/*
Assignment plan:
Logging in:
	New Profile	> Ask for username and password
				> Save credentials to file
	Log in		> Open file > return if unable
				> Check credentials > return if invalid
Open file, compare credentials
Making a guess: 
Comparing guesses: 
Continue prompt: 
*/

#include <iostream>					// Used for all input and output to the console and data file.
#include <ctime>					// Used for randomization.
//#include <cctype>					//
#include <string>					// Used for all user input.
#include <fstream>					// Used for reading and writing user validation.
#include <Windows.h>				// Used for Sleep() and textColour().

using namespace std;

// Enumeration for the data type of all user input.
enum rps { rock, paper, scissors};

// Function to set the colour of a given piece of text.
void textColour(int colour, string text)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(screen, colour);
	cout << text;
	SetConsoleTextAttribute(screen, 7);
}

// Function to validated a given string input and convert it into an enumerated RPS output.
rps rpsInput(string init, string invalid)
{											// General function for checking input validation and converting it to the game's language.
	bool valid = false;						// Validation flag.
	string input;
	rps output;
	do										// Check for input validation, only exit when validation flag is true.
	{
		cout << init;
		cin >> input;
		cin.ignore(INT_MAX, '\n');
		if (input == "1" || input == "ROCK" || input == "Rock" || input == "rock" || input == "R" || input == "r")
		{
			output = rock;
			valid = true;
		}
		else if (input == "2" || input == "PAPER" || input == "Paper" || input == "paper" || input == "P" || input == "p")
		{
			output = paper;
			valid = true;
		}
		else if (input == "3" || input == "SCISSORS" || input == "Scissors" || input == "scissors" || input == "S" || input == "s")
		{
			output = scissors;
			valid = true;
		}
		else { cout << invalid; }
	} while (!valid);
	return output;
}

// Function to locate whether a given username string exists in the data file,
// and return the corresponding password if one is requested
bool findID(string searchID, string* checkPW = NULL)
{
	string checkID;
	bool foundID = false;
	ifstream inFile("HighlySecureUserData.txt");
	if (!inFile.is_open())
	{
		cerr << "Error opening file." << endl;
		system("pause");
		return 1;
	}
	while (!inFile.eof())
	{
		!checkPW ? inFile >> checkID : inFile >> checkID >> *checkPW;
		//*playerName = searchID;
		if (searchID == checkID)
		{
			foundID = true;
			break;
		}
	}
	inFile.close();
	if (foundID) return true;
	else return false;
}

// Function to create a new user profile.
// It begins by checking if a username already exists using findID().
short newProfile(string* playerName)
{
	bool newUser = false;
	string searchID, checkID, newPW;
	cout << "Create a new profile." << endl << endl;
	do
	{
		cout << "Enter your username: ";
		cin >> searchID;
		cin.ignore(INT_MAX, '\n');
		newUser = !findID(searchID);
		if (!newUser)
		{
			Sleep(400);
			cout << "Username \"" << searchID << "\" already in database. Please try something else." << endl;
		}
		else
		{
			ofstream outFile("HighlySecureUserData.txt", ios::app);
			if (!outFile.is_open())
			{
				cerr << "Error opening file." << endl;
				system("pause");
				return 1;
			}
			bool valid = false;
			do
			{					// IN NEED OF INPUT VALIDATION!! WHAT CAN THER USER ENTER HERE?
				cout << "Enter your Password: ";
				cin >> newPW;
				cin.ignore(INT_MAX, '\n');
				valid = true;
			} while (!valid);
			cout << "Saving user \"" << searchID << "\" with password \"" << newPW << "\" to file..." << endl;
			outFile << endl << searchID << ' ' << newPW << endl;
			outFile.close();
			*playerName = searchID;
		}
	} while (!newUser);
	return 0;
}

// Function to log in to an existing user profile, making use of findID().
short logIn(string* playerName)
{
	bool matchUser = false;
	string searchID, searchPW, checkID, checkPW;
	cout << "Log in to an existing profile." << endl << endl;
	do
	{
		bool foundID = false;
		cout << "Enter your username: ";
		cin >> searchID;
		cin.ignore(INT_MAX, '\n');
		foundID = findID(searchID, &checkPW);
		if (foundID)
		{
			Sleep(400);
			cout << "Matching username found. Enter your password: ";
			cin >> searchPW;
			cin.ignore(INT_MAX, '\n');
			if (searchPW == checkPW)
			{
				Sleep(400);
				cout << "Logging in..." << endl;
				Sleep(800);
				*playerName = checkID;
				matchUser = true;
			}
			else
			{
				Sleep(400);
				cout << "Password incorrect. Please try again." << endl;
			}
		}
		else
		{
			Sleep(400);
			cout << "User not found. Please try again." << endl;
		}
	} while (!matchUser);
	return 0;
}

/*---- I M P O R T A N T   T A S K S   R E M A I N I N G   T O   D O -------
---------------------------TASKS REMAINING TO DO!---------------------------
[1] ADD input validation to checking and saving of passwords and usernames
----> There should be limits on character types and lengths at least
[2] ADD core functionality of game loop.
[3] ADD full commenting throughout the file for marks and shit.
[4] CNG Menus in separate functions for readability and happiness and rainbows. 
---------------------------TASKS REAMINING TO DO-------------------------*/


// Main entry point function.
int main()
{
	rps input;
	string playerName;

	cout << "GAME1001_A1_BaconKiera" << endl;
	cout << "Rock, Paper, Scissors" << endl;
	cout << "Initializing..." << endl;
	Sleep(400); cout << endl;
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "In this game, you win by guessing your opponent's choice." << endl;
	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
	Sleep(800); cout << endl;
	cout << "First thing, are you a new or returning player?" << endl;
	cout << "[1]"; textColour(3, "ROCK"); cout << "> Log in to an existing profile" << endl;
	cout << "[2]"; textColour(2, "PAPER"); cout << "> Create a new profile" << endl;
	cout << "[3]"; textColour(4, "SCISSORS"); cout << "> Exit the game" << endl;
	cout << endl;
	input = rpsInput("Enter your selection: ","Invalid input. Please try again: ");
	cout << endl;
	switch (input)
	{
	case 0:
		logIn(&playerName);
		break;
	case 1:
		newProfile(&playerName);
		break;
	case 2:
		cout << "Sorry to see you go!" << endl << endl;
		system("pause");
		return 0;
	default: 
		cout << "There was an error in choosing the menu item." << endl << endl;
		system("pause");
		return 1;
	}

	system("pause");
	return 0;
}