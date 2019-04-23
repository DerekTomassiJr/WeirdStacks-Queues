#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <stack>
#include <string>
using namespace std;

class Problem1 {
protected:
    stack<char> characterStack;
public:
    Problem1();
    ~Problem1();
    void decodeText(string inputFilename, string outputFilename);
    void printFileContents(string filename);
};

#endif
