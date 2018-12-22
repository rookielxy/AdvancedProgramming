#include "Manager.h"

void Manager::add(Member *member) {
    table.emplace_back(*member);
}

void Manager::sortById() {
    sort(table.begin(), table.end());
}

void Manager::sortByDate() {
    sort(table.begin(), table.end(), compareDate);
}

void Manager::printSearch(const int id) {
    for(auto ele: table) {
        if(equalId(ele, id))
            ele.printInfo();
    }
}

void Manager::printAll() {
    for(auto ele: table) {
        ele.printInfo();
    }
}