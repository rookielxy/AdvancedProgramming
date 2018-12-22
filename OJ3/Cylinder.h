#ifndef OJ3_CYLINDER_H
#define OJ3_CYLINDER_H


#include "Body.h"

class Cylinder: public Body {
    double radius;
public:
    explicit Cylinder(double height, double radius);
    void getArea();
    void getVolume();
};


#endif //OJ3_CYLINDER_H
