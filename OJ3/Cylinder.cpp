#include "Cylinder.h"

Cylinder::Cylinder(double height, double radius):
    Body(height) {
    this->radius = radius;
}

void Cylinder::getArea() {
    cout << setiosflags(ios::fixed) << setprecision(3)
         << PI*radius*radius << endl;
}

void Cylinder::getVolume() {
    double volume = PI*radius*radius*height;
    cout << setiosflags(ios::fixed) << setprecision(3)
         << volume << endl;
}