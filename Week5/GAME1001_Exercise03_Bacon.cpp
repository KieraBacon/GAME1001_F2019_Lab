/*-----------------------Kiera Bacon-------------------------------
Create a program based on the following criteria:

Define an integer for the user selection called selection
Define a double called ticketPrice that is initialized to 20
Create a numeric menu for ticket prices, thus:
Adult is 15-64 and is normal price (option 1)
Child is 0-14 and is half normal price (option 2)
Senior is 65+ and is 0.8x normal price (option 3)
Give an option to exit (option 4)
Based on their selection, output the price of their selected ticket
-----------------------------------------------------------------*/
/*
#include <iostream>
#include <iomanip>
using namespace std;

// Function to (re)display the menu.
void menu(double ticketPrice)
{
	cout << ">>>> >>> >> > TICKET MENU < << <<< <<<<" << endl << endl;
	cout << "#1> Adult Ticket [15-64] - $" << ticketPrice << endl;
	cout << "#2> Child Ticket [0-14] - $" << ticketPrice * 0.5 << endl;
	cout << "#3> Senior Ticket [65+] - $" << ticketPrice * 0.8 << endl;
	cout << "#4> Exit" << endl << endl;
}

// Main function.
int main()
{
	int userInput = 0;
	double ticketPrice = 20;	// Base ticket price. All other prices are percentages relative to this.
	double totalPrice = 0;		// Running total of all ticket prices.
	const float HST = 0.14;		// Death and taxes.
	menu(ticketPrice);
	do							// Begin main loop.
	{
		// Condition for whether the user has made a purchase. Redisplays the base message if the user has only given bad input.
		totalPrice == 0 ? cout << "Select a ticket by entering its item #. Enter 4 to exit or -4 for the menu: " :
			              cout << "To add another ticket, enter an item #. Enter 4 to exit or -4 for the menu: ";
		cin >> userInput;
		if (cin.fail()) {		// Check for input stream failure.
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Please enter a number corresponding to one of the items above." << endl << endl;
			continue;
		}
		switch (userInput) {	// Central menu switch against which all user inputs are checked.
		case 1:
			cout << "You bought an Adult Ticket for $" << ticketPrice << endl << endl;
			totalPrice += ticketPrice;
			break;
		case 2:
			cout << "You bought a Child Ticket for $" << ticketPrice*0.5 << endl << endl;
			totalPrice += ticketPrice*0.5;
			break;
		case 3:
			cout << "You bought a Senior Ticket for $" << ticketPrice*0.8 << endl << endl;
			totalPrice += ticketPrice*0.8;
			break;
		case 4:					// Case 4 exits the menu as per assignment guidelines. Possibly -1 might be a better pick under other circumstances.
			if (totalPrice == 0) {cout << endl << "We're sorry to see you go so soon. Please have a nice day." << endl << endl;}
			else
			{
				cout << fixed;
				cout << setprecision(2);
				cout << endl << "Thank you for your purchase!" << endl;
				cout << setw(20) << "Subtotal: $" << totalPrice << endl;
				cout << setw(20) << "     HST: $" << totalPrice * HST << endl;
				cout << setw(20) << "   TOTAL: $" << totalPrice * (1 + HST) << endl;
				cout << endl << "We hope you enjoy you visit. Please come again." << endl << endl;
			}
			break;
		case 5:					// Easter eggs are fun!
			cout << "You bought a secret VIP Ticket for $" << ticketPrice * 6.5 << endl;
			cout << "Thank you very much for your purchase, your experience is our highest priority." << endl << endl;
			totalPrice += ticketPrice * 6.5;
			break;
		// User can enter negative values to undo their previous purchases, but all entries are still listed on the receipt.
		case -1:
			cout << "You undid your purchase of an Adult Ticket. Total -$" << ticketPrice << endl << endl;
			totalPrice -= ticketPrice;
			break;
		case -2:
			cout << "You undid your purchase of an Adult Ticket. Total -$" << ticketPrice * 0.5 << endl << endl;
			totalPrice -= ticketPrice * 0.5;
			break;
		case -3:
			cout << "You undid your purchase of a Senior Ticket. Total -$" << ticketPrice * 0.8 << endl << endl;
			totalPrice -= ticketPrice;
			break;
							
		case -4:				// Case -4, corresponding to the exit option, redisplays the menu for the user.
			cout << endl;
			menu(ticketPrice);
			break;
		case -5:
			cout << "You undid your purchase of a secret VIP Ticket. Total -$" << ticketPrice * 6.5 << endl << endl;
			totalPrice -= ticketPrice * 6.5;
			break;
		default:				// Displays in case the user enters valid input that is nevertheless not on the menu.
			cout << "Please enter a number corresponding to one of the items above." << endl << endl;
			break;
		}
	} while (userInput != 4);	// Using a switch operator prevents the use of break; statements to exit a loop.
	
	system("pause");
	return 0;
}
*/