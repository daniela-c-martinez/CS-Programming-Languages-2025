// "Grocer.cpp"

#include "Grocer.h"


using namespace std;



Grocer::Grocer() {}

	
void Grocer::run() {
	string item = " ";
	int itemsAddded = 0;
	int itemsUpdated = 0;
	int selection = 0;
	bool notDone = true;
	if (openInputFile(inputFile, "CS210_Project_Three_Input_File.txt")) {
		cout << "Input File Opened" << endl;
	} // if
	else {
		cout << "File Error" << endl;
		return;
	} //else

	if (openOutputFile(outputFile, "frequency.dat")) {
		cout << "Output File Opened" << endl;
	} // if

	else {
		cout << "File error" << endl;
		return;
	} //else
	
	pause("Press enter to read the file ");
		cls();
		grocList = readInputFile(inputFile);
		writeOutputFile(outputFile, grocList);

	do {
		displayMenu();
		selection = getInteger(1, 4, "Please select menu option ");

		switch (selection) {
		case 1:
			findItem(grocList);
			cls();
			break;
		case 2:
			listItems(grocList);
			break;
		case 3:
			printHistogram(grocList);
			break;
		case 4:
			notDone = false;
			break;
		default:
			cout << "Error! Error!" << endl;
			break;
		} //switch
	} // do
	while (notDone);

	inputFile.close();

	
} // run
void Grocer::displayMenu() {
	cout << "Press 1 to find an item " << endl;
	cout << "Press 2 to list items and quantities " << endl;
	cout << "Press 3 to print a histogram " << endl;
	cout << "Press 4 to Exit the program " << endl;
} //displayMenu


int Grocer::getInteger(int minSelection, int maxSelection, string prompt) { // validates if input entered for menu selection is between 1-4
	int selection = 0;
	bool needSelection = false;

	while (!needSelection) {
		cout << prompt;
		cin >> selection;

		if (cin.fail()) {
			cin.clear();               
			cin.ignore(10000, '\n');   
			cout << "Please select between " << minSelection << " and " << maxSelection << endl;
		} //if
		else if (selection < minSelection || selection > maxSelection) {
			cin.ignore(10000, '\n');  
			cout << "Please enter a number between " << minSelection << " and " << maxSelection << endl;
		} // else if
		else {
			cin.ignore(10000, '\n');   
			needSelection = true;
		} // else
	}

	return selection;
} // get integer


bool Grocer::openInputFile(ifstream& infile, string filename) {
	infile.open(filename);
	if (infile.fail()) {
		cout << "Error in file " << endl;
		return false;
	} // if
	return true;
} //open inputfile

bool Grocer::openOutputFile(ofstream& outfile, string filename) {
	outfile.open(filename);
	if (outfile.fail()) {
		cout << "Error in file " << endl;
		return false;
	} // if
	return true;
} //open outputfile

map<string, int> Grocer::readInputFile(ifstream& inputFile) { //reads input file
	map<string, int> grocList;
	string item = " ";
	int itemsAdded = 0;
	int itemsUpdated = 0;

	while (getline(inputFile, item)) {
		cout << "reading " << item << endl;
		if (grocList.count(item)) {
			grocList[item]++;
			itemsUpdated++;
			cout << std::flush;
			cout << item << " updated " << endl;
		} //if
		else {
			grocList.emplace(item, 1);
			itemsAdded++;
			cout << std::flush;
			cout << item << " added " << endl;
		} //else

	} //while

	string stars(45, '*');
	cout << stars << endl;
	cout << "Items added = " << itemsAdded << endl;
	cout << "Items updated " << itemsUpdated << endl;
	cout << stars << endl;

	pause();
	cls();

	return grocList;

} // map

void Grocer::writeOutputFile(ofstream& outfile, map<string, int> grocList) {
	for (auto& groceries : grocList) {
		outfile << groceries.first << " " << groceries.second << endl;
	} //for
	cout << "Successfully output grocery list." << endl;
	pause();
	cls();
} //write outputfile


string Grocer::printStars(int numStars) {
	string stars(numStars, '*');
	return stars;
} //print stars

void Grocer::findItem(map<string, int> grocList) {
	string item = "";

	cout << "Enter an item ";
	getline(cin, item);

	if (grocList.count(item)) {
		cout << item << " is found with qty ";
		cout << grocList.at(item);
	} //if
	else {
		cout << item << " not found ";
	} //else
	cout << endl;
	pause();

} //find item

void Grocer::listItems(map<string, int> grocList) {
	for (auto groceries : grocList) {
		cout << groceries.first << " " << groceries.second << endl;
	} //for
	cout << endl;
	pause();
	cls();
	cout << endl;

} // list items

void Grocer::printHistogram(map<string, int> grocList) {
	for (auto groceries : grocList) {
		cout << groceries.first << " " << printStars(groceries.second) << endl;
	} //for
	cout << endl;
	pause();
	cls();
	cout << endl;
} //printHistogram
void Grocer::pause(string prompt) {
	cout << prompt;
	cin.get();

} //pause
void Grocer::cls() {
	cout << "\x1B[2J\x1B[H"; // ANSI escape sequence to clear screen and adjust cursor
	cout.flush();
} //cls

