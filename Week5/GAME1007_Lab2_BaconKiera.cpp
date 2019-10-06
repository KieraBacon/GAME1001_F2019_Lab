/*
Game project by Kiera Bacon.
In addition to the original code, I added a menu feature in which the player could select:
the maximum value for the number to be guessed, the maximum number of rounds, and the number of players.
The menu also features a set of default options the player can choose from.
During the main game loop, I added a check for the turn number and round number
and added a fail condition for if the player reaches the round limit without winning
in which the player closest to the right number is considered the winner.
I also added the ability to restart after a game finishes,
including the ability to restart with the same settings or with new ones.
*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string nameSelection(unsigned short currentSelector)
{
	string selectorName;
	cout << "Player " << currentSelector+1 << ", please enter your name: ";
	getline(cin, selectorName);
	return selectorName;
}

void defMenuAnnouncer(string difficulty, unsigned int range, unsigned int rounds)
{
	cout << "You selected " << difficulty << " mode. Range: [1-" << range << "]. Rounds: [" << rounds << "]." << endl;
}

unsigned int customizeSettings(string initSetup, unsigned int boundMin, unsigned int boundMax)
{
	unsigned int settingInput;
	cout << initSetup;
	bool valid = false;							// Validation flag for the customizeSettings function.
	do											// Validation loop for the customizeSettings function.
	{
		cin >> settingInput;
		cin.ignore(INT_MAX, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input. Select a number [" << boundMin << "-" << boundMax << "]: ";
		}
		else if (settingInput < boundMin || settingInput > boundMax)
		{
			cout << "Invalid input. Select a number [" << boundMin << "-" << boundMax << "]: ";
		}
		else
		{
			valid = true;
		}
	} while (!valid);
	return settingInput;
}

int main()
{
	const unsigned int DEFAULT_RANGE[5] = { 10, 100, 1000, 10000, 1000000 };		// Default values for the number range that the player can choose from.
	const unsigned int DEFAULT_ROUNDS[5] = { 0, 60, 30, 20, 10 };					// Default values for the turn timer that the player can choose from.
	const unsigned int RANGEMAX[2] = {10, 1000000000 };								// Min/max value for the target number.
	const unsigned short ROUNDLIMITMAX = 100;										// Mmax number of rounds.
	const unsigned short PLAYERSMAX = 10;											// Max number of players.
	const string DIFFICULTY[5] = {"EASY", "NORMAL", "HARD", "EXTREME", "INSANE" };	// Default names for the default difficulties.
	string playerName[10] = { "Player One", "Player Two", "Player Three", "Player Four", "Player Five", "Player Six", "Player Seven", "Player Eight", "Player Nine", "Player Ten" };
	bool firstGame = true, gameOver = false, quitGame = false;
	unsigned short roundLimit = 0, currentRound = 0, currentTurn = 1, playerCount = 1, currentPlayer = 1, closestNum, closestPlayer;
	unsigned int inputNum, targetNum = 1, maxNum = 1;
	
	srand((unsigned)time(NULL));
	
	quitGame = false;								// Set flag for the entire game.
	do												// Run the entire game loop, starting with the main menu.
	{
		/*-----------------------Initiate the Game---------------------*/
		if (firstGame)								// Only displays on the first run through.
		{
			cout << "In this game, players will take turns to guess a random number." << endl;
			cout << "With each guess, the game will hint whether the guess was too high or too low." << endl;
			cout << "The player who guesses right wins!" << endl;
			cout << "Good luck!" << endl << endl;
		}
		else										// Displays if this is the second time around.
		{
			cout << "Would you like to play another game?" << endl;
			cout << "1> RESTART with the same settings" << endl;
			cout << "2> RETURN to the main menu" << endl;
			cout << "0> EXIT the game" << endl << endl;
			bool valid = false;						// Validation flag for the restart menu loop.
			do										// Check for input validation for the restart menu.
			{
				cout << "Enter your selection [0-2]: ";
				cin >> inputNum;
				cin.ignore(INT_MAX, '\n');
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Invalid input. Select a number [0-2]: ";
				}
				else if (inputNum < 0 || inputNum > 2)
				{
					cout << "Invalid input. Select a number [0-2]: ";
				}
				else
				{
					valid = true;
				}
			} while (!valid);
			if (inputNum == 1)
			{
				cout << "You selected RESTART with the same settings." << endl;
				cout << "Range: [1-" << maxNum << "]. ";
				roundLimit == 0 ? cout << "No round limit." : cout << "Round Limit: [" << roundLimit << "].";
				cout << endl << endl;
				gameOver = false;					// Resets the gameOver flag so that the next round doesn't end immediately.
			}
			else if (inputNum == 2)
			{
				cout << "You selected RETURN to the main menu." << endl << endl;
				firstGame = true;					// Sets the firstGame flag to true so that the game restarts at the main menu.
				gameOver = false;					// Resets the gameOver flag so that the next round doesn't end immediately.
			}
			else if (inputNum == 0)
			{ 
				cout << "You selected EXIT. Have a great day!" << endl << endl;
				firstGame = false;					// If the firstGame flag is false, the main menu won't display.
				gameOver = true;					// If the gameOver flag is true, the main game loop won't begin.
				quitGame = true;					// If the quitGame flag is true the entire game loop will end without restarting.
			}
			else
			{
				cout << "There was an error in selecting the menu item." << endl << endl;
			}
		}
		/*--------------------Select Difficulty Mode-------------------*/
		if (firstGame)								// Main menu, skippable if this is your second game.
		{
			firstGame = false;						// Sets firstGame to false so that neither this menu nor the introduction will display.
			cout << ">>> >> > Main menu < << <<<" << endl;
			cout << "Select your difficulty setting:" << endl;
			cout << "1> " << DIFFICULTY[0] << " mode    " << "[1-" << DEFAULT_RANGE[0] << "]        " << "[No round limit]" << endl;
			cout << "2> " << DIFFICULTY[1] << " mode  " << "[1-" << DEFAULT_RANGE[1] << "]       " << "[" << DEFAULT_ROUNDS[1] << " round limit]" << endl;
			cout << "3> " << DIFFICULTY[2] << " mode    " << "[1-" << DEFAULT_RANGE[2] << "]      " << "[" << DEFAULT_ROUNDS[2] << " round limit]" << endl;
			cout << "4> " << DIFFICULTY[3] << " mode " << "[1-" << DEFAULT_RANGE[3] << "]     " << "[" << DEFAULT_ROUNDS[3] << " round limit]" << endl;
			cout << "5> " << DIFFICULTY[4] << " mode  " << "[1-" << DEFAULT_RANGE[4] << "]   " << "[" << DEFAULT_ROUNDS[4] << " round limit]" << endl;
			cout << "6> CUSTOM mode  " << "[Your choice] " << "[Your choice]   " << endl;
			cout << "0> EXIT the game" << endl << endl;	
			bool valid = false;						// Validation flag for the difficulty select loop.
			do										// Check for valid input for the difficulty select loop.
			{
				cout << "Enter your selection [0-6]: ";
				cin >> inputNum;
				cin.ignore(INT_MAX, '\n');
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					cout << "Invalid input. Select a number [0-6]: ";
				}
				else if (inputNum < 0 || inputNum > 6)
				{
					cout << "Invalid input. Select a number [0-6]: ";
				}
				else
				{
					valid = true;
				}
			} while (!valid);
			if (inputNum == 1)
			{
				cout << "You selected " << DIFFICULTY[0] << " mode. Range: [1-" << DEFAULT_RANGE[0] << "]. No round limit." << endl;
				maxNum = DEFAULT_RANGE[0];
				roundLimit = DEFAULT_ROUNDS[0];
			}
			else if (inputNum > 1 && inputNum < 6)
			{
				defMenuAnnouncer(DIFFICULTY[inputNum - 1], DEFAULT_RANGE[inputNum - 1], DEFAULT_ROUNDS[inputNum - 1]);
				maxNum = DEFAULT_RANGE[inputNum - 1];
				roundLimit = DEFAULT_ROUNDS[inputNum - 1];
			}
			else if (inputNum == 6)
			{
				cout << "You selected CUSTOM mode. The range and round limit is your choice." << endl;
				maxNum = customizeSettings("Please select the maximum the target number can be: ", RANGEMAX[0], RANGEMAX[1]);
				roundLimit = customizeSettings("Please select the number of rounds: ", 0, ROUNDLIMITMAX);
			}
			else if (inputNum == 0)
			{
				cout << "You selected EXIT. Have a great day!" << endl << endl;
				quitGame = true;
			}
			else
			{
				cout << "There was an error in selecting the menu item." << endl << endl;
			}
			if (quitGame) break;
			playerCount = customizeSettings("Please select the number of players who will be playing: ", 1, PLAYERSMAX);

			/*---------------------Select Player Names---------------------*/
			currentPlayer = 0;
			for (currentPlayer; currentPlayer < playerCount; currentPlayer++)
			{
				playerName[currentPlayer] = nameSelection(currentPlayer);
			}
			cout << endl;
		}
		/*---------------------Main game/turn loop---------------------*/
		currentPlayer = rand() % playerCount;		// The starting player will be randomized.
		targetNum = 1 + rand() % maxNum;			// The target number will be anywhere between 1 and maxNum, inclusive.
		currentRound = 0;							// Every game starts at round 0, even if the roundLimit is 0.
		currentTurn = 1;							// Every game starts on turn 1, even if there's only 1 player.
		closestNum = maxNum;						// Every game starts with the closest guess at its maximum possible value.
		closestPlayer = 0;							// Every game starts with player one as the currently winning player.
		while (!gameOver)
		{
			bool valid = false;						// Validation flag for the main game loop.
			do										// Validation loop.
			{
				cout << "Round [" << currentRound;	// Displays the round.turn/roundLimit, depending on players and round limit.
				if (playerCount > 1) cout << "." << currentTurn;
				if (roundLimit != 0) cout << "/" << roundLimit;
				cout << "]. ";
				cout << playerName[currentPlayer] << ", enter your guess [1-" << maxNum << "]: ";
				cin >> inputNum;
				cin.ignore(INT_MAX, '\n');
				if (cin.fail())						// Check if the input stream is in a fail state.
				{
					cin.clear();					// Clear the fail state.
					cin.ignore(INT_MAX, '\n');		// Flush again.
					cout << "Sorry, your guess has to be a number! Try again!" << endl;

				}
				else if (inputNum < 1 || inputNum > maxNum)	// Check if the range is good.
					cout << "Sorry, your guess has to be between [1-" << maxNum << "]. Try again!" << endl;

				else
					valid = true;					// Now we can exit the validation loop.

			} while (!valid);

			if (inputNum < targetNum)
			{
				cout << "Your guess was too low!" << endl;
				if (targetNum - inputNum < closestNum)
				{
					closestNum = targetNum - inputNum;
					closestPlayer = currentPlayer;
				}
			}
			else if (inputNum > targetNum)
			{
				cout << "Your guess was too high!" << endl;
				if (inputNum - targetNum < closestNum)
				{
					closestNum = inputNum - targetNum;
					closestPlayer = currentPlayer;
				}
			}
			else
			{
				cout << "Your guess was correct!" << endl;
				cout << playerName[currentPlayer] << " wins!" << endl << endl;
				gameOver = true;
			}
			if (!gameOver)
			{										// End of turn incrementation: rounds, turns, current first place; check for last turn.
				currentPlayer + 1 >= playerCount ? currentPlayer = 0 : currentPlayer++;
				if (currentTurn >= playerCount)
				{									// Increment the round and set the turn back to 1.
					currentTurn = 1;
					currentRound++;
					if (currentRound == roundLimit - 1 && roundLimit != 0)
					{								// Run at end of the penultimate round.
						cout << "Last round, make it count!" << endl;
					}
					else if (currentRound >= roundLimit && roundLimit != 0)
					{								// Run at the end of the final round.
						cout << "Game over! " << endl;
						closestNum != maxNum ? cout << "The winner is " << playerName[closestPlayer] << ", who was only " << closestNum << " away from the target!" : cout << "Only the computer is the winner here.";
						cout << endl << endl;
						gameOver = true;
					}
				}
				else
				{									// Increment the turn.
					currentTurn++;
				}
			}
		}
	} while (!quitGame);

	system("pause");
	return 0;
}
