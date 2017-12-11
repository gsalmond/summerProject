//
// Created by gray on 12/12/17.
//

#include <iostream>
#include <vector>

#include "MinHeap.h"
#include "Symbol.h"

using namespace std;

template <class T>
MinHeap<T>::MinHeap(std::vector<Symbol<T>> &symbols) {
    for (auto && sym : symbols) {
        std::cout << "TEST" << sym.getCount() << " ";
        data.push_back(sym);
        insertHeap(sym);
    }
}

template<class T>
void MinHeap<T>::insertHeap(Symbol<T> sym) {
    data.push_back(sym);
}

template<class T>
void MinHeap<T>::printHeap() {
    for (auto && sym : data) {
        std::cout << "Printing heap" << sym.getSym() << " " << sym.getCount() << std::endl;
    }
}

template class MinHeap<char>;