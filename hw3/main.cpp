#include <iostream>
#include <string>
#include <vector>
#include "Manager.h"

using namespace std;

int main() {
    Manager m;
    m.add(new Teacher(1069, "Cai", 2018, "Economics", "Prof"));
    m.add(new Student(161011, "Alice", 2016, "CS", "CS"));
    m.add(new Student(150886, "Wang", 2015, "EE", "CE"));
    m.add(new Student(183210, "Zhang", 2018, "Science", "Mathematics"));
    m.add(new Teacher(11240, "Huang", 2012, "Art", "AProf"));
    m.add(new Teacher(11421, "Zheng", 2014, "Economics", "AP"));
    m.add(new Teacher(10530, "Wu", 2005, "Law", "Prof"));
    m.printAll();
    m.sortById();
    m.printAll();
    m.printSearch(11421);
    m.printSearch(10824);
    m.sortByDate();
    m.printAll();
    return 0;
}