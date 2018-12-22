#ifndef _ITERATOR_H
#define _ITERATOR_H

#include <iostream>

using namespace std;

template <class T>
class Iterator {
private:
    T *ptr;
public:
    explicit Iterator(T* p = nullptr): ptr(p) {};
    ~Iterator();
    Iterator<T> operator+(size_t sz);
    Iterator<T> operator-(size_t sz);
    Iterator<T>& operator++();
    const Iterator<T> operator++(int);
    Iterator<T>& operator--();
    const Iterator<T> operator--(int);
    Iterator<T>& operator=(const Iterator &p);
    bool operator==(const Iterator &p);
    bool operator!=(const Iterator &p);
    T& operator*();


};

template <class T>
Iterator<T>::~Iterator() {

}

template <class T>
Iterator<T> Iterator<T>::operator+(size_t sz) {
    return Iterator(ptr + sz);
}

template <class T>
Iterator<T> Iterator<T>::operator-(size_t sz) {
    return Iterator(ptr - sz);
}

template <class T>
Iterator<T>& Iterator<T>::operator++() {
    ++ptr;
    return *this;
}

template <class T>
const Iterator<T> Iterator<T>::operator++(int) {
    ++ptr;
    return Iterator(ptr - 1);
}

template <class T>
Iterator<T>& Iterator<T>::operator--() {
    --ptr;
    return *this;
}

template <class T>
const Iterator<T> Iterator<T>::operator--(int) {
    --ptr;
    return Iterator(ptr + 1);
}

template <class T>
Iterator<T>& Iterator<T>::operator=(const Iterator &p) {
    ptr = p.ptr;
    return *this;
}

template <class T>
bool Iterator<T>::operator==(const Iterator &p) {
    return ptr == p.ptr;
}

template <class T>
bool Iterator<T>::operator!=(const Iterator &p) {
    return ptr != p.ptr;
}

template <class T>
T& Iterator<T>::operator*() {
    return *ptr;
}
#endif
