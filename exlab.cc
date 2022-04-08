

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "header.h"

using namespace std;

extern "C" int LLVMFuzzerTestOneInput(int argc, char* argv[])
{
    const int program_name = 0;
    const int input_filename = 1;
    const int expected_args = 2;
    int user_params = argc;

    if (argc != expected_args) {
        usage(argv[program_name]);
        return (int)outcomes::INCORRECTUSAGE; //the user did not include the required number of arguments
    }

    vector<string> emptyvector;
    vector<string> newvector;

    newvector = parseInput(emptyvector, argv[input_filename]);
    if (newvector.empty()){ //aka the input file couldnt be opened and parsed into emptyvector
        cout << "Could not find input file." << endl;
        usage(argv[program_name]);
        return (int)outcomes::FAILURE;
    }

    vector<int> integers;

    int counter = 0;

    cout << endl << "Strings with letters or letters and numbers:" << endl;
    for (unsigned int i = 0; i < newvector.size(); i++) {
        int total = newvector[i].size();
        int digits = 0;
        for (unsigned int j = 0; j < newvector[i].size(); j++) {
            if (isdigit(newvector[i][j])) {
                digits++;
            }
        }
        if (total == digits) { //if the total size of string = number if digits in the string (all-digit string)
            stringstream ss(newvector[i]);
            int x = 0;
            ss >> x;
            integers.push_back(x); //add to the vector
        }
        while ((counter == 0) && (total != digits)) { //total number != digits number
            cout << newvector[i] << endl;
            counter++; //prints the string only once
        }
        counter = 0;
    }

    cout <<  endl << "Printing numeric values stored in integer vector:" << endl;
    for (unsigned int i = 0; i < integers.size(); i++) {
        cout << integers[i] << endl;
    }

    cout << "Goodbye!" << endl;
    return (int)outcomes::SUCCESS; //0
}


void usage(char* program_name) {
    cout << endl;
    cout << "Hello! This program reads strings from an input file and pushes them into a vector." << endl;
    cout << "Then, it copies out the integers into a new vector, and displays both vectors to the user." << endl;
    cout << "Proper usage: " << program_name << " <input_file_name>" << endl;
    cout << "Make sure your <input_file_name> exists!" << endl;

}


