#include "MyPoint.h"

MyPoint::MyPoint() {
    x = 0;
    y = 0;
}

MyPoint::MyPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

int MyPoint::getX() const {
    cout << x << endl;
    return x;
}

int MyPoint::getY() const {
    cout << y << endl;
    return y;
}

double MyPoint::distance(const MyPoint &p) {
    double res = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    cout << res << endl;
    return res;
}

double MyPoint::distance(int x, int y) {
    double res = sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
    cout << res << endl;
    return res;
}