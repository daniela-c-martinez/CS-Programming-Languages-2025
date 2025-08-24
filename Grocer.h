// Daniela Martinez 8/19/25
//"Grocer.h"


#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <conio.h>


using namespace std;

class Grocer {
public: 
	Grocer(); // Constructor
	void run();

	void displayMenu();
	int getInteger(int, int, string);


	bool openInputFile(ifstream&, string);
	bool openOutputFile(ofstream&, string);
	map<string, int> readInputFile(ifstream&);
	void writeOutputFile(ofstream&, map<string, int>);
	void findItem(map<string, int>);
	void listItems(map<string, int>);
	void printHistogram(map<string, int>);


	
private:

	map<string, int> grocList;
	ifstream inputFile;
	ofstream outputFile;
	

	string printStars(int);

	void pause(string = "Press to continue");
	void cls();
	
};
