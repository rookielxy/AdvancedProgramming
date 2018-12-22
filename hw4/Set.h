#ifndef HW4_SET_H
#define HW4_SET_H

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define DEFAULT_LENGTH 1024
#define NUM 32

class Set {
	int *array;
    int length;
    static Set *p_free;
    Set *next;
public:
    Set();
    Set(const Set &set);
    Set(int elements[], int length);
    ~Set();

    void add(int element);
    bool erase(int element);
    bool contains(int element) const;

    int size() const { return length; }

    Set& operator+=(Set &set);
    Set& operator-=(Set &set);

    friend ostream& operator<<(ostream &os, Set rset);
    friend Set operator+(const Set &set1, const Set &set2);
    friend Set operator-(const Set &set1, const Set &set2);
    friend Set operator&(const Set &set1, const Set &set2);
	friend Set operator|(const Set &set1, const Set &set2);
	friend bool operator==(const Set &set1, const Set &set2);
	friend bool operator!=(const Set &set1, const Set &set2);
	friend bool operator>=(const Set &set1, const Set &set2);
	friend bool operator<=(const Set &set1, const Set &set2);
	friend bool operator>(const Set &set1, const Set &set2);
	friend bool operator<(const Set &set1, const Set &set2);
	static void *operator new(size_t size);
	static void operator delete(void *p);
};

ostream& operator<<(ostream &os, Set rset);
Set operator+(const Set &set1, const Set &set2);
Set operator-(const Set &set1, const Set &set2);
Set operator&(const Set &set1, const Set &set2);
Set operator|(const Set &set1, const Set &set2);
bool operator==(const Set &set1, const Set &set2);
bool operator!=(const Set &set1, const Set &set2);
bool operator>=(const Set &set1, const Set &set2);
bool operator<=(const Set &set1, const Set &set2);
bool operator>(const Set &set1, const Set &set2);
bool operator<(const Set &set1, const Set &set2);
void sort(int array[], int length);



#endif //HW4_SET_H
