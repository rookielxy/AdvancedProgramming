#ifndef _MYPOINT_H
#define _MYPOINT_H

#include <iostream>
#include <math.h>

using namespace std;

class MyPoint {
private:
    int x;
    int y;
public:
    MyPoint();
    MyPoint(int x, int y);
    int getX() const;
    int getY() const;
    double distance(const MyPoint &p);
    double distance(int x, int y);
};

#endif
