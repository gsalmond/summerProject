//
// Created by gray on 12/12/17.
//

#ifndef SUMMERPROJECT_MINHEAP_H
#define SUMMERPROJECT_MINHEAP_H

#include <vector>

#include "Symbol.h"

template <class T>
class MinHeap {
public:
    explicit MinHeap(std::vector<Symbol<T>> &symbols);
//private:
    std::vector<Symbol <T>> data;
};

#endif //SUMMERPROJECT_MINHEAP_H
