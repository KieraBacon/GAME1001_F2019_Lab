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

/*-----------------------------Compiler Directives and Global Variables.----------------------------*/
#include <iostream>					// Used for all input and output to the console and data file.
#include <ctime>					// Used for randomization.
#include <string>					// Used for all user input.
#include <fstream>					// Used for reading and writing user validation.
#include <Windows.h>				// Used for Sleep() and textCol().
using namespace std;

/*-------------------------Enumeration for the data type of all user input.-------------------------*/
enum rps { rock, paper, scissors, cross };

/*------------------------------Set the colour of a given piece of text.----------------------------*/
void textCol(int colour, string text)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);	// Sets the screen handle.
	SetConsoleTextAttribute(screen, colour);			// Sets the text colour attribute to the passed in integer.
	cout << text;										// Prints the passed in text.
	SetConsoleTextAttribute(screen, 7);					// Resets the text colour attribute for the program to resume normally.
}

/*------------Validate a given string input and convert it into an enumerated RPS output.-----------*/
rps rpsInput(string init = "Enter your selection: ", string invalid = "Invalid input, please try again: ")
{											// General function for checking input validation and converting it to the game's language.
	bool valid = false;						// Validation flag.
	string input;
	rps output;
	do										// Check for input validation, only exit when validation flag is true.
	{
		cout << init;						// Prints the introduction text for whatever is requesting the input.
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
		else if (input == "4" || input == "0" || input == "CROSS" || input == "Cross" || input == "cross" || input == "X" || input == "x" || input == "C" || input == "c")
		{
			output = cross;
			valid = true;
		}
		else { cout << invalid; }			// If the validation flag is not set to true in any of the above cases, the result is invalid,
	} while (!valid);						// and the loop has to start again.
	return output;							// returns one of the four possible values to the calling function.
}

/*-----------------Validate a new string input for username or password conditions.-----------------*/
string textInput(string firstPrompt = "Enter your input [3-10 characters]: ", string secondPrompt = "Invalid input, please try again: ")
{
	string input;
	bool valid = false;								// Validation flag for verifying valid text input.
	cout << firstPrompt;							// Prints the prompt text supplied by the calling function.
	do												// Continues to loop until a valid input is entered.
	{
		cin >> input;
		cin.ignore(INT_MAX, '\n');
		if (input.length() >= 3 && input.length() <= 10) // Checks input text meets conditions.
		{
			valid = true;
		}
		else
		{
			cout << secondPrompt;					// If user input is invalid, prints error text supplied by calling function.
		}
	} while (!valid);
	return input;
}

/*---------Locate a given username in the data file and return its corresponding password.----------*/
short findID(string searchID, string* checkPW = NULL)
{
	string checkID;									// String for the username which is read from the file.
	bool foundID = false;							// Checks whether the function found what it was looking for, becomes true if so.
	ifstream inFile("HighlySecureUserData.txt");	// Opens the data file for reading.
	if (!inFile.is_open())							// Checks if the file opened successfully, and exits the program if it didn't.
	{
		cerr << "Error opening file." << endl;
		system("pause");
		return -3;
	}
	while (!inFile.eof())							// Loops through the data file until it finds the string that was passed into the function.
	{
		!checkPW ? inFile >> checkID : inFile >> checkID >> *checkPW;
		if (searchID == checkID)					// If it matches the username read from the file with the username input from the user, it breaks the loop.
		{
			foundID = true;
			break;
		}
	}
	inFile.close();									// The file must be closed before the function terminates.
	if (foundID) return 1;
	else return 0;
}

/*----------------Create a new user profile if a matching one does not already exist.---------------*/
short newProfile(string &playerName)
{
	bool newUser = false;							// Flag which states whether or not the username checked is new.
	string searchID, checkID, newPW;
	system("CLS");									// Clears the screen for aesthetic purposes.
	cout << "Create a new profile." << endl << endl;
	do												// Continues to loop until a new profile has been successfully created.
	{
		searchID = textInput("Enter your username [3-10 characters]: ", "Invalid username, please try again: ");	// Calls textInput() to validate username input.
		switch (findID(searchID))					// Calls findID() to check if the inputted username exists.
		{
		case 0: newUser = true; break;
		case -3: return -3;
		default: break;
		}
		if (!newUser)								// If the username already exists, it can't proceed.
		{
			Sleep(400);
			cout << "Username \"" << searchID << "\" already in database. Please try something else." << endl;
		}
		else										// If the username is new, it can go on to the next step.
		{
			ofstream outFile("HighlySecureUserData.txt", ios::app);	// Opens the data file for writing.
			if (!outFile.is_open())					// Checks if the file opened successfully, and exits the program if it didn't.
			{
				cerr << "Error opening file." << endl;
				system("pause");
				return -3;
			}
			bool valid = false;						// Validation flag for password input.
			newPW = textInput("Enter your password [3-10 characters]: ", "Invalid password, please try again: ");	// Calls textInput() to validate password input.
			cout << endl << "Saving user \"" << searchID << "\" with password \"" << newPW << "\" to file..." << endl;
			outFile << endl << searchID << ' ' << newPW;	// Outputs the data to the data file.
			outFile.close();						// The data file must be closed before the function terminates.
			playerName = searchID;					// Finally, saves the player's name as the new name which was entered.
		}
	} while (!newUser);								// Continues to loop until a new user profile has been successfully created.
	return 0;
}

/*-------------------------------Log in to an existing user profile.--------------------------------*/
short logIn(string &playerName)
{
	bool matchUser = false;							// Flag which states whether or not the username checked matches one in the data file.
	string searchID, searchPW, checkPW;
	system("CLS");								// Clears the screen for aethetic purposes.
	cout << "Log in to an existing profile." << endl << endl;
	do												// Continues to loop until the player has successfully logged in.
	{
		short foundID = 0;							// Flag to verify wheather a previously existing ID was found.
		searchID = textInput("Enter your username: ", "Invalid username, please try again: ");
		foundID = findID(searchID, &checkPW);		// Calls findID() to check the inputted username, and if found, saves the associated password.
		if(foundID == -3)							// If the datafile failed the open, the error should cascade back.
		{
			return -3;
		}
		else if (foundID == 1)						// If the username was found, enters a short sequence to determined if the password matches.
		{
			Sleep(400);
			searchPW = textInput("Matching username found. Enter your password: ", "Invalid password, please try again: ");
			if (searchPW == checkPW)				// If the password entered matches the one previously saved from the data file, begin exiting the loop.
			{
				Sleep(400);
				cout << endl;
				cout << "Logging in..." << endl;
				Sleep(800);
				playerName = searchID;				// Sets the player's name to the saved username from the data file.
				matchUser = true;					// Sets the flag to allow the loop to exit.
			}
			else									// If the password doesn't match, allows the loop to reset back to the start with inputting the username. 
			{
				Sleep(400);
				cout << "Password incorrect. Please try again." << endl << endl;
			}
		}
		else										// If the username was not found, prompts the user the try again.
		{
			Sleep(400);
			cout << "User not found. Please try again." << endl << endl;
		}
	} while (!matchUser);							// Continues to loop until the player has successfully logged in.
	return 0;
}

/*---------------------------------Re-explain the rules on demand.----------------------------------*/
void printRules()
{
	cout << "Gameplay rules: " << endl;
	Sleep(200);
	cout << endl;
	cout << "Each round, select one of three options: [1]"; textCol(3, "ROCK"); cout << ", [2]"; textCol(2, "PAPER"); cout << ", or [3]"; textCol(4, "SCISSORS"); cout << "." << endl;
	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
	cout << "To win, guess how your opponent will play, and pick the one that beats it!" << endl;
	cout << endl;
	system("pause");
}

/*-----------------------------------------Roll the credits.----------------------------------------*/
void credits()
{
	cout << "Credits: " << endl;
	Sleep(200);
	cout << endl;
	cout << "Assignment 1: Rock, Paper, Scissors, by Kiera Bacon," << endl;
	cout << "with special thanks to Cloud for purring while she was working on it," << endl;
	cout << "and to Alex and Wallace at George Brown College for teaching her how to do it." << endl;
	cout << endl;
	system("pause");
}

/*-----------------------------------Display the current scores.------------------------------------*/
void scoreboard(string& playerName, int& pWin, int& pLos, int& pTie, int& pRoc, int& pPpr, int& pScr, int& cWin, int& cLos, int& cTie, int& cRoc, int& cPpr, int& cScr, short detail = 0)
{
	cout << "Current Score:" << endl;
	Sleep(200);
	cout << endl;
	cout << "Name: " << playerName << " Rounds: " << pWin+pLos+pTie << endl;
	cout << "Wins: " << pWin << " Losses: " << pLos << " Ties: " << pTie << endl;
	cout << "Rocks: " << pRoc << " Papers: " << pPpr << " Scissors: " << pScr << endl;
	cout << endl;
	cout << "Name: " << "Computer" << " Rounds: " << cWin + cLos + cTie << endl;
	cout << "Wins: " << cWin << " Losses: " << cLos << " Ties: " << cTie << endl;
	cout << "Rocks: " << cRoc << " Papers: " << cPpr << " Scissors: " << cScr << endl;
	cout << endl;
	system("pause");
}

/*-----------------------------------------Core game loop.------------------------------------------*/
short gameLoop(string& playerName, int& pWin, int& pLos, int& pTie, int& pRoc, int& pPpr, int& pScr, int& cWin, int& cLos, int& cTie, int& cRoc, int& cPpr, int& cScr)
{
	rps input;

	cout << endl; "Starting a new game...";
	Sleep(200);
	system("CLS");
	bool exitGame = false;								// Flag to check the game should still be running.
	do
	{
		rps cpuInput = static_cast<rps>(rand() % 3);	// The computer's guess is randomized at the start of each round.
		
		cout << "Round " << pWin+pLos+pTie << ": " << endl;	// Display the round number and input information at the start of each round.
		cout << "[1]"; textCol(3, "ROCK"); cout << " / ";
		cout << "[2]"; textCol(2, "PAPER"); cout << " / ";
		cout << "[3]"; textCol(4, "SCISSORS"); cout << " / ";
		cout << "[4]"; textCol(5, "CROSS"); cout << " (Return to the main menu)" << endl;
		
		string playerPrompt = playerName + ": ";		// Display the player's name when making a guess.
		input = rpsInput(playerPrompt);
		
		// Check each of the nine different potential outcomes and both print the result, and save it to a variable for later reference.
		Sleep(200);
		switch (cpuInput)
		{
		case 0: cout << "Computer: Rock" << endl; break;
		case 1: cout << "Computer: Paper" << endl; break;
		case 2: cout << "Computer: Scissors" << endl; break;
		}
		Sleep(300);
		if      (input == 0 && cpuInput == 0) { cout << "You both chose Rock. It's a tie!";             pTie++; pRoc++; cTie++; cRoc++; }
		else if (input == 0 && cpuInput == 1) { cout << "Your Rock loses to the computer's Paper!";     pLos++; pRoc++; cWin++; cPpr++; }
		else if (input == 0 && cpuInput == 2) { cout << "Your Rock beats the computer's Scissors!";     pWin++; pRoc++; cLos++; cScr++; }
		else if (input == 1 && cpuInput == 0) { cout << "Your Paper beats the computer's Rock!";        pWin++; pPpr++; cLos++; cRoc++; }
		else if (input == 1 && cpuInput == 1) { cout << "You both chose Paper. It's a tie!";            pTie++; pPpr++; cTie++; cPpr++; }
		else if (input == 1 && cpuInput == 2) { cout << "Your Paper loses to the computer's Scissors!"; pLos++; pPpr++; cWin++; cScr++; }
		else if (input == 2 && cpuInput == 0) { cout << "Your Scissors lose to the computer's Rock!";   pLos++; pScr++; cWin++; cRoc++; }
		else if (input == 2 && cpuInput == 1) { cout << "Your Scissors beat the computer's Paper!";     pWin++; pScr++; cLos++; cPpr++; }
		else if (input == 2 && cpuInput == 2) { cout << "You both chose Scissors. It's a tie!";         pTie++; pScr++; cTie++; cScr++; }
		else if (input == 3)							// Player can exit at any point.
		{
			cout << "Thank you for playing!" << endl;
			cout << "Your final score as " << playerName << " was: " << pWin - pLos << "." << endl;
			cout << "Wins: " << pWin << " Losses: " << pLos << " Ties: " << pTie << ". Rounds played: " << pWin+pLos+pTie << endl << endl;
			system("pause");
			break;
		}
		else { cout << "There was an error in comparing your choice to the computer's!" << endl; }
		
		Sleep(400);
		cout << endl;
		cout << playerName << "\'s score: Wins: " << pWin << " Losses: " << pLos << " Ties: " << pTie << endl << endl << endl;
		
		Sleep(300);
	} while (!exitGame);
	return 0;
}

/*--------------------------------------------Main menu.--------------------------------------------*/
short mainMenu(string& playerName, int& pWin, int& pLos, int& pTie, int& pRoc, int& pPpr, int& pScr, int& cWin, int& cLos, int& cTie, int& cRoc, int& cPpr, int& cScr)
{
	rps input;

	cout << endl << "Loading main menu...";
	Sleep(800);
	system("CLS");
	cout << "Would you like to start a new game?" << endl;
	cout << "[1]"; textCol(3, "ROCK"); cout << "> Start a new game" << endl;
	cout << "[2]"; textCol(2, "PAPER"); cout << "> Resume a previous game" << endl;
	cout << "[3]"; textCol(4, "SCISSORS"); cout << "> Display the current score" << endl;
	cout << "[4]"; textCol(5, "CROSS"); cout << "> Return to the login menu" << endl;
	cout << endl;
	input = rpsInput();
	cout << endl;
	switch (input)
	{
	case 0:
		printRules();
		pWin = 0; pLos = 0; pTie = 0; pRoc = 0; pPpr = 0; pScr = 0;
		cWin = 0; cLos = 0; cTie = 0; cRoc = 0; cPpr = 0; cScr = 0;
		gameLoop(playerName, pWin, pLos, pTie, pRoc, pPpr, pScr, cWin, cLos, cTie, cRoc, cPpr, cScr);
		return 0;
	case 1:
		gameLoop(playerName, pWin, pLos, pTie, pRoc, pPpr, pScr, cWin, cLos, cTie, cRoc, cPpr, cScr);
		return 1;
	case 2:
		scoreboard(playerName, pWin, pLos, pTie, pRoc, pPpr, pScr, cWin, cLos, cTie, cRoc, cPpr, cScr);
		return 2;
	case 3:
		cout << "Logging out..." << endl;
		return -1;
	default:
		cout << "There was an error in choosing the menu item." << endl << endl;
		return -2;
	}
}

/*-------------------------------------------Login menu.--------------------------------------------*/
short logInMenu(string& playerName)
{
	rps input;
	int pWin = 0, pLos = 0, pTie = 0, pRoc = 0, pPpr = 0, pScr = 0;
	int cWin = 0, cLos = 0, cTie = 0, cRoc = 0, cPpr = 0, cScr = 0;

	cout << endl << "loading login screen...";
	Sleep(1600);
	system("CLS");
	cout << "First thing, are you a new or returning player?" << endl;
	cout << "[1]"; textCol(3, "ROCK"); cout << "> Log in to an existing profile" << endl;
	cout << "[2]"; textCol(2, "PAPER"); cout << "> Create a new profile" << endl;
	cout << "[3]"; textCol(4, "SCISSORS"); cout << "> Roll the credits" << endl;
	cout << "[4]"; textCol(5, "CROSS"); cout << "> Exit the game" << endl;
	cout << endl;
	input = rpsInput();
	cout << endl;
	switch (input)
	{
	case 0:
		logIn(playerName);
		break;
	case 1:
		newProfile(playerName);
		return 1;
	case 2:
		credits();
		return 2;
	case 3:
		cout << "Sorry to see you go!" << endl << endl;
		return -1;
	default:
		cout << "There was an error in choosing the menu item." << endl << endl;
		return -2;
	}
	if (input == 0)
	{
		short mainMenuReturn = 0;
		do
		{
			mainMenuReturn = mainMenu(playerName, pWin, pLos, pTie, pRoc, pPpr, pScr, cWin, cLos, cTie, cRoc, cPpr, cScr);
			if (mainMenuReturn == -2) return -2;
			else if (mainMenuReturn == -3) return -3;
		} while (mainMenuReturn >= 0);
		return 0;
	}
	return 0;
}

/*---------------------------------------Program entry point.---------------------------------------*/
int main()
{
	string playerName = "Default";
	srand((unsigned)time(NULL));		// Initialize the random seed.

	cout << "GAME1001_A1_BaconKiera" << endl;
	cout << "Rock, Paper, Scissors" << endl;
	cout << "Initializing..." << endl;
	Sleep(400); cout << endl;
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "In this game, you win by guessing your opponent's choice." << endl;
	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
	short logInMenuReturn = 0;
	do
	{
		logInMenuReturn = logInMenu(playerName);
		switch (logInMenuReturn)
		{
		case -1:
			system("pause");
			return -1;
		case -2:
			cout << "Exception in menu handling system." << endl;
			system("pause");
			return -2;
		case -3:
			cout << "Exception in file loading system." << endl;
			system("pause");
			return -3;
		}
	} while (logInMenuReturn >= 0);

	system("pause");
	return 0;
}