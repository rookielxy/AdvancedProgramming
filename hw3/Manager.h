#ifndef HW3_MANAGER_H
#define HW3_MANAGER_H

#include "Teacher.h"
#include "Student.h"
#include "Member.h"

class Manager {
private:
    vector<Member> table;
public:
    void add(Member* member);
    void sortById();
    void sortByDate();
    void printSearch(int id);
    void printAll();
};


#endif //HW3_MANAGER_H
