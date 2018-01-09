//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <vector>

#include "Huffman.h"

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
    long uniqueSymbols = pow(2, sizeof(T) * 8);
    for(long i = 0; i < uniqueSymbols; ++i) {
        auto* temp = new symbolNode<T>;
        temp->symbol = (T)i;
        initialNodes.push_back(temp);
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
        initialNodes[c]->count++;
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

    //insert every symbol into minheap
    for(auto&& symbolNode : initialNodes) {
        insertHuffmanTree(symbolNode);
    }

    //construct huffman tree

    cout << setw(6);
    //display tallies
    for (int i = 0; i < initialNodes.size(); i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << initialNodes[i]->count << ", ";
    }
    cout << endl;
    for (int i = 0; i < huffmanTree.size(); i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << huffmanTree[i]->count << ", ";
    }
    cout << endl;

    //TODO create output file

    inFile.close();
    outFile.close();
}

template<class T>
void Huffman<T>::insertHuffmanTree(symbolNode<T> *nodeToInsert) {
    //if there are no occurrences of symbol it is not needed
    if(nodeToInsert->count == 0) { return; }

    //push symbol node to back of heap
    huffmanTree.push_back(nodeToInsert);

    //make heap valid minheap
    unsigned long i = huffmanTree.size() - 1; //index of the last element
    unsigned long parent;
    //keep moving element up the minheap until in right position
    while(i > 0) {
        //formula to find parent node in a heap
        parent = (i-1)/2;
        //swap if needed
        if(huffmanTree[i]->count < huffmanTree[parent]->count) {
            symbolNode<T>* temp = huffmanTree[parent];
            huffmanTree[parent] = huffmanTree[i];
            huffmanTree[i] = temp;
            i = (i-1)/2;
        } else { break; } //otherwise in correct position
    }
}

template class Huffman<char>;
template class Huffman<int>;
template class Huffman<long>;
template class Huffman<long long>;