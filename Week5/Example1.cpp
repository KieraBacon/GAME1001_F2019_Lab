/*
// Brief introduction to programming loops (again)
#include <iostream>
using namespace std;

int main()
{
	int userInput = 0;
	int sum = 0;

	cout << "Hey ";

	// Sentinal Value (-1)

	while (true) // Infinte loop!
	{
		cout << "Enter a positive integer that will be added together. Type -1 to exit." << endl << endl;
		cin >> userInput;
		if (userInput == -1)
		{
			break; // Immediately exit out of the loop the computer is currently executing
		}
		sum += userInput;
		cout << "Your added value is: " << sum << endl;
	}

	cout << "\nThat's all folks!\n";

	system("pause");
	return 0;
}
*/