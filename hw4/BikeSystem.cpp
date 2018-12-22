#include "BikeSystem.h"
#include <iostream>
using namespace std;

int BikeSystem::search(const char *user_name, int start_x, int start_y, int acceptive_comfort_rating) const {
    int idx = -1, distance = 200, comfort = 0;
	for (int i = 0; i < size; ++i) {
    	if (bikes[i]->occupied)
		    continue;
    	if (bikes[i]->comfort < acceptive_comfort_rating)
		    continue;

    	int disNow = abs(bikes[i]->x - start_x) + abs(bikes[i]->y - start_y);
		if (disNow < distance) {
			idx = i;
			distance = disNow;
			comfort = bikes[i]->comfort;
		} else if (disNow == distance) {
			if (bikes[i]->comfort > comfort) {
				idx = i;
				comfort = bikes[i]->comfort;
			}
		}
    }
    if (idx != -1)
    	cout << user_name << " selected " << bikes[idx]->serial << endl;
    else
    	cout << "found no bikes available" << endl;
	return idx;
}

BikeSystem::BikeSystem(){
    this->capability = INIT_CAP;
    this->bikes = new Bike*[this->capability];
    this->size = 0;
    this->incremental = this->capability / 2;
    for(int i = 0; i < this->capability; ++i){
        this->bikes[i] = nullptr;
    }
}
BikeSystem::~BikeSystem() {
    release(this->bikes, this->size);
}
bool BikeSystem::unlock_bike(int bike_indicator) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to unlock with bike indicator " << bike_indicator << endl;
        return false;
    }
    return this->bikes[bike_indicator]->unlock();
}
int BikeSystem::ride_record(int bike_indicator, int destination_x, int destination_y) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to ride with bike indicator " << bike_indicator << endl;
        return 0;
    }
    return this->bikes[bike_indicator]->move_to(destination_x, destination_y);
}
int BikeSystem::lock_bike(int bike_indicator) {
    if(bike_indicator >= this->size || this->bikes[bike_indicator] == NULL){
        cerr << "fail to lock with bike indicator " << bike_indicator << endl;
        return 0;
    }
    return this->bikes[bike_indicator]->lock();
}

void BikeSystem::add(Bike *bike) {
    if(this->size == this->capability) { // realloc
        cout << "realloc" << endl;
        this->capability += this->incremental;
        if(INIT_CAP / this->incremental < 8) {
            this->incremental /= 2;
            if(this->incremental < 1) this->incremental = 1;
        }
        Bike** new_bikes = new Bike*[this->capability];
        memcpy(new_bikes, this->bikes, this->size * sizeof(Bike*));
        for(int i = this->size; i < this->capability; ++i){
            new_bikes[i] = nullptr;
        }
        delete []this->bikes;
        this->bikes = new_bikes;
    }
    this->bikes[this->size] = bike;
    ++this->size;
}
void BikeSystem::release(Bike **bike_list, int num) {
    if(bike_list == nullptr){
        return;
    }
    for(int i = 0; i < num; ++i){
        if(bike_list[i] != nullptr){
            delete bike_list[i];
        }
    }
    delete []bike_list;
    bike_list = nullptr;
}