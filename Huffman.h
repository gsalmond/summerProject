//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#ifndef SUMMERPROJECT_HUFFMAN_H
#define SUMMERPROJECT_HUFFMAN_H

// represents a unique symbol of a file
template <class T>
struct symbolNode {
    T symbol = 0;
    bool isInternalNode = false;
    unsigned long long count = 0;
    symbolNode<T>* leftPtr = nullptr;
    symbolNode<T>* rightPtr = nullptr;
};

//performs Huffman compression coding on a file and creates a .huffCode file of the same name
template <class T>
class Huffman {
public:
    // encode a file with huffman's code
    void encode(const std::string &inStr);
    // decode an encoded file
    void decode(const std::string &fileStr);
private:
    //file to compress
    std::ifstream inFile;
    //initial vector for counting up occurrences of a symbol in a file(s)
    std::vector<symbolNode<T>*> initialNodes;
    //min heap to become a huffman tree
    std::vector<symbolNode<T>*> huffmanTree;
    //vector<bool> representation of compressed file
    std::vector<bool> compressed;
    //map of codes for individual symbols
    std::map<T, std::vector<bool>> codeMap;
    //insert an element into Huffman tree (minheap)
    void insertHuffmanTree(symbolNode<T>* nodeToInsert);
    //delete a node and return a pointer to that node
    symbolNode<T>* deleteHuffmanNode();
    //build Huffman tree from minheap of symbol node occurrences
    void buildTree();
    //traverse and output Huffman tree codes
    void outputTree(symbolNode<T>* node, std::vector<bool> code);
    //take a symbol and push its bit representation onto vector<bool> compressed
    void convertToBits(T element);
    // builds prebuilt tree from encoded file
    symbolNode<T>* decodeTree(int& i);
    // returns number of bits in a symbol
    unsigned long long bitsInSymbol(unsigned long long bytes);
    // creates a compressed file using vector<bool> compressed
    void createCompressed(const std::string& inStr) const;
};

#endif //SUMMERPROJECT_HUFFMAN_H
