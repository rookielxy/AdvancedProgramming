#ifndef OJ3_VECTOR_H
#define OJ3_VECTOR_H

#include <iostream>
#include <cstdlib>

using namespace std;


template <class T>
class Vector {
public:
    typedef T* iterator;

private:
    iterator start;
    iterator end_iterator;
    size_t m_size;
    size_t m_capacity;
public:
    explicit Vector(size_t c);
    ~Vector();
    void push_back(T e);
    size_t size();
    iterator begin();
    iterator end();
    iterator insert(iterator it, T e);
    iterator erase(iterator it);
    T& operator[](int idx);
};

template <class T>
Vector<T>::Vector(size_t c) {
    start = new T[c];
    end_iterator = start;
    m_size = 0;
    m_capacity = c;
}

template <class T>
Vector<T>::~Vector() {
    delete[] start;
    start = end_iterator = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template <class T>
void Vector<T>::push_back(T e) {
    *end_iterator = e;
    ++end_iterator;
    ++m_size;
}

template <class T>
size_t Vector<T>::size() {
    return m_size;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() {
    return start;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() {
    return end_iterator;
}

template <class T>
typename Vector<T>::iterator Vector<T>::insert(iterator it, T e) {
    for(iterator p = end_iterator; p != it; --p)
        *p = *(p - 1);
    *it = e;
    ++m_size;
    ++end_iterator;
    return it;
}

template <class T>
typename Vector<T>::iterator Vector<T>::erase(iterator it) {
    for(iterator p = it; p != end_iterator - 1; ++p)
        *p = *(p + 1);
    --end_iterator;
    --m_size;
    return it;
}

template <class T>
T& Vector<T>::operator[](int idx) {
    return start[idx];
}
#endif //OJ3_VECTOR_H
