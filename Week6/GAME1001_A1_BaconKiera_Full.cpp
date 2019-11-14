///*---------------------------------------GAME1001_A1_BaconKiera---------------------------------------
//							 GAME1001 Assignment 1, project by Kiera Bacon
//										 Feature Creep Version
//
//This program runs a Rock, Paper, Scissors game in which it loads the player username and password 
//information from a file, checking if they match existing data or writing new data as the player 
//commands.
//										*** In this version ***
//	(1) 9 user score variables are stored containing wins, losses, and ties for each type of guess.
//	(2) A single datafile is used for all user data.
//	(3) Windows.h is included for the use of SetConsoleTextAttribute(), Sleep(), and system("CLS").
//----------------------------------------------------------------------------------------------------*/
//
///*-----------------------------Compiler Directives and Global Variables.----------------------------*/
//#include <iostream>					// Used for all input and output to the console and data file.
//#include <ctime>					// Used for randomization.
//#include <string>					// Used for all user input.
//#include <fstream>					// Used for reading and writing user validation.
//#include <Windows.h>				// Used for Sleep(), system("CLS"), and textCol().
//using namespace std;
//
///*-------------------------Enumeration for the data type of all user input.-------------------------*/
//enum rps { rock, paper, scissors, cross };
//
///*------------------------------Set the colour of a given piece of text.----------------------------*/
//void textCol(int colour, string text)
//{
//	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);	// Sets the screen handle.
//	SetConsoleTextAttribute(screen, colour);			// Sets the text colour attribute to the passed in integer.
//	cout << text;										// Prints the passed in text.
//	SetConsoleTextAttribute(screen, 7);					// Resets the text colour attribute for the program to resume normally.
//}
//
///*------------------------Examine a string input for its character contents.------------------------*/
//short validateChars(string input, short conditionType, short sizeMin, short sizeMax)
//{
//	int upper = 0, lower = 0, number = 0, special = 0, legal = 0, illegal = 0;
//
//	// First, check if input length is valid. If it isn't, nothing more need be said.
//	if ((sizeMin > 0 && input.length() < sizeMin) || (sizeMax > 0 && input.length() > sizeMax))
//		return 1;
//
//	// Then check if the first character is valid.
//	if (conditionType == 1 && !((input[0] >= 'A' && input[0] <= 'Z') || (input[0] >= 'a' && input[0] <= 'z') || (input[0] >= '0' && input[0] <= '9')))
//		return 1;
//
//	// Then add the rest of the characters and see what they've got.
//	for (int i = 0; i < input.length(); i++)
//	{
//		if (input[i] >= 'A' && input[i] <= 'Z')
//			upper++;
//		else if (input[i] >= 'a' && input[i] <= 'z')
//			lower++;
//		else if (input[i] >= '0' && input[i] <= '9')
//			number++;
//		else if ((input[i] >= '!' && input[i] <= '/') || (input[i] >= ':' && input[i] <= '@') || (input[i] >= '[' && input[i] <= '`') || (input[i] >= '{' && input[i] <= '~'))
//			special++;
//		else if (input[i] == '#' || input[i] == '\'' || input[i] == '-' || input[i] == '@' || input[i] == '_')
//			legal++;
//		else
//			illegal++;
//	}
//
//	// Then compare the results against the condition flags if there are any.
//	if (conditionType == 1)
//	{
//		if ((special - legal == 0) && illegal == 0)
//			return 0;
//		else
//			cout << "???";
//			return 1;
//	}
//	else if (conditionType == 2)
//	{
//		if (upper > 0 && lower > 0 && number > 0 && special > 0 && illegal == 0)
//			return 0;
//		else
//			return 1;
//	}
//	
//	// Then, if it actually made it this far, it must be fine for whatever it's being checked against.
//	return 0;
//}
//
///*------------Validate a given string input and convert it into an enumerated RPS output.-----------*/
//rps rpsInput(string init = "Enter your selection [1-4]: ", string invalid = "Invalid input, please try again [1-4]: ")
//{											// General function for checking input validation and converting it to the game's language.
//	bool valid = false;						// Validation flag.
//	string input;
//	rps output;
//
//	// Check for valid input, and don't stop looping until it's given.
//	cout << init;							// Prints the introduction text either provided by whatever is requesting the input, or by the default.
//	do
//	{
//		cin >> input;
//		cin.ignore(INT_MAX, '\n');
//			//begin(RPSNames::rock), end(RPSNames::rock), input) != end(RPSNames::rock);
//		if (input == "1" || input == "ROCK" || input == "Rock" || input == "rock" || input == "R" || input == "r")
//		{
//			output = rock;
//			valid = true;
//		}
//		else if (input == "2" || input == "PAPER" || input == "Paper" || input == "paper" || input == "P" || input == "p")
//		{
//			output = paper;
//			valid = true;
//		}
//		else if (input == "3" || input == "SCISSORS" || input == "Scissors" || input == "scissors" || input == "S" || input == "s")
//		{
//			output = scissors;
//			valid = true;
//		}
//		else if (input == "4" || input == "0" || input == "CROSS" || input == "Cross" || input == "cross" || input == "X" || input == "x" || input == "C" || input == "c")
//		{
//			output = cross;
//			valid = true;
//		}
//		else { cout << invalid; }			// If the validation flag is not set to true in any of the above cases, the result is invalid,
//	} while (!valid);						// and the loop has to start again.
//	return output;							// returns one of the four possible values to the calling function.
//}
//
///*-----------------Validate a new string input for username or password conditions.-----------------*/
//string textInput(string firstPrompt, string secondPrompt, bool exitable, short conditionType, short sizeMin, short sizeMax, string conditionPrompt1, string conditionPrompt2)
//{
//	string input;
//	bool valid = false;								// Validation flag for verifying valid text input.
//
//	// Print the prompt text supplied by the calling function.
//	cout << firstPrompt;
//	if (sizeMin > 0 || sizeMax > 0) cout << " [" << sizeMin << "-" << sizeMax << " characters]";
//	if (exitable) cout << endl << " [4]>Go back";
//	cout << ": ";
//
//	// Check for valid input, and don't stop looping until it's given.
//	do
//	{
//		cin >> input;
//		cin.ignore(INT_MAX, '\n');
//
//		// First check for an exit request.
//		//if (exitable && (rpsInput(input) == 0))						~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//		//	return "-1";
//
//		// Then check for validation conditions.
//		if (conditionType != 0)
//			if (validateChars(input, conditionType, sizeMin, sizeMax) == 0)
//				valid = true;
//			else
//			{
//				// If user input is invalid, prints error text supplied by calling function.
//				textCol(4, conditionPrompt1);
//				cout << endl;
//				textCol(4, conditionPrompt2);
//				cout << endl;
//				cout << secondPrompt;
//				if (sizeMin > 0 || sizeMax > 0) cout << " [" << sizeMin << "-" << sizeMax << " chars]";
//				if (exitable) cout << endl << " [4]>Go back";
//				cout << ": ";
//			}
//		else
//			valid = true;
//	} while (!valid);
//	return input;
//}
//
///*---------Locate a given username in the data file and return its corresponding password.----------*/
//short findID(string searchID, string* checkPW, int pStats[] = nullptr)
//{
//	rps input;
//	string checkID, newFile;						// String for the username which is read from the file.
//	bool foundID = false;							// Checks whether the function found what it was looking for, becomes true if so.
//	ifstream inFile("HighlySecureUserData.txt");	// Opens the data file for reading.
//	if (!inFile.is_open())							// Checks if the file opened successfully, and prompts the user to create a new one if it didn't.
//	{
//		cerr << "Error opening file." << endl;
//		input = rpsInput("Create a new data file? [1-3]>Yes [4]>No: ", "Invalid input, please try again [1-3]>Yes [4]>No: ");
//		cout << endl;
//		if (input != 3)
//		{
//			cout << "Generating the new highly secure user data file..." << endl;
//			Sleep(1200);
//			cout << "Factoring the encryption prototype..." << endl;
//			Sleep(600);
//			cout << "Minimizing the loss protocol..." << endl;
//			Sleep(800);
//			cout << "Colonizing the feature creep..." << endl;
//			Sleep(1000);
//			cout << "Securing the login key..." << endl;
//			Sleep(600);
//			ofstream outFile("HighlySecureUserData.txt");
//			if (!outFile.is_open())					// Checks once again if the file opened successfully, and exits the program if it didn't.
//			{
//				cerr << "Error opening file." << endl;
//				system("pause");
//				return -3;
//			}
//			outFile.close();
//			cout << "Data file creation succsseful!" << endl << endl;
//			return 2;								// returning 2 allows the logInMenu() to know to go straight to the newProfile() function if it wasn't there already.
//		}
//		else
//		{
//			return -3;
//		}
//	}
//	while (!inFile.eof())							// Loops through the data file until it finds the string that was passed into the function.
//	{
//		!pStats ? inFile >> checkID >> *checkPW : inFile >> checkID >> *checkPW >> pStats[0] >> pStats[1] >> pStats[2] >> pStats[3] >> pStats[4] >> pStats[5] >> pStats[6] >> pStats[7] >> pStats[8];
//		if (searchID == checkID)					// If it matches the username read from the file with the username input from the user, it breaks the loop.
//		{
//			foundID = true;
//			break;
//		}
//	}
//	inFile.close();									// The file must be closed before the function terminates.
//	if (foundID) return 1;
//	else return 0;
//}
//
///*----------------Create a new user profile if a matching one does not already exist.---------------*/
//short newProfile(string &pName)
//{
//	bool newUser = false;							// Flag which states whether or not the checked username is new.
//	string searchID, checkID, newPW;
//	system("CLS");									// Clears the screen for aesthetic purposes.
//	cout << "Create a new profile." << endl << endl;
//	do												// Continues to loop until a new profile has been successfully created.
//	{
//		searchID = textInput("Enter your username", "Invalid username, please try again", true, 1, 8, 16,
//			"Must be [8-16 characters], start with a [letter or numeral],",
//			"and contain only the special characters [#'-@_].");	// Calls textInput() to validate username input.
//		if (searchID == "-1") { return -1; }
//		switch (findID(searchID, &newPW))			// Calls findID() to check if the inputted username exists.
//		{
//		case 0: newUser = true; break;				// If the switch returns 0: the username was not found.
//		case 1: break;								// If the switch returns 1: the username was found, and thus, the function cannot proceed.
//		case -1: newUser = true; break;				// If the switch returns -1: the file failed the open, but a new one was created that is currently empty.
//		case -3: return -3;							// If the switch returns -3: the file failed to open and a new one was NOT created. This kills the program.
//		default: cerr << "Error checking username, password, or user score data." << endl; return -1;
//		}
//		if (newUser == false)						// If the username already exists, it can't proceed.
//		{
//			Sleep(400);
//			cout << "Username \"" << searchID << "\" already in database. Please try something else." << endl;
//		}
//		else										// If the username is new, it can go on to the next step.
//		{
//			ofstream outFile("HighlySecureUserData.txt", ios::app);	// Opens the data file for writing.
//			if (!outFile.is_open())					// Checks if the file opened successfully, and exits the program if it didn't.
//			{
//				cerr << "Error opening file." << endl;
//				system("pause");
//				return -3;
//			}
//			newPW = textInput("Enter your password", "Invalid password, please try again", true, 2, 8, 16,
//				"Must be [8-16 characters] and contain at least one of each",
//				"[uppercase, lowercase, numueral, special character].");	// Calls textInput() to validate password input.
//			if (newPW == "-1") { return -1; }
//			cout << endl << "Saving user \"" << searchID << "\" with password \"" << newPW << "\" to file..." << endl;
//			outFile << endl << searchID << ' ' << newPW << " 0 0 0 0 0 0 0 0 0";	// Outputs the data to the data file.
//			outFile.close();						// The data file must be closed before the function terminates.
//			pName = searchID;						// Finally, saves the player's name as the new name which was entered.
//		}
//	} while (!newUser);								// Continues to loop until a new user profile has been successfully created.
//	return 0;
//}
//
///*-------------------------------Log in to an existing user profile.--------------------------------*/
//short logIn(string &pName, int pStats[])
//{
//	bool matchUser = false;							// Flag which states whether or not the username checked matches one in the data file.
//	string searchID, searchPW, checkPW;
//	system("CLS");									// Clears the screen for aethetic purposes.
//	cout << "Log in to an existing profile." << endl << endl;
//	do												// Continues to loop until the player has successfully logged in.
//	{
//		short foundID = 0;							// Flag to verify wheather a previously existing ID was found.
//		searchID = textInput("Enter your username", "Invalid username, please try again", true, 1, 8, 16, 
//			"Must be [8-16 characters], start with a [letter or numeral],",
//			"and contain only the special characters [#'-@_].");
//		if (searchID == "-1") { return -1; }
//		switch (findID(searchID, &checkPW, pStats))
//		{
//		case 0:										// If the switch returns 0: the file was opened but the username was not found.
//			Sleep(400);
//			cout << "User not found. Please try again." << endl << endl;
//			break;
//		case 1:										// If the switch returns 1: the username was found. 
//			Sleep(400);
//			searchPW = textInput("Username found. Enter your password", "Invalid password, please try again", true, 2, 8, 16,
//				"Must be [8-16 characters] and contain at least one of each",
//				"[uppercase, lowercase, numueral, special character].");
//			if (searchPW == "-1") { return -1; }
//			else if (searchPW == checkPW)			// If the password entered matches the one previously saved from the data file, begin exiting the loop.
//			{
//				Sleep(400);
//				cout << endl;
//				cout << "Logging in..." << endl;
//				Sleep(800);
//				pName = searchID;					// Sets the player's name to the saved username from the data file.
//				matchUser = true;					// Sets the flag to allow the loop to exit.
//			}
//			else									// If the password doesn't match, allows the loop to reset back to the start with inputting the username. 
//			{
//				Sleep(400);
//				cout << "Password incorrect. Please try again." << endl << endl;
//			}
//			break;
//		case 2: return 2;							// If the switch returns 2: the file failed to open but a new one was created.
//		case -3: return -3;							// If the switch returns -3: the file failed to open and a new one was NOT created. This kills the program.
//		default: cerr << "Error checking username, password, or user score data." << endl; return -1;
//		}
//	} while (!matchUser);							// Continues to loop until the player has successfully logged in.
//	return 0;
//}
//
///*---------------------------------Re-explain the rules on demand.----------------------------------*/
//void printRules()
//{
//	cout << "Gameplay rules: " << endl;
//	Sleep(200);
//	cout << endl;
//	cout << "Each round, select one of three options: [1]"; textCol(3, "ROCK"); cout << ", [2]"; textCol(2, "PAPER"); cout << ", or [3]"; textCol(4, "SCISSORS"); cout << "." << endl;
//	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
//	cout << "To win, guess how your opponent will play, and pick the one that beats it!" << endl;
//	cout << endl;
//	system("pause");
//}
//
///*-----------------------------------------Roll the credits.----------------------------------------*/
//void credits()
//{
//	cout << "Credits: " << endl;
//	Sleep(200);
//	cout << endl;
//	cout << "Assignment 1: Rock, Paper, Scissors, by Kiera Bacon," << endl;
//	cout << "with special thanks to Cloud for purring while she was working on it," << endl;
//	cout << "and to Alex and Wallace at George Brown College for teaching her how to do it." << endl;
//	cout << endl;
//	system("pause");
//}
//
///*-----------------------------------Display the current scores.------------------------------------*/
//void scoreboard(string& pName, int pStats[], int cStats[])
//{
//	cout << "Current Score:" << endl;
//	Sleep(200);
//	cout << endl;
//	cout << "Name: " << pName << " Rounds: " << pStats[0] + pStats[1] + pStats[2] + pStats[3] + pStats[4] + pStats[5] + pStats[6] + pStats[7] + pStats[8] << endl;
//	cout << "Wins: " << pStats[0] + pStats[3] + pStats[6] << " Losses: " << pStats[1] + pStats[4] + pStats[7] << " Ties: " << pStats[2] + pStats[5] + pStats[8] << endl;
//	cout << "Rocks: " << pStats[0] + pStats[1] + pStats[2] << " Papers: " << pStats[3] + pStats[4] + pStats[5] << " Scissors: " << pStats[6] + pStats[7] + pStats[8] << endl;
//	cout << endl;
//	cout << "Name: " << "Computer" << " Rounds: " << cStats[0] + cStats[1] + cStats[2] + cStats[3] + cStats[4] + cStats[5] + cStats[6] + cStats[7] + cStats[8] << endl;
//	cout << "Wins: " << cStats[0] + cStats[3] + cStats[6] << " Losses: " << cStats[1] + cStats[4] + cStats[7] << " Ties: " << cStats[2] + cStats[5] + cStats[8] << endl;
//	cout << "Rocks: " << cStats[0] + cStats[1] + cStats[2] << " Papers: " << cStats[3] + cStats[4] + cStats[5] << " Scissors: " << cStats[6] + cStats[7] + cStats[8] << endl;
//	cout << endl;
//	system("pause");
//}
//
///*-----------------------------------------Core game loop.------------------------------------------*/
//short gameLoop(string& pName, int pStats[], int cStats[])
//{
//	rps input;
//
//	cout << endl; "Starting a new game...";
//	Sleep(200);
//	system("CLS");
//	bool exitGame = false;								// Flag to check the game should still be running.
//	do
//	{
//		rps cpuInput = static_cast<rps>(rand() % 3);	// The computer's guess is randomized at the start of each round.
//
//		cout << "Round " << pStats[0] + pStats[1] + pStats[2] + pStats[3] + pStats[4] + pStats[5] + pStats[6] + pStats[7] + pStats[8] << ": " << endl;	// Display the round number and input information at the start of each round.
//		cout << "[1]"; textCol(3, "ROCK"); cout << " / ";
//		cout << "[2]"; textCol(2, "PAPER"); cout << " / ";
//		cout << "[3]"; textCol(4, "SCISSORS"); cout << " / ";
//		cout << "[4]"; textCol(5, "CROSS"); cout << " (Return to the main menu)" << endl;
//
//		string playerPrompt = pName + ": ";		// Display the player's name when making a guess.
//		input = rpsInput(playerPrompt);
//
//		// Check each of the nine different potential outcomes and both print the result, and save it to a variable for later reference.
//		Sleep(200);
//		switch (cpuInput)
//		{
//		case 0: cout << "Computer: Rock" << endl; break;
//		case 1: cout << "Computer: Paper" << endl; break;
//		case 2: cout << "Computer: Scissors" << endl; break;
//		}
//		Sleep(300);
//		if (input == 0 && cpuInput == 0) { cout << "You both chose Rock. It's a tie!";					pStats[2]++; cStats[2]++; }
//		else if (input == 0 && cpuInput == 1) { cout << "Your Rock loses to the computer's Paper!";     pStats[1]++; cStats[3]++; }
//		else if (input == 0 && cpuInput == 2) { cout << "Your Rock beats the computer's Scissors!";     pStats[0]++; cStats[7]++; }
//		else if (input == 1 && cpuInput == 0) { cout << "Your Paper beats the computer's Rock!";        pStats[3]++; cStats[1]++; }
//		else if (input == 1 && cpuInput == 1) { cout << "You both chose Paper. It's a tie!";            pStats[5]++; cStats[5]++; }
//		else if (input == 1 && cpuInput == 2) { cout << "Your Paper loses to the computer's Scissors!"; pStats[4]++; cStats[6]++; }
//		else if (input == 2 && cpuInput == 0) { cout << "Your Scissors lose to the computer's Rock!";   pStats[7]++; cStats[0]++; }
//		else if (input == 2 && cpuInput == 1) { cout << "Your Scissors beat the computer's Paper!";     pStats[6]++; cStats[4]++; }
//		else if (input == 2 && cpuInput == 2) { cout << "You both chose Scissors. It's a tie!";         pStats[8]++; cStats[8]++; }
//		else if (input == 3)							// Player can exit at any point.
//		{
//			cout << "Thank you for playing!" << endl;
//			cout << "Your final score as " << pName << " was: " << pStats[0] + pStats[3] + pStats[6] - pStats[1] + pStats[4] + pStats[7] << "." << endl;
//			cout << "Wins: " << pStats[0] + pStats[3] + pStats[6] << " Losses: " << pStats[1] + pStats[4] + pStats[7] << " Ties: " << pStats[2] + pStats[5] + pStats[8] << ". Rounds played: " << pStats[0] + pStats[1] + pStats[2] + pStats[3] + pStats[4] + pStats[5] + pStats[6] + pStats[7] + pStats[8] << endl << endl;
//			system("pause");
//			break;
//		}
//		else { cout << "There was an error in comparing your choice to the computer's!" << endl; }
//
//		Sleep(400);
//		cout << endl;
//		cout << pName << "\'s score: Wins: " << pStats[0] + pStats[3] + pStats[6] << " Losses: " << pStats[1] + pStats[4] + pStats[7] << " Ties: " << pStats[2] + pStats[5] + pStats[8] << endl << endl << endl;
//
//		Sleep(300);
//	} while (!exitGame);
//	return 0;
//}
//
///*--------------------------------------------Main menu.--------------------------------------------*/
//short mainMenu(string& pName, int pStats[], int cStats[])
//{
//	rps input;
//
//	cout << endl << "Loading main menu...";
//	Sleep(800);
//	system("CLS");
//	cout << "Would you like to start a new game?" << endl;
//	cout << "[1]"; textCol(3, "ROCK"); cout << "> Start a new game" << endl;
//	cout << "[2]"; textCol(2, "PAPER"); cout << "> Resume a previous game" << endl;
//	cout << "[3]"; textCol(4, "SCISSORS"); cout << "> Display the current score" << endl;
//	cout << "[4]"; textCol(5, "CROSS"); cout << "> Return to the login menu" << endl;
//	cout << endl;
//	input = rpsInput();
//	cout << endl;
//	switch (input)
//	{
//	case 0:
//		printRules();
//		for (int i = 0; i < 8; i++)
//		{
//			pStats[i] = 0;
//			cStats[i] = 0;
//		}
//		gameLoop(pName, pStats, cStats);
//		return 0;
//	case 1:
//		gameLoop(pName, pStats, cStats);
//		return 1;
//	case 2:
//		scoreboard(pName, pStats, cStats);
//		return 2;
//	case 3:
//		cout << "Logging out..." << endl;
//		return -1;
//	default:
//		cout << "There was an error in choosing the menu item." << endl << endl;
//		return -2;
//	}
//}
//
///*-------------------------------------------Login menu.--------------------------------------------*/
//short logInMenu()
//{
//	rps input;
//	string pName = "Default";
//	int pStats[9] = { 0,0,0,0,0,0,0,0,0 };
//	int cStats[9] = { 0,0,0,0,0,0,0,0,0 };
//
//	cout << endl << "loading login screen...";
//	Sleep(1600);
//	system("CLS");
//	cout << "First thing, are you a new or returning player?" << endl;
//	cout << "[1]"; textCol(3, "ROCK"); cout << "> Log in to an existing profile" << endl;
//	cout << "[2]"; textCol(2, "PAPER"); cout << "> Create a new profile" << endl;
//	cout << "[3]"; textCol(4, "SCISSORS"); cout << "> Roll the credits" << endl;
//	cout << "[4]"; textCol(5, "CROSS"); cout << "> Exit the game" << endl;
//	cout << endl;
//	input = rpsInput();
//	cout << endl;
//	
//	if (input == 0)
//	{
//		switch (logIn(pName, pStats))
//		{
//		case -3: return -3;						// Returning -3 to the main() function gives an error associated with the file loading system.
//		case 2: input = static_cast<rps>(1);	// if logIn() returns 2, fall down to creating a new profile. Setting input to 1 should cause newProfile() to run.
//		}
//	}
//	if (input == 1)
//	{
//		switch (newProfile(pName))
//		{
//		case 0:									// Everything worked properly and a new profile was created.
//			input = static_cast<rps>(0);		// Setting input to zero should cause mainMenu() to run.
//			break;
//		case -1:								// The player voluntarily exited the newProfile() process before it completed.
//		case -3: return -3;						// Returning -3 to the main() function gives an error associated with the file loading system.
//		}
//	}
//
//
//	switch (input)
//	{
//	case 0:
//		switch (logIn(pName, pStats))
//		{
//		case 2:
//			switch (newProfile(pName))
//			{
//			case -3: return -3;				// Returning -3 to the main() function gives an error associated with the file loading system.
//			}
//			break;
//			input = static_cast<rps>(1); break; // If logIn() failed, prevents the main menu from starting.
//			break;
//		case -3: return -3;				// Returning -3 to the main() function gives an error associated with the file loading system.
//		}
//		break;
//	case 1:
//		switch (newProfile(pName))
//		{
//		case 0:
//			input = static_cast<rps>(0);	// If newProfile succeeded, we shouldn't need to logIn() as well.
//			break;
//		case -3: return -3;				// Returning -3 to the main() function gives an error associated with the file loading system.
//		}
//		break;
//	case 2:
//		credits();
//		break;
//	case 3: return -1;					// Returning -1 to the main() function exits the game. 
//	default: return -2;					// Returning -2 to the main() function gives a generalized error.
//	}
//	
//	// If input is 0 after the switch, start looping mainMenu(). This should only happen if A) logIn() [case 0] was successful, or if newProfile() [case 1] was.
//	if (input == 0)
//	{
//		short mainMenuReturn = 0;
//		do
//		{
//			mainMenuReturn = mainMenu(pName, pStats, cStats);
//			if (mainMenuReturn == -2) return -2;
//			else if (mainMenuReturn == -3) return -3;
//		} while (mainMenuReturn >= 0);
//		return 0;
//	}
//	return 0;							// Only in the case of returning 0 does the login menu start again in a new iteration of the main() loop.
//}
//
///*---------------------------------------Program entry point.---------------------------------------*/
//int main()
//{
//	srand((unsigned)time(NULL));		// Initialize the random seed.
//
//	cout << "GAME1001_A1_BaconKiera" << endl;
//	cout << "Rock, Paper, Scissors" << endl;
//	cout << "Initializing..." << endl;
//	Sleep(400); cout << endl;
//	cout << "Welcome to Rock, Paper, Scissors!" << endl;
//	cout << "In this game, you win by guessing your opponent's choice." << endl;
//	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
//	short logInMenuReturn = 0;
//	do
//	{
//		logInMenuReturn = logInMenu();
//		switch (logInMenuReturn)
//		{
//		case -1:
//			switch (rand() % 10)
//			{
//			case 0:
//			case 1: cout << "Hope to see you again!" << endl << endl; break;
//			case 2: 
//			case 3: cout << "Sorry to see you go!" << endl << endl; break;
//			case 4: cout << "Don't forget to give me a five star rating!" << endl << endl; break;
//			case 5: cout << "Hang on a sec while I (pretend to) secure all your super secret login info!" << endl << endl; break;
//			default: cout << "Have a great day!" << endl << endl; break;
//			}
//			system("pause");
//			return 0;
//		case -2:
//			cerr << "Exception in menu handling system." << endl << endl;
//			system("pause");
//			return -2;
//		case -3:
//			cerr << "Unable to load user data." << endl << endl;
//			system("pause");
//			return -3;
//		}
//	} while (logInMenuReturn >= 0);
//
//	system("pause");
//	return 0;
//}
//
///*
//So there are two possible ways I can handle the menu system:
//newProfile() can get called from within logIn(), and can itself call logIn().
//	the advantage here is that it is cleaner and easier to understand.
//	the disadvantage is that it runs the risk of entering the main menu from within another function.
//or:
//from the return value of logIn(), there is an if() which calls newProfile(), and from newProfile one that calls logIn().
//*/