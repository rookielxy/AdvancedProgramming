#ifndef HW4_OFOBIKE_H
#define HW4_OFOBIKE_H

#include "Bike.h"

class OfoBike : public Bike {

public:
    OfoBike(const char *id, int x, int y, int comfort);
    bool unlock() override;
    int lock() override;
    int compute_cost() override;
};


#endif //HW4_OFOBIKE_H
