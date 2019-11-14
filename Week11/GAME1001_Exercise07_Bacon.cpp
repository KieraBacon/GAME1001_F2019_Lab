/*----------------------------------- GAME1001_Exercise07_Bacon --------------------------------------
						GAME1001 Practical Exercise 07, project by Kiera Bacon

Program specificiations are as follows:
1.1) Create an array of integers with a fixed size of 5 called marks.
1.2) Have integer variables for a counter, a sum of all values, a min and a max value and
1.3) a double for average.
2.1) Prompt the user to enter marks for 5 assignments then
2.2) use a for loop to get all the marks from the user and store them in each array index.
3.1) Use another for loop to get the min and max marks and store them in the respective integers.
3.2) Use another for loop to calculate the sum of all marks.
3.3) Calculate the average based on the sum of the 5 marks.
3.4) Finally, output the average, min and max marks back to the user.
//----------------------------------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

int main()
{
	int marks[5];																// Criterion 1.1
	int ctr, sum, min, max;														// Criterion 1.2
	double avg;																	// Criterion 1.3
	
	cout << "This program calculates the average, min, and max marks\n";
	cout << "based on a set of five assignment marks entered by the user.\n";
	
	for (ctr = 0; ctr < 5; ctr++)	// Loop runs once per mark to be entered	// Criterion 2.2
	{
		bool valid = false;			// Validation flag for the integer input
		do																		// Criterion 2.1
		{
			cout << "Enter ";
			switch (ctr)			// Let the user know which mark they are entering
			{
			case 0: cout << "1st"; break;
			case 1: cout << "2nd"; break;
			case 2: cout << "3rd"; break;
			case 3: cout << "4th"; break;
			case 4: cout << "5th"; break;
			}
			cout << " mark [positive whole number]: ";
		
			cin >> marks[ctr];
			
			if (cin.fail())				// Restart if the input fails
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else if (marks[ctr] < 0)	// Restart if the input is not a valid mark
			{
				cout << "Invalid entry. Marks must be positive whole numbers.\n";
			}
			else
			{
				cin.ignore(INT_MAX, '\n');	// Ensure that nothing is read into the next input
				valid = true;			// Exit if the input is good
			}
			
		} while (!valid);
	} 
	
	min = max = sum = marks[0];	// Min cannot be larger than, or max and sum smaller than, the first entry
	
	for (ctr = 0; ctr < 5; ctr++)												// Criterion 3.1
	{
		if (marks[ctr] < min) min = marks[ctr];
		if (marks[ctr] > max) max = marks[ctr];
	}
	
	for (ctr = 1; ctr < 5; ctr++)	// Only add values after the first			// Criterion 3.2
		sum += marks[ctr];	// It is unclear to me why this is better in a separate loop from above

	avg = sum / 5;			// There cannot be more or fewer than five marks	// Criterion 3.3

	cout << "The highest mark entered was " << max << endl;						// Criterion 3.4 
	cout << "The lowest mark entered was " << min << endl;						// |
	cout << "The average mark entered was " << avg << endl;						// V

	system("pause");
	return 0;
}