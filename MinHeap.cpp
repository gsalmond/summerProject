//
// Created by gray on 12/12/17.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "MinHeap.h"
#include "Symbol.h"

using namespace std;

template <class T>
MinHeap<T>::MinHeap(std::vector<Symbol<T>> &symbols) {
    for (auto && sym : symbols) {
        insertHeap(sym);
    }
}

template<class T>
void MinHeap<T>::insertHeap(Symbol<T> sym) {
    data.push_back(sym);
}

template<class T>
void MinHeap<T>::printHeap() {
    cout << setw(6);
    //display tallies
    for (int i = 0; i < 256; i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << data[i].getCount() << ", ";

    }
    cout << endl;
}

template class MinHeap<char>;