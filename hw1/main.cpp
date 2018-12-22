#include "QuadraticEquation.h"

int main() {
    QuadraticEquation p(-1, -4, -3);
    int a = p.getA();
    int b = p.getB();
    int c = p.getC();
    int d = p.getDiscriminant();
    double result1 = p.getRoot1();
    double result2 = p.getRoot2();
    return 0;
}