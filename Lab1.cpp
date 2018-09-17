// Matthew Hanley
// COSO 2030 Lab 1
// Sep 17 2018
// Referenced COSC 1030 homework assignment #7

#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::fstream;

int main()
{
	int count = -1; //-1 because the while loop runs one more time than it should, therefore counter is run up one more than it should be
	double current = 0;
	double first = 0;
	double second = 0;
	double previous = 0;
	double last = 0;
	double hold1 = 0;
	double hold2 = 0;
	string filename;
	ifstream inFile;

	inFile.close(); //make sure file input stream is free of all garbage from previous runs
	inFile.clear();

	cout << "Enter a filename: "; //ask the user for the filename
	cin >> filename;
	cout << endl;
	
	inFile.open(filename); //open file

	while (!inFile.fail()) //while .fail() is not true...
	{
		inFile >> current; //number read from file saved to variable current
		if (count == -1) //if this is the first number
		{
			first = current; //save as first
			count++;
		}
		else if (count == 0) //if this is the second number
		{
			second = current; //save as second
			count++;
		}
		else if (count > 0)
		{
			last = current;
			previous = hold2;
			hold2 = hold1; //while loop runs one extra time for some unknown reason. therefore it is necessary to save the two previous values in order to accurately output the second to last value.
			hold1 = current;
			count++;
		}
		
	}

	inFile.close();
	inFile.clear();

	cout << "Total numbers in file: " << count << endl;
	cout << "First number in file: " << first << endl;
	cout << "Second number in file: " << second << endl;
	cout << "Second to last number in file: " << previous << endl;
	cout << "Last number in file: " << last << endl << endl;
	system("pause");
}
