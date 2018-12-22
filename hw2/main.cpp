#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    q1.show();
    Queue<string> q2;
    q2.push("test");
    q2.push("queue");
    q2.push("template");
    cout << q2.front() << endl;
    q2.pop();
    q2.show();
    return 0;
}