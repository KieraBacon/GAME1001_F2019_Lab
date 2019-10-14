///*--------------------------------GAME1001_Exercise04_BaconKiera----------------------------------
//							 Practical Lab Exercise 04 by Kiera Bacon
//Create a program based on the following criteria:
//1) Define two integers, one called number and one called sum. Sum should be intialized to 0
//2) Ask the user for an integer and put the user's input into 'number'
//3) No input validation required
//4) If the user's integer is negative, make it positive (this is mandatory)
//5) Create a for loop using a counter integer called i initialized to 1, continue the loop while i <= number and increment i by 1 each iteration
//6) In the body of the for loop, add the current value of i to the sum and assign the result back into sum
//7) After the for loop is done, output the final sum of the number from 1 to 'number'
//Submission: GAME1001_Exercise04_BaconKiera.cpp
//------------------------------------------------------------------------------------------------*/
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int number, sum = 0;							// 1) Define two variables.
//	
//	cout << "Please input a single whole number: ";	// 2.1) Ask the user for input...
//	cin >> number;									// 2.2) ...and save it to number, 3) without bothering to validate the input.
//	
//	if (number < 0) number -= number * 2;			// 4) Make the input positive if it is negative.
//	
//	for (int i = 1; i <= number; i++)				// 5) Create for loop with i <= number, incrementing by 1.
//	{
//		sum += i;									// 6) Add i to the sum total of sum each time.
//	}
//													// 7) Output the final sum.
//	cout << "The sum of all numbers between 1 and " << number << " is: " << sum << endl << endl;
//
//	system("pause");
//	return 0;
//}