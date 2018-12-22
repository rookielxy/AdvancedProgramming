#include "Complex.h"

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double re) {
    this->re = re;
    im = 0;
}

Complex::Complex(double re, double im) {
    this->re = re;
    this->im = im;
}

Complex::~Complex() {
    re = 0;
    im = 0;
}

Complex& Complex::operator=(const Complex &op) {
    re = op.re;
    im = op.im;
    return *this;
}

Complex Complex::operator+(const Complex &op) {
    double re = this->re + op.re;
    double im = this->im + op.im;
    auto res = new Complex(re, im);
    return *res;
}

Complex Complex::operator-(const Complex &op) {
    double re = this->re - op.re;
    double im = this->im - op.im;
    auto res = new Complex(re, im);
    return *res;
}

Complex Complex::operator*(const Complex &op) {
    double re = this->re*op.re - this->im*op.im;
    double im = (this->re*op.im + this->im*op.re);
    auto res = new Complex(re, im);
    return *res;
}

Complex Complex::operator/(const Complex &op) {
    double divisor = op.re*op.re + op.im*op.im;
    double re = (this->re*op.re + this->im*op.im)/divisor;
    double im = (this->im*op.re - this->re*op.im)/divisor;
    auto res = new Complex(re, im);
    return *res;
}

ostream& operator<<(ostream &output, const Complex &op) {
    output << setiosflags(ios::fixed) << setprecision(2)
        << op.re << " " << op.im << endl;
    return output;
}