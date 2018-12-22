#ifndef HW4_BIKE_H
#define HW4_BIKE_H

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class BikeSystem;

class Bike {
	friend class BikeSystem;
protected:
    string serial;
    bool occupied;
    int distance;
    int x, y;
    int comfort;
public:
    Bike(): occupied(false), distance(0) {}
    virtual bool unlock();
    virtual int lock();
    virtual int move_to(int dst_x, int dst_y);
    virtual int compute_cost() = 0;
};


#endif //HW4_BIKE_H
