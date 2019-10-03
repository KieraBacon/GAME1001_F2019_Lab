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
#include <iostream>
using namespace std;

int main()
{
	int userInput = 0;
	double ticketPrice = 20;
	cout << ">>>>TICKET MENU<<<<" << endl << endl;
	cout << "1> Adult Ticket [15-64] - $" << ticketPrice << endl;
	cout << "2> Child Ticket [0-14] - half price = $" << ticketPrice/2 << endl;
	cout << "3> Senior Ticket [65+] - 80% price = $" << ticketPrice*4/5 << endl;
	cout << "Select your ticket by entering the number into the prompt. Enter -1 to exit.";
	while (true)
	{
		switch (userInput) {
		case 1: cout << ticketPrice;
		case 2: cout << ticketPrice / 2;
		case 3: cout << ticketPrice * 4 / 5;
		case -1: break;
		}
	}
		   
	system("pause");
	return 0;
}