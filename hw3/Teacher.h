#ifndef HW3_TEACHER_H
#define HW3_TEACHER_H


#include "Member.h"

class Teacher : public Member{
private:
    string title;
public:
    Teacher(int id, const char* name, int date, const char *department, const char *title);
};


#endif //HW3_TEACHER_H
