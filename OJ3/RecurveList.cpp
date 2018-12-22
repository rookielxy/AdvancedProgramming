#include "RecurveList.h"

ListNode* List::NewNode(int item){
    return new ListNode(item);
}

void List::NewList(int retvalue) {
    int data;
    while(true) {
        cin >> data;
        if(data == retvalue)
            break;
        auto p = new ListNode(data);
        if(first == nullptr) {
            first = p;
            current = p;
            max = data;
        } else {
            current->link = p;
            current = p;
            max = data > max ? data : max;
        }
        ++num;
        sum += data;
    }
}

int List::Max(ListNode *f) {
    return max;
}

int List::Num(ListNode *f) {
    return num;
}

float List::Avg(ListNode *f, int &n) {
    return (float)sum/num;
}

void List::PrintList() {
    ListNode *p = first;
    while(p != nullptr) {
        cout << p->data << " ";
        p = p->link;
    }
}
