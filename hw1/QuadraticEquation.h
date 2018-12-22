#ifndef __QUADRATICEQUATION_H
#define __QUADRATICEQUATION_H

#include <iostream>
#include <math.h>

using namespace std;

class QuadraticEquation {
private:
    int a;
    int b;
    int c;
public:
    QuadraticEquation(int a, int b, int c);
    int getA() const;
    int getB() const;
    int getC() const;
    int getDiscriminant();
    double getRoot1();
    double getRoot2();
};

#endif
