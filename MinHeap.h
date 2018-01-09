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
    void printHeap();
private:
    std::vector<Symbol <T>> data;
    void insertHeap(Symbol<T> sym);
    void buildHuffmanTree();
//    Symbol<T> deleteHeapRoot();
};

#endif //SUMMERPROJECT_MINHEAP_H
