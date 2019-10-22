///*------------------------------------GAME1001_A1_BaconKiera--------------------------------------
//							 GAME1001 Assignment 1, project by Kiera Bacon
//
//This program runs a Rock, Paper, Scissors game against the computer. In this game, the player 
//makes a guess of one of the three options before the computer's guess and the game winner is 
//revealed. Rock beats Scissor, Scissor beats Paper, and Paper beats Scissor. The computer's guess
//is random. After each round, the player is prompted whether they wish to continue, and has the
//option of saving their data and exiting instead.
//
//In addition, at the beginning of the game, the player is prompted to log in with a username 8-16
//characters in length. If the username cannot be found, they are asked to create a new password, 
//then a new file is created and they are logged in. If the username already exists, however, they 
//must type in the password matching the one in the data file before they are able to log in, and 
//if they do, their previous score is displayed. The score is saved upon exiting the game.
//------------------------------------------------------------------------------------------------*/
//
//#include <iostream>					// Used for printing to and receiving input from the console.
//#include <string>					// Used for all user input, player name and password.
//#include <fstream>					// Used for reading and writing to the data file.
//#include <ctime>					// Used for randomizing the computer's guess.
//using namespace std;				// Used for enhanced readability.
//enum rps { rock, paper, scissor };	// Used for making the choices all pretty and well contained.
//
//rps rpsInput(string prompt)
//{
//	string input;
//	rps output;
//	bool valid = false;	// Validation flag.
//	do					// Loop until valid.
//	{
//		// Prompt for input (given by calling function).
//		cout << prompt << ": ";
//		cin >> input;
//		cin.ignore(INT_MAX, '\n');
//
//		// Check for valid input.
//		if (input == "ROCK" || input == "Rock" || input == "rock"
//			|| input == "R" || input == "r")
//		{
//			output = rock;
//			valid = true;
//		}
//		else if (input == "PAPER" || input == "Paper" || input == "paper"
//			|| input == "P" || input == "p")
//		{
//			output = paper;
//			valid = true;
//		}
//		else if (input == "SCISSORS" || input == "Scissors" || input == "scissors"
//			|| input == "SCISSOR" || input == "Scissor" || input == "scissor"
//			|| input == "S" || input == "s")
//		{
//			output = scissor;
//			valid = true;
//		}
//	} while (!valid);
//	return output;
//}
//
//string textInput(string prompt)
//{
//	string input;
//	bool valid = false;		// Flag to check for valid input.
//	do						// Loop until valid input is given.
//	{
//		// Prompt for input (given by calling function).
//		cout << prompt << ": ";
//		cin >> input;
//		cin.ignore(INT_MAX, '\n');
//
//		// Check for validation conditions.
//		valid = true;		// Input is presumed innocent until proven guilty... it's fewer steps.
//		
//		// Valid is false if the input is smaller or larger than allowed.
//		if (!(input.length() >= static_cast<unsigned int>(8) && input.length() <= static_cast<unsigned int>(16)))
//		{
//			valid = false;
//			cout << "Invalid input. Must be 8 to 16 characters in length." << endl << endl;
//		}
//
//		// Valid is false if any char is not allowed. This way, it breaks at the first invalid.
//		else
//		{
//			for (unsigned int i = 0; i < input.length(); i++)
//			{
//				if (!((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9') || input[i] == '_' || input[i] == '\'' || input[i] == '-'))
//				{
//					valid = false;
//					cout << "Invalid input. Must contain only [A-Z][a-z][0-9][-'_]." << endl << endl;
//					break;
//				}
//			}
//		}
//	} while (!valid);
//	return input;
//}
//
//bool saveStats(string& pName, string& pPass, int pStats[])
//{
//	// Open/create the data file for writing. If it didn't open, give an error and exit the program.
//	ofstream outFile(pName + ".txt");
//	if (!outFile.is_open())
//	{
//		cerr << endl << "Error opening or creating file." << endl;
//		return 1;
//	}
//
//	// Save the data, including the password obtained at logIn(), then close the file ASAP.
//	outFile << pPass << ' ' << pStats[0] << ' ' << pStats[1] << ' ' << pStats[2];
//	outFile.close();
//	cout << endl << "Data saved successfully." << endl << endl;
//	return 0;
//}
//
//bool gameLoop(string& pName, string& pPass, int pStats[])
//{
//	rps pInput, cInput;
//	bool exitGame = false;	// Flag to check if the game should still be running.
//	cout << "Starting new game." << endl;
//	do
//	{
//		// Randomize the computer's guess [0-2].
//		cInput = static_cast<rps>(rand() % 3);
//
//		// Display the round number anmd rules information, and then request input.
//		cout << endl << endl << endl << "Round " << pStats[0] + pStats[1] + pStats[2] << ": " << endl;
//		cout << "Enter your choice: [Rock], [Paper], or [Scissor]." << endl;
//		pInput = rpsInput(pName);
//		
//		// Print the computer's guess only after the player has entered theirs.
//		switch (cInput)
//		{
//		case 0: cout << "Computer: Rock" << endl; break;
//		case 1: cout << "Computer: Paper" << endl; break;
//		case 2: cout << "Computer: Scissor" << endl; break;
//		}
//
//		// Check each of the nine outcomes and print the result. Save result for later reference.
//		cout << endl;
//		if      (pInput == 0 && cInput == 0) { cout << "You both chose Rock. It's a tie!";				pStats[2]++; }
//		else if (pInput == 0 && cInput == 1) { cout << "Your Rock loses to the computer's Paper!";		pStats[1]++; }
//		else if (pInput == 0 && cInput == 2) { cout << "Your Rock beats the computer's Scissor!";		pStats[0]++; }
//		else if (pInput == 1 && cInput == 0) { cout << "Your Paper beats the computer's Rock!";			pStats[0]++; }
//		else if (pInput == 1 && cInput == 1) { cout << "You both chose Paper. It's a tie!";				pStats[2]++; }
//		else if (pInput == 1 && cInput == 2) { cout << "Your Paper loses to the computer's Scissor!";	pStats[1]++; }
//		else if (pInput == 2 && cInput == 0) { cout << "Your Scissor loses to the computer's Rock!";	pStats[1]++; }
//		else if (pInput == 2 && cInput == 1) { cout << "Your Scissor beats the computer's Paper!";		pStats[0]++; }
//		else if (pInput == 2 && cInput == 2) { cout << "You both chose Scissor. It's a tie!";			pStats[2]++; }
//		cout << endl;
//		
//		// Print the result and ask if the player wants to continue.
//		cout << pName << "\'s score: ";
//		cout << pStats[0]; pStats[0] == 1 ? cout << " win, "  : cout << " wins, ";
//		cout << pStats[1]; pStats[1] == 1 ? cout << " loss, " : cout << " losses, ";
//		cout << pStats[2]; pStats[2] == 1 ? cout << " tie."   : cout << " ties.";
//		cout << endl << endl;
//		cout << "Continue playing? [Rock]>Yes, [Paper]>Save and Exit, [Scissor]>Reset Score." << endl;
//		switch (rpsInput("Enter your choice"))
//		{
//		case 0:
//			break;
//		case 1: 
//			saveStats(pName, pPass, pStats);
//			switch (rand() % 12)
//				{
//				case 0: cout << "Don't forget to give me a five star rating!"; break;
//				case 1: cout << "Hang on a sec while I (pretend to) secure all your super secret login info!"; break;
//				case 2:
//				case 3: cout << "Hope to see you again!"; break;
//				case 4:
//				case 5: cout << "Sorry to see you go!"; break;
//				case 6:
//				case 7: cout << "Have fun!"; break;
//				default: cout << "Have a great day!"; break;
//				}
//			cout << endl << endl;
//			exitGame = true;
//			break;
//		case 2:
//			pStats[0] = pStats[1] = pStats[2] = 0;
//			break;
//		}
//	} while (!exitGame);
//	return 0;
//}
//
//bool logIn(string& pName, string& pPass, int pStats[])
//{
//	string inputID, inputPW, foundPW;
//	cout << "Enter your username [8-16 alphanumeric characters]" << endl;
//	bool loggedIn = false;				// Flag to check for logIn loop success.
//	do									// Continue to loop until the player has successfully logged in.
//	{
//		// Prompt the user for a username.
//		inputID = textInput("Username");
//
//		// Open the data file for reading, then check if it opened. If it didn't, create a new one.
//		ifstream inFile((inputID + ".txt"));
//		if (!inFile.is_open())
//		{
//			// Prompt the user for a new password.
//			cout << "Username not found, creating new profile." << endl;
//			cout << "Enter your password [8-16 alphanumeric characters]" << endl;
//			inputPW = textInput("Password");
//			
//			// Create a new file, then check if it opened. If it didn't, give an error and exit the program.
//			ofstream outFile(inputID + ".txt");
//			if (!outFile.is_open())
//			{
//				cerr << "Error creating file." << endl;
//				return 1;
//			}
//
//			// Save the password and baseline data, then close the file ASAP.
//			outFile << inputPW << ' ' << pStats[0] << ' ' << pStats[1] << ' ' << pStats[2];
//			outFile.close();
//
//			// Set the player name and password to the ones entered, then flag the function to exit.
//			cout << "Logging in..." << endl << endl;
//			pName = inputID;
//			pPass = inputPW;
//			loggedIn = true;
//		}
//		else
//		{
//			// If the original data file opened successfully, save the data within it, then close it ASAP.
//			inFile >> foundPW >> pStats[0] >> pStats[1] >> pStats[2];
//			inFile.close();
//
//			// Prompt the user for a password, then check if it matches the one saved from the data file.
//			cout << "Enter your password [8-16 alphanumeric characters]" << endl;
//			inputPW = textInput("Password");
//			if (inputPW == foundPW)
//			{
//				cout << "Logging in..." << endl << endl;
//				pName = inputID;
//				pPass = inputPW;
//				cout << endl << endl << "Username: " << pName << endl;
//				cout << "Current score: ";
//				cout << pStats[0]; pStats[0] == 1 ? cout << " win, " : cout << " wins, ";
//				cout << pStats[1]; pStats[1] == 1 ? cout << " loss, " : cout << " losses, ";
//				cout << pStats[2]; pStats[2] == 1 ? cout << " tie." : cout << " ties.";
//				cout << endl;
//				loggedIn = true;
//			}
//			else
//			{
//				cout << "Password incorrect." << endl << endl;
//			}
//		}
//	} while (!loggedIn);
//	return 0;
//}
//
//int main()
//{
//	string pName = "Player01", pPass = "Password";
//	int pStats[3] = { 0,0,0 };
//	srand((unsigned)time(NULL));
//	
//	// Print startup instructions.
//	cout << "Welcome to Rock, Paper, Scissors!" << endl;
//	cout << "A project by Kiera Bacon." << endl;
//	cout << endl;
//	cout << "In this game, play against the computer to see who can win the most rounds." << endl;
//	cout << "To win, predict your opponent's choice, then pick the one that will beat it!" << endl;
//	cout << "Rock beats Scissors, Scissors beats Paper, and Paper beats Rock." << endl;
//	cout << "Good luck! And don't forget to have fun!" << endl;
//	cout << endl;
//
//	// Both logIn()/gameLoop() loop internaly, so are only called once. When either returns, the game ends.
//	if (logIn(pName, pPass, pStats) == 0)
//		gameLoop(pName, pPass, pStats);
//	system("pause");
//	return 0;
//}