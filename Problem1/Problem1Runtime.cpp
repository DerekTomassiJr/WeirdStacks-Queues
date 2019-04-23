#include <iostream>
#include "Problem1.h"
using namespace std;

int main() {
    Problem1 test;

    cout << "PROBLEM 1" << endl;

    string inputFilename;
    cout << "Enter Input Filename: ";
    cin >> inputFilename;
    cout << endl;

    string outputFilename;
    cout << "Enter Output Filename: ";
    cin >> outputFilename;
    cout << endl;

    test.decodeText(inputFilename, outputFilename);

    cout << "Input File" << endl;
    test.printFileContents(inputFilename);

    cout << "Output File" << endl;
    test.printFileContents(outputFilename);

    return 0;
}
