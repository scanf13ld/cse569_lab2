#pragma once
/* algorithms.h
Author: Shane Canfield
Purpose: This file holds declarations and definitoin for the functions used throughout this program
*/

//#ifndef HEADER_H
//#define HEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

enum struct params {USERINPUTFILE, USERINPUTS = 1};
enum struct outcomes {SUCCESS = 0, FAILURE = -1, INCORRECTUSAGE = -1};

outcomes printScreen(string userinputfile, int userparams);

vector<string> parseInput(vector<string>&, char*);

void usage(char*);


vector<string> parseInput(vector<string> &a, char* b)
{
	ifstream inputfile;

	inputfile.open(b);
	if (!inputfile) {
		return a; //returns empty vector if it cant open the file
	}
	int i = 0;
	string line;
	while (getline(inputfile, line)) {
		istringstream is(line);
		string word;
		while (is >> word) {
			if (word == "") { //leave out blank spaces
			}
			else {
				a.push_back(word);
				i++;
			}
		}
	}
	inputfile.close();
	return a;
}


//#endif  // HEADER_H

