#include "ThreePrism.h"


ThreePrism::ThreePrism(double height, double size_a, double size_b, double size_c):
    Body(height) {
    this->size_a = size_a;
    this->size_b = size_b;
    this->size_c = size_c;
}

void ThreePrism::getArea() {
    double p = (size_a + size_b + size_c)/2;
    double area = sqrt(p*(p - size_a)*(p - size_b)*(p - size_c));
    cout << setiosflags(ios::fixed) << setprecision(3)
         << area << endl;
}

void ThreePrism::getVolume() {
    double p = (size_a + size_b + size_c)/2;
    double area = sqrt(p*(p - size_a)*(p - size_b)*(p - size_c));
    cout << setiosflags(ios::fixed) << setprecision(3)
         << area*height << endl;
}