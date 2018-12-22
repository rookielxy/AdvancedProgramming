#ifndef OJ3_CONE_H
#define OJ3_CONE_H

#include "Body.h"

class Cone : public Body {
    double radius;
public:
    explicit Cone(double height, double radius);
    void getArea();
    void getVolume();
};


#endif //OJ3_CONE_H
