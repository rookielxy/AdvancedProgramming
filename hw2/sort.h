#ifndef _SORT_H
#define _SORT_H

template <class T>
void sort(T array[], int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size - i - 1; ++j) {
            if(array[j] > array[j + 1]) {
                T temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

#endif
