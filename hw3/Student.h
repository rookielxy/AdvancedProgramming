#ifndef HW3_STUDENT_H
#define HW3_STUDENT_H

#include "Member.h"

class Student : public Member {
private:
    string major;
public:
    Student(int id, const char *name, int date, const char *department, const char *major);
};


#endif //HW3_STUDENT_H
