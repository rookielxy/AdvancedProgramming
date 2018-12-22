#ifndef HW3_MEMBER_H
#define HW3_MEMBER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Member {
private:
    int id;
    string name;
    int date;
    string department;
public:
    Member(int id, const char *name, int date, const char *department);
    void printInfo();
    bool operator<(const Member &x) const ;
    friend bool compareDate(const Member &x, const Member &y);
    friend bool equalId(const Member &x, int id);
};

bool compareDate(const Member &x, const Member &y);
bool equalId(const Member &x, int id);

#endif //HW3_MEMBER_H
