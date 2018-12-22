#include "Teacher.h"

Teacher::Teacher(int id, const char *name, int date, const char *department, const char *title):
    Member(id, name, date, department) {
    this->title = string(title);
}