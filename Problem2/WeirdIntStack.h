#ifndef WEIRDINTSTACK_H
#define WEIRDINTSTACK_H

#include <queue>
using namespace std;

class WeirdIntStack {
protected:
    queue<int>* mainQueue = new queue<int>();
    queue<int>* reverseQueue = new queue<int>();
    int size;
public:
    WeirdIntStack();
    WeirdIntStack(WeirdIntStack& toCopy);
    ~WeirdIntStack();
    int getSize();
    bool isEmpty();
    void push(int num);
    void pop(); //O(1)
    int getTop(); //O(1)
};

#endif
