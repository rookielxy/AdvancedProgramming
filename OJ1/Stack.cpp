#include "Stack.h"

Stack::Stack() {
    top = nullptr;
}

Stack::~Stack() {
    if(top == nullptr)
        return;
    while(top != nullptr) {
        stackNode *p = top;
        top = top->next;
        delete p;
    }
}

void Stack::push(char data) {
    auto p = new stackNode(data);
    if(top == nullptr)
        top = p;
    else {
        p->next = top;
        top = p;
    }
}

char Stack::pop() {
    char ch = top->data;
    stackNode *p = top;
    top = top->next;
    delete p;
    return ch;
}

char Stack::stackTop() {
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::show() {
    if(top == nullptr)
        return;
    stackNode *p = top;
    while(p != nullptr) {
        cout << p->data << endl;
        p = p->next;
    }
}