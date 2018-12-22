#include "Cone.h"


Cone::Cone(double height, double radius):
    Body(height){
    this->radius = radius;
}

void Cone::getArea() {
    cout << setiosflags(ios::fixed) << setprecision(3)
         << PI*radius*radius << endl;
}

void Cone::getVolume() {
    double volume = (PI*radius*radius*height)/3;
    cout << setiosflags(ios::fixed) << setprecision(3)
         << volume << endl;
}