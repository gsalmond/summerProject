//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef SUMMERPROJECT_HUFFMAN_H
#define SUMMERPROJECT_HUFFMAN_H

template <class T>
struct symbolNode {
    T symbol = 0;
    bool isInternalNode = false;
    unsigned long long count = 0;
    T* leftPtr = nullptr;
    T* rightPtr = nullptr;
};

//performs Huffman compression coding on a file and creates a .huffCode file of the same name
template <class T>
class Huffman {
public:
    Huffman(const std::string &inStr, const std::string &outStr);
    //file to compress
    std::ifstream inFile;
    //destination of resulting compressed file
    std::ofstream outFile;
    //initial vector for counting up occurrences of a symbol in a file(s)
    std::vector<symbolNode<T>*> initialNodes;
    //min heap to become a huffman tree
    std::vector<symbolNode<T>*> huffmanTree;
    //insert an element into Huffman tree (minheap)
    void insertHuffmanTree(symbolNode<T>* nodeToInsert);
    //delete a node and return a pointer to that node
    symbolNode<T>* deleteHuffmanNode();
};

#endif //SUMMERPROJECT_HUFFMAN_H
