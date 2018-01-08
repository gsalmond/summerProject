//
// Created by gray on 12/12/17.
//

#include <iostream>
#include <vector>
#include <iomanip>

#include "MinHeap.h"

using namespace std;

template <class T>
MinHeap<T>::MinHeap(std::vector<Symbol<T>> &symbols) {
    for (auto && sym : symbols) {
        insertHeap(sym);
    }
}

template<class T>
void MinHeap<T>::insertHeap(Symbol<T> sym) {
    //if there are no occurrences of symbol it is not needed
    if(sym.getCount() == 0) { return; }

    //push symbol to back of heap
    data.push_back(sym);

    //make heap valid minheap

    //index of the last element
    unsigned long i = data.size() - 1;
    unsigned long parent;
    //keep moving element up the minheap until in right position
    while(i > 0) {
        //formula to find parent node in a heap
        parent = (i-1)/2;
        //swap if needed
        if(data[i].getCount() < data[parent].getCount()) {
            Symbol<T> temp = data[parent];
            data[parent] = data[i];
            data[i] = temp;
            i = (i-1)/2;
        } else { break; } //otherwise in correct position
    }
}

template<class T>
void MinHeap<T>::printHeap() {
    cout << setw(6);
    //display tallies
    for (int i = 0; i < data.size(); i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << data[i].getCount() << ", ";

    }
    cout << endl;
}

template class MinHeap<char>;