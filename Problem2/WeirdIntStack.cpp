#include "WeirdIntStack.h"
#include <queue>
#include <stdexcept>
using namespace std;

WeirdIntStack::WeirdIntStack() {
    this->size = 0;
}

WeirdIntStack::WeirdIntStack(WeirdIntStack& toCopy) {
    this->size = toCopy.getSize();

    if (toCopy.getSize() != 0) {
        //making a tempQueue to hold all the values from toCopy
        queue<int> tempQueue;
        while (!toCopy.isEmpty()) {
            tempQueue.push(toCopy.mainQueue->front());
            toCopy.pop();
        }

        //transfering the values of tempQueue to this->mainQueue and back to toCopy->mainQueue
        while (!tempQueue.empty()) {
            this->mainQueue->push(tempQueue.front());
            toCopy.push(tempQueue.front());
            tempQueue.pop();
        }

        //reversing mainQueue
        this->reverseQueue->push(this->mainQueue->back());
        for (int i = 0; i < this->mainQueue->size() - 1; i++) {
            for (int i = 0; i < this->mainQueue->size() - 1; i++) {
                int storage = this->mainQueue->front();
                this->mainQueue->pop();
                this->mainQueue->push(storage);
            }
            this->reverseQueue->push(this->mainQueue->back());
        }
    }
}

WeirdIntStack::~WeirdIntStack() {
    delete this->mainQueue;
    delete this->reverseQueue;
}

int WeirdIntStack::getSize() {
    return this->mainQueue->size();
}

bool WeirdIntStack::isEmpty() {
    //if queue is empty then stack is empty
    return this->mainQueue->empty();
}

void WeirdIntStack::push(int num) {
    this->mainQueue->push(num);

    //erasing all data in reverseQueue and repopulating it
    delete this->reverseQueue;
    //reversing mainQueue
    this->reverseQueue->push(this->mainQueue->back());
    for (int i = 0; i < this->mainQueue->size() - 1; i++) {
        for (int i = 0; i < this->mainQueue->size() - 1; i++) {
            int storage = this->mainQueue->front();
            this->mainQueue->pop();
            this->mainQueue->push(storage);
        }
        this->reverseQueue->push(this->mainQueue->back());
    }
}

void WeirdIntStack::pop() {
    if (this->getSize() == 0) {
        throw runtime_error("WeirdIntStack::pop, stack is empty");
    }
    this->reverseQueue->pop();

    for (int i = 0; i < this->mainQueue->size() - 1; i++) {
        int storage = this->mainQueue->front();
        this->mainQueue->pop();
        this->mainQueue->push(storage);
    }
    this->mainQueue->pop();
}

int WeirdIntStack::getTop() {
    if (this->isEmpty()) {
        throw runtime_error("WeirdIntStack::getTop, Stack is Empty");
        return 0;
    }
    return this->reverseQueue->front();
}
