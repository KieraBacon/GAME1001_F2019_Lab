//#include <iostream>
//#include <cctype>
//#include <string>
//#include <fstream>
//
//using namespace std;
//
//int main()
//{
//	// Search variable.
//	bool found = false;
//	string searchID;
//	// Tempr variables to hold data from file
//	string lastName, firstName, studentID, grade1, grade2, grade3, grade4, grade5, grade6;
//	ifstream inFile("records.txt");
//	if (!inFile.is_open())
//	{
//		cerr << "Error opening file." << endl;
//		system("pause");
//		return 1;
//	}
//	cout << "Enter studentID to search for: ";
//	cin >> searchID;
//	while (!inFile.eof())
//	{
//		inFile >> lastName >> firstName >> studentID >> grade1 >> grade2 >> grade3 >> grade4 >> grade5 >> grade6;
//		if (searchID == studentID) 
//		{
//			cout << "Found: " << lastName << ", " << firstName << ", " << grade1 << ", " << grade2 << ", " << grade3
//				<< ", " << grade4 << ", " << grade5 << ", " << grade6;
//			found = true;
//			break;
//		}
//	}
//	if (found == false)
//		cout << "Student not found." << endl;
//		inFile.close();
//
//		system("pause");
//}
//
//short logIn()
//{
//	 Menu option.
//	char opt;
//	 Temp variables to hold data going into file.
//	string lastName, firstName, studentID, grade1, grade2, grade3, grade4, grade5, grade6;
//	ofstream outFile("records.txt", ios::app);
//	if (!outFile.is_open())
//	{
//		cerr << "Error opening file." << endl;
//		system("pause");
//		return 1;
//	}
//	do
//	{
//		cout << "\nNew student [n]\nQuit [q]\n\nEnter option: ";
//		cin >> opt;
//		if (tolower(opt) == 'n')
//		{
//			cout << "\nFormat: lastName firstName studentID grade1" <<
//				"grade 2 grade3 grade 4 grade5 grade6\n" << "Enter data: ";
//			cin >> lastName >> firstName >> studentID >> grade1 >> grade2 >> grade3 >> grade4 >> grade5 >> grade6;
//			outFile << lastName << ' ' << firstName << ' ' << studentID
//				<< ' ' << grade1 << ' ' << grade2 << ' ' << grade3 << ' ' << grade4 << ' ' << grade5 << ' ' << grade6 << endl;
//			cout << "Student " << studentID << " added to file." << endl;
//		}
//	} while (tolower(opt) != 'q');
//	outFile.close();
//	return 0;
//}