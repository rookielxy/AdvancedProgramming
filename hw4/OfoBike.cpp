#include "OfoBike.h"

OfoBike::OfoBike(const char *id, int x, int y, int comfort): Bike() {
    serial = id;
    this->x = x;
    this->y = y;
    this->comfort = comfort;
}

bool OfoBike::unlock() {
    if (not occupied) {
        cout << "unlock " << serial << endl;
        occupied = true;
        return true;
    }
    cout << "fail to unlock " << serial << endl;
    return false;
}

int OfoBike::lock() {
    if (occupied) {
        cout << "lock " << serial << endl;
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    }
    cout << serial << " has been locked" << endl;
    return -1;
}

int OfoBike::compute_cost() {
    int cost = 2*(int)ceil((double)distance/21);
    return cost > 7? cost - 7 : 0;
}
