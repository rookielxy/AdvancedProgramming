#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
#include <iomanip>

using namespace std;

class Complex {
private:
    double re;
    double im;
public:
    Complex();
    explicit Complex(double re);
    Complex(double re, double im);
    ~Complex();
    Complex& operator=(const Complex &op);
    Complex operator+(const Complex &op);
    Complex operator-(const Complex &op);
    Complex operator*(const Complex &op);
    Complex operator/(const Complex &op);
    friend ostream& operator<<(ostream& output, const Complex &op);
};


#endif
