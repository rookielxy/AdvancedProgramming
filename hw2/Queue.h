#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>
#include <iostream>
#include <string>

template <class T>
struct Node {
    T val;
    Node *next;
    explicit Node(T val) {
        this->val = val;
        next = nullptr;
    }
};

template <class T>
class Queue {
private:
    Node<T> *start;
    Node<T> *end;
    size_t length;
public:
    Queue();
    ~Queue();
    void push(T e);
    T pop();
    T back();
    T front();
    bool isEmpty();
    size_t size();
    void show();
};

template <class T>
Queue<T>::Queue(){
    start = end = nullptr;
    length = 0;
}

template <class T>
Queue<T>::~Queue() {
    length = 0;
    end = nullptr;
    while(start != nullptr) {
        Node<T> *temp = start;
        start = start->next;
        delete temp;
    }
}

template <class T>
void Queue<T>::push(T e) {
    auto p = new Node<T>(e);
    if(end == nullptr) {
        start = end = p;
        length = 1;
    } else {
        end->next = p;
        end = p;
        ++length;
    }
}

template <class T>
T Queue<T>::pop() {
    // suppose start != nullptr
    T res = start->val;
    start = start->next;
    if(start == nullptr)
        end = nullptr;
    --length;
    return res;
}

template <class T>
T Queue<T>::back() {
    // suppose queue not empty
    return end->val;
}

template <class T>
T Queue<T>::front() {
    // suppose queue not empty
    return start->val;
}

template <class T>
bool Queue<T>::isEmpty() {
    return length == 0;
}

template <class T>
size_t Queue<T>::size() {
    return length;
}

template <class T>
void Queue<T>::show() {
    Node<T> *p = start;
    while(p != nullptr) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

#endif
