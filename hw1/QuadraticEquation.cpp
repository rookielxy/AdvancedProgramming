#include "QuadraticEquation.h"


QuadraticEquation::QuadraticEquation(int a, int b, int c){
    this->a = a;
    this->b = b;
    this->c = c;
}

int QuadraticEquation::getA() const {
    cout << a << endl;
    return a;
}

int QuadraticEquation::getB() const {
    cout << b << endl;
    return b;
}

int QuadraticEquation::getC() const {
    cout << c << endl;
    return c;
}

int QuadraticEquation::getDiscriminant() {
    int res = b*b - 4*a*c;
    cout << res << endl;
    return res;
}

double QuadraticEquation::getRoot1() {
    int d = b*b - 4*a*c;
    if(d < 0) {
        cout << 0 << endl;
        return 0;
    }

    double x1 = (b == sqrt(d))? 0: (-b + sqrt(d))/(2*a);
    double x2 = (b == -sqrt(d))? 0: (-b - sqrt(d))/(2*a);
    double res = max(x1, x2);
    cout << res << endl;
    return res;
}

double QuadraticEquation::getRoot2() {
    int d = b*b - 4*a*c;
    if(d < 0) {
        cout << 0 << endl;
        return 0;
    }

    double x1 = (b == sqrt(d))? 0: (-b + sqrt(d))/(2*a);
    double x2 = (b == -sqrt(d))? 0: (-b - sqrt(d))/(2*a);
    double res = min(x1, x2);
    cout << res << endl;
    return res;
}