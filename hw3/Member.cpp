#include "Member.h"

void Member::printInfo() {
    cout << id << " " << name << " "
        << date << " " << department << endl;
}

Member::Member(int id, const char *name, int date, const char *department) {
    this->id = id;
    this->name = string(name);
    this->date = date;
    this->department = string(department);
}

bool Member::operator<(const Member &x) const {
    return id < x.id;
}

bool compareDate(const Member &x, const Member &y) {
    return (x.date < y.date) or
            (x.date == y.date and x.id < y.id);
}

bool equalId(const Member &x, int id) {
    return x.id == id;
}
