#include "Body.h"

Body::Body(double height) {
    this->height = height;
}

void Body::printHeight() {
    cout << setiosflags(ios::fixed) << setprecision(3)
        << height << endl;
}