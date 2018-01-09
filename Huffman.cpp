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
    //... implementing own minheap for practice/academic purposes
    for(auto&& symbolNode : initialNodes) {
        insertHuffmanTree(symbolNode);
    }

    //construct huffman tree

    //keep constructing tree until there is a single root node
//    while(huffmanTree.size() > 1) {
//
//    }

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
        parent = (i-1)/2; //formula to find parent node in a heap
        //swap if needed
        if(huffmanTree[i]->count < huffmanTree[parent]->count) {
            symbolNode<T>* temp = huffmanTree[parent];
            huffmanTree[parent] = huffmanTree[i];
            huffmanTree[i] = temp;
            i = (i-1)/2;
        } else { break; } //otherwise in correct position
    }
}

template<class T>
symbolNode<T> *Huffman<T>::deleteHuffmanNode() {
    symbolNode<T>* toReturn = huffmanTree[0];
    if(toReturn == nullptr) { throw "Error deleting Huffman tree node"; }

    //start to repair minheap after a delete
    long lastIndex = huffmanTree.size()-1;
    huffmanTree[0] = huffmanTree[lastIndex];
    huffmanTree.erase(huffmanTree.begin() + lastIndex);
    lastIndex--;

    long parentIndex = 0;
    long leftChildIndex;
    long rightChildIndex;
    long smallestChildIndex;

    while(true) {
        leftChildIndex = parentIndex*2+1;
        rightChildIndex = parentIndex*2+2;

        if(leftChildIndex > lastIndex) { break; }  //stop when the heap is fixed

        if(rightChildIndex > lastIndex) { smallestChildIndex = leftChildIndex; } //if no right node left is smallest
        else { //return smallest child index between left and right
            smallestChildIndex = (huffmanTree[leftChildIndex]->count <= huffmanTree[rightChildIndex]->count) ?
                                 leftChildIndex : rightChildIndex;
        }


        //swap nodes if needed, set next parent index for next iteration
        if(huffmanTree[parentIndex]->count > huffmanTree[smallestChildIndex]->count) {
            symbolNode<T>* temp = huffmanTree[parentIndex];
            huffmanTree[parentIndex] = huffmanTree[smallestChildIndex];
            huffmanTree[smallestChildIndex] = temp;
            parentIndex = smallestChildIndex;
        } else { break; } //stop when heap is fixed

    }
    return toReturn;
}

template class Huffman<char>;
template class Huffman<int>;
template class Huffman<long>;
template class Huffman<long long>;