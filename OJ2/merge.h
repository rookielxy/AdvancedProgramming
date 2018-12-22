#ifndef _MERGE_H
#define _MERGE_H

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

template <class T>
T* merge(T* a1, size_t sz1, T* a2, size_t sz2) {
    auto res = new T[sz1 + sz2];
    int idx = 0;
    for(int i = 0; i < sz1; ++i, ++idx)
        res[idx] = a1[i];
    for(int i = 0; i < sz2; ++i, ++idx)
        res[idx] = a2[i];
    sort(res, res + sz1 + sz2);
    return res;
}

#endif
