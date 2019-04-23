#include "Problem1.h"
#include <stack>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

Problem1::Problem1() {
    //constructor has nothing to initialize
}

Problem1::~Problem1() {
    //constructor has nothing to delete
    //or no memory to free up
}

void Problem1::decodeText(string inputFilename, string outputFilename) {
    ifstream inFile;
    inFile.open(inputFilename);
    ofstream outFile;
    outFile.open(outputFilename);

    //testing if the filename is valid
    if (!inFile.is_open()) {
        throw runtime_error("Problem1::decodeText, invalid input Filename");
    }

    //loop to continue until the end of the file
    while (!inFile.eof()) {
        char characterHolder;
        inFile.get(characterHolder);

        //determining if the char is a * or not
        if (characterHolder != '*') {
            this->characterStack.push(characterHolder);
        } else {
            //determining if the stack is empty
            if (this->characterStack.empty()) {
                throw runtime_error("Problem1::decodeText, found * when stack is empty");
            } else {
                char tempChar = this->characterStack.top();
                this->characterStack.pop();
                outFile << tempChar;
            }
        }
    }

    inFile.close();
    outFile.close();
}

//@Param filename to be used as an input file that will be printed out into the console
//Not a required method but I made it to help me test
void Problem1::printFileContents(string filename) {
    ifstream inFile;
    inFile.open(filename);

    //testing if the filename is valid
    if (!inFile.is_open()) {
        throw runtime_error("Problem1::printFileContents, invalid filename");
    }

    //loop to continue to the end of the file
    while(!inFile.eof()) {
        char tempChar;
        inFile.get(tempChar);

        cout << tempChar;
    }
    cout << endl;

    inFile.close();
}
