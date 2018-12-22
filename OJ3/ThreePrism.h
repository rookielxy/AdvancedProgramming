#ifndef OJ3_THREEPRISM_H
#define OJ3_THREEPRISM_H

#include "Body.h"

class ThreePrism : public Body {
    double size_a;
    double size_b;
    double size_c;
public:
    explicit ThreePrism(double height, double size_a, double size_b, double size_c);
    void getArea();
    void getVolume();
};


#endif //OJ3_THREEPRISM_H
