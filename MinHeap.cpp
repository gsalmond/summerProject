//
// Created by gray on 12/12/17.
//

#include <vector>

#include "MinHeap.h"
#include "Symbol.h"

using namespace std;

template <class T>
MinHeap<T>::MinHeap(std::vector<Symbol<T>> &symbols) {
    data.push_back(symbols[0]);
}

template class MinHeap<char>;