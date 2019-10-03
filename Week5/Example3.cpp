// Outputting to a file.
#include <iostream>
#include <fstream> // File-stream. Needed to use files.
using namespace std;

int main()
{
	ofstream outputFile;
	outputFile.open("GAME1001_Demo_File.txt"); // Opens the output file or source.

	cout << "Now writing data to the file. \n";

	outputFile << "Ninetendo Switch\n";
	outputFile << "Playstation 4 " << '\n';
	outputFile << "Xbox One " << endl;
	outputFile << "PC ";

	outputFile.close(); // Important to do this as immediately as possible.

	cout << "DONE! \n";

	system("pause");
	return 0;
}
/*
fstream
-------
ifstream -- Input file stream

ofstream -- Output file stream

 fstream -- File Stream (does both input and output, but slightly less optimized)
*/