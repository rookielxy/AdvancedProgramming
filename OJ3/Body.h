#ifndef OJ3_BODY_H
#define OJ3_BODY_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define PI 3.14

using namespace std;

class Body {
protected:
    double height;
public:
    explicit Body(double height);
    void printHeight();
};


#endif //OJ3_BODY_H
