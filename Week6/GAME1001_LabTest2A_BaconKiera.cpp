///*----------------------------------GAME1001_Lab2A_BaconKiera-------------------------------------
//									Lab Test 2A by Kiera Bacon
//One interesting application of computers is to display graphs and bar charts. Write an application
//that reads five numbers between 1 and 30. For each number that’s read, your program should
//display the same number of adjacent asterisks. For example, if your program reads the number
//7, it should display *******. Display the bars of asterisks after you read all five numbers.
//------------------------------------------------------------------------------------------------*/
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int readNum[5] = {0,0,0,0,0};			// array for all input values
//	cout << "Please input five whole numbers between 1 and 30." << endl << endl;
//	for (int i = 0; i < 5; i++)
//	{										// repeat the input procedure once for each input index (five times)
//		bool valid = false;					// initialize validation for user input
//		while (!valid)
//		{									// verify input is valid and conforms to the specified requirements
//			switch (i)
//			{
//			case 0: cout << "1st number: "; break;
//			case 1: cout << "2nd number: "; break;
//			case 2: cout << "3rd number: "; break;
//			case 3: cout << "4th number: "; break;
//			case 4: cout << "5th number: "; break;
//			default: cout << "Error identifying input index.";
//			}
//			cin >> readNum[i];
//			cin.ignore(INT_MAX, '\n');
//			if (cin.fail())
//			{								// if input is not an integer, clear the stream and try again
//				cin.clear();
//				cin.ignore(INT_MAX, '\n');
//				cout << "Input must be a whole number between 1 and 30, please try again." << endl;
//			}
//			else if (readNum[i] < 1 || readNum[i] > 30)
//			{								// if input is not within range, do nothing but try again
//				cout << "Input must be a whole number between 1 and 30, please try again." << endl;
//			}
//			else
//			{								// if input is valid and in range, end the validation loop
//				valid = true;
//			}
//		}
//	}
//	cout << endl;					// nice white space
//	for (int i = 0; i < 5; i++)
//	{														// for each of the five input indicis, access the value stored within the index location, then
//		cout << readNum[i];									// print the value itself, 
//		readNum[i] < 10 ? cout << ":  " : cout << ": ";		// adjust the formatting based on the number of digits, and
//		for (int j = 0; j < readNum[i]; j++)
//		{													// print a number of *s equal to the value of the originally access index.
//			cout << "*";
//		}
//		cout << endl;
//	}
//	cout << endl;							// more pretty white space, isn't it great?
//
//	system("pause");
//	return 0;
//}