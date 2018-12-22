#include "Bike.h"

bool Bike::unlock() {
    if (not occupied) {
        occupied = true;
        return true;
    }
    return false;
}

int Bike::lock() {
    if (occupied) {
        occupied = false;
        int cost = compute_cost();
        distance = 0;
        return cost;
    }
    return -1;
}

int Bike::move_to(int dst_x, int dst_y) {
    cout << "from " << x << "," << y
        << " to " << dst_x << "," << dst_y << endl;
    distance += abs(dst_x - x) + abs(dst_y - y);
    x = dst_x;
    y = dst_y;
}