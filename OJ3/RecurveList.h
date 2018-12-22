#ifndef OJ3_RECURVELIST_H
#define OJ3_RECURVELIST_H

#include <iostream>

using namespace std;

class List;

class ListNode {
    friend class List;
private:
    int data;
    ListNode *link;
    explicit ListNode(const int item) : data(item), link(nullptr) {}
};

class List {
private:
    ListNode *first, *current;
    int max;
    int num;
    int sum;
    int Max(ListNode *f);
    int Num(ListNode *f);
    float Avg(ListNode *f, int& n);
public:
    List() : first(nullptr), current(nullptr), max(0), num(0), sum(0) {}
    ~List() = default;
    ListNode* NewNode(int item);
    void NewList(int retvalue);
    void PrintList();
    int GetMax() { return Max(first); }
    int GetNum() { return Num(first); }
    float GetAvg() { return Avg(first, num); }
};

#endif //OJ3_RECURVELIST_H
