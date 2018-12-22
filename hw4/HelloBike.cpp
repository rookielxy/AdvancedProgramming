#include "HelloBike.h"

HelloBike::HelloBike(const char *id, const char *elock_id, int x, int y, int comfort): Bike() {
    serial = id;
    this->elock_id = elock_id;
    this->x = x;
    this->y = y;
    this->comfort = comfort;
}

bool HelloBike::unlock() {
    if (not occupied) {
        cout << "unlock " << serial << " "<< elock_id << endl;
        occupied = true;
        return true;
    }
    cout << "fail to unlock " << serial << " " << elock_id << endl;
    return false;
}

int HelloBike::lock() {
    if (occupied) {
        cout << "lock " << serial << " " << elock_id << endl;
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    }
    cout << serial << " " << elock_id << " has been locked" << " " << endl;
    return -1;
}

int HelloBike::compute_cost() {
    int cost = 2*(int)ceil((double)distance/25);
    return cost > 5? cost - 5 : 0;
}