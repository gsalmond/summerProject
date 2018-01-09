//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Huffman.h"
#include "Symbol.h"
#include "MinHeap.h"

using namespace std;

//performs Huffman compression coding on a file and creates a .huffCode file of the same name
template <class T>
Huffman<T>::Huffman(const string &inStr, const string &outStr) {

    //open file, check exists
    inFile.open(inStr);
    if(!inFile.is_open()) {
        cout << "Error opening file: " + inStr;
        exit(EXIT_FAILURE);
    }

    //initialise vector of every symbol
    vector<Symbol<char>> syms;
    for(int i = 0; i < 256; ++i) {
        Symbol<char> nextSym((char)i);
        syms.push_back(nextSym);
    }

    ///////////////////////////
    //DELETE THIS EVENTUALLY
    //an array of number of tallies a symbol appears in a file
    long tallies[256];
    //initialise tallies
    for (auto &&item : tallies) {
        item = 0;
    }
    ///////////////////////////

    //go through file and count occurrence of each symbol
    //copying file into output file
    outFile.open(outStr);
    char c;
    while(inFile.get(c)) {
        outFile << c;
        ///////////////////////////
        ++tallies[(int)c]; //DELETE
        ///////////////////////////
        //treating each symbol as a number for indexing vector
        ++syms[(int)c];
    }

    ////////////////////////////
    //CAN DELETE THIS EVENTUALLY
    cout << setw(6);
    //display tallies
    for (int i = 0; i < 256; i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << tallies[i] << ", ";

    }
    cout << endl;
    ////////////////////////////

    //Take vector of counted Symbols and create a Huffman tree
    MinHeap<char> heap(syms);
    heap.printHeap();

    //TODO create output file

    inFile.close();
    outFile.close();
}

template class Huffman<char>;
template class Huffman<int>;
template class Huffman<long>;
template class Huffman<long long>;