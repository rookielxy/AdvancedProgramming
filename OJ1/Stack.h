#ifndef _STACK_H
#define _STACK_H

#include <iostream>

using namespace std;

struct stackNode {
    char data;
    stackNode *next;
    explicit stackNode(char data) {
        this->data = data;
        next = nullptr;
    }
};

class Stack {
private:
    stackNode *top;
public:
    Stack();
    ~Stack();
    void push(char data);
    char pop();
    char stackTop();
    bool isEmpty();
    void show();
};


#endif
