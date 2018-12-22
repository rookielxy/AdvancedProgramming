#ifndef HW4_HELLOBIKE_H
#define HW4_HELLOBIKE_H

#include "Bike.h"

class HelloBike : public Bike {
    string elock_id;
public:
    HelloBike(const char *id, const char *elock_id, int x, int y, int comfort);
    bool unlock() override;
    int lock() override;
    int compute_cost() override;
};


#endif //HW4_HELLOBIKE_H
