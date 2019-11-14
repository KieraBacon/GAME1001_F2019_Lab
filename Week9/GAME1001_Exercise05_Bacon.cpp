///*----------------------------------- GAME1001_Exercise05_Bacon --------------------------------------
//					    GAME1001 Practical Exercise 05, project by Kiera Bacon
//
//Program specificiations are as follows:
//1.1) Define four doubles, three of which are numbers and one represents the base of a power calculation
//1.2) Define one integer that will represent the power of a power calculation
//2.1) Ask the user for the three numbers, then the base and power
//3.1) Create four functions
//3.2) One calculates and returns the sum of the three number doubles
//3.3) One calculates and returns the product of the three doubles
//3.4) One calculates and returns the average of the three doubles
//3.5) One returns the result of the exponent using base and power
//4.1) Print all four function results back to the user
//----------------------------------------------------------------------------------------------------*/
//
//#include <iostream>
//using namespace std;
//
//double getSum(double, double, double);
//double getProduct(double, double, double);
//double getAverage(double, double, double);
//double getPower(double, int);
//
//int main()
//{
//	// Explain the program to the user
//	cout << "This program calculates the sum, product, and average of three numbers," << endl;
//	cout << "and then calculates the result of an exponent using base and power." << endl << endl;
//
//	bool exit = false;				// Exit flag for entire program
//	do
//	{	
//		char cont;
//		double num1, num2, num3, base;	// 1.1) Define four doubles, three of which are numbers and one represents the base of a power calculation
//		int pow;						// 1.2) Define one integer that will represent the power of a power calculation
//
//		for (int i = 0; i < 5; i++)		// 2.1) Ask the user for the three numbers, then the base and power
//		{
//			switch (i)						// Prompt the user based on which number is being input
//			{
//			case 0: cout << "First number: "; cin >> num1; break;
//			case 1: cout << "Second number: "; cin >> num2; break;
//			case 2: cout << "Third number: "; cin >> num3; break;
//			case 3: cout << "Base number: "; cin >> base; break;
//			case 4: cout << "Power [whole number only]: "; cin >> pow; break;
//			}
//			if (cin.fail())					// Verify that input is valid for the type, step back if not so no numbers get skipped
//			{
//				cin.clear();
//				cin.ignore(INT_MAX, '\n');
//				i--;
//			}
//			else			
//				cin.ignore(INT_MAX, '\n');	// Ignore the rest of the input stream so numbers don't get input to the next variable
//		}
//
//		// 4.1) Print all four function results back to the user
//		cout << endl << "Sum: " << getSum(num1, num2, num3) << endl;
//		cout << "Product: " << getProduct(num1, num2, num3) << endl;
//		cout << "Average: " << getAverage(num1, num2, num3) << endl;
//
//		{	// Smaller scope means the power calculation can be saved and the referenced several times, but the variable won't exist out of scope
//			double powResult = getPower(base, pow);
//			cout << "Result of [" << base << "^" << pow << "]: " << powResult;
//			if (powResult > 0 && powResult < 1)
//				cout << " or 1/" << (1 / powResult);
//			else if (powResult > -1 && powResult < 0)
//				cout << " or -1/" << (1 / -powResult);
//			cout << endl << endl;
//		}
//
//		// Check if the user wants to continue
//		do
//		{
//			cout << "Continue? [y/n]: ";
//			cin >> cont;
//			cin.ignore(INT_MAX, '\n');
//		} while (cont != 'Y' && cont != 'y' && cont != 'N' && cont != 'n');
//		if (cont == 'N' || cont == 'n')
//			exit = true;
//
//	} while (!exit);
//	return 0;
//}
//															// 3.1) Create four functions
//double getSum(double num1, double num2, double num3)		// 3.2) One calculates and returns the sum of the three number doubles
//{
//	return (num1 + num2 + num3);
//}
//
//double getProduct(double num1, double num2, double num3)	// 3.3) One calculates and returns the product of the three doubles
//{
//	return (num1 * num2 * num3);
//}
//
//double getAverage(double num1, double num2, double num3)	// 3.4) One calculates and returns the average of the three doubles
//{
//	return ((num1 + num2 + num3) / 3);
//}
//
//double getPower(double base, int pow)						// 3.5) One returns the result of the exponent using base and power
//{
//	double result = base;
//	if (pow == 0)		// Any number to the power of 0 is 1
//		return 1;
//	else if (pow < 0)	// A number with a negative exponent is the same as the reciprocal of the same number with a positive exponent
//	{
//		for (int i = 1; i < -pow; i++)
//			result *= base;
//		result = 1 / result;
//	}
//	else
//	{
//		for (int i = 1; i < pow; i++)
//			result *= base;
//	}
//	return result;
//}