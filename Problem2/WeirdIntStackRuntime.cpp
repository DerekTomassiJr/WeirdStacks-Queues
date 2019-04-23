#include "WeirdIntStack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Test" << endl;
    WeirdIntStack theStack;

    for (int i = 0; i < 10; i++) {
        theStack.push(i+1);
    }

    cout << "Size: " << theStack.getSize() << endl;
    cout << "Empty: " << theStack.isEmpty() << endl;

    cout << "Top 1" << theStack.getTop() << endl;

    for (int i =0; i < 5; i++) {
        theStack.pop();
    }

    //WeirdIntStack theStack2 = new WeirdIntStack(*theStack);

    cout << "Top 2" << theStack.getTop() << endl;
    //cout << "Top 3" << theStack2.getTop() << endl;

    return 0;
}
