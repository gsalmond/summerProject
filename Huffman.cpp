//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "Huffman.h"

using namespace std;

// encodes/compresses a file using Huffman's code
template<class T>
void Huffman<T>::encode(const std::string &inStr, const std::string &outStr) {
    const int UNIQUE_SYMBOLS = bitsInSymbol(sizeof(T));
    if(UNIQUE_SYMBOLS != 256) { cout << "Error with expected symbol size" << UNIQUE_SYMBOLS; exit(EXIT_FAILURE); }

    inFile.open(inStr);
    if(!inFile.is_open()) {
        cout << "Error opening file: " + inStr;
        exit(EXIT_FAILURE);
    }

    //initialise vector of every symbol
    for(int i = 0; i < UNIQUE_SYMBOLS; ++i) {
        auto* temp = new symbolNode<T>;
        temp->symbol = (T)i; // casting to create each symbol
        initialNodes.push_back(temp);
    }

//    ///////////////////////////
//    //DELETE THIS EVENTUALLY
//    //an array of number of tallies a symbol appears in a file
//    long tallies[256];
//    //initialise tallies
//    for (auto &&item : tallies) {
//        item = 0;
//    }
//    ///////////////////////////

    //go through file and count occurrence of each symbol
    //copying file into output file
    char c;
    while(inFile.get(c)) {
        //outFile << c;
//        ///////////////////////////
//        ++tallies[(int)c]; //DELETE
//        ///////////////////////////
        //treating each symbol as a number for indexing vector
        initialNodes[c]->count++;
    }

//    ////////////////////////////
//    //CAN DELETE THIS EVENTUALLY
//    cout << setw(6);
//    //display tallies
//    for (int i = 0; i < 256; i++) {
//        if(i % 10 == 0 && i != 0) { cout << endl; }
//        cout << setw(4) << i << ": " << setw(6) << tallies[i] << ", ";
//
//    }
//    cout << endl;
//    ////////////////////////////

    //insert every symbol into minheap
    //... implementing own minheap for practice/academic purposes
    for(auto&& symbolNode : initialNodes) { insertHuffmanTree(symbolNode); }

    //construct huffman tree
    buildTree();

    //traverse tree, print out
    outputTree(huffmanTree[0], vector<bool>());

//    for(auto element : compressed) {
//        cout << element;
//    }

//    cout << setw(6);
//    //display tallies
//    for (int i = 0; i < initialNodes.size(); i++) {
//        if(i % 10 == 0 && i != 0) { cout << endl; }
//        cout << setw(4) << i << ": " << setw(6) << initialNodes[i]->count << ", ";
//    }
//    cout << endl;
//    for (int i = 0; i < huffmanTree.size(); i++) {
//        if(i % 10 == 0 && i != 0) { cout << endl; }
//        cout << setw(4) << i << ": " << setw(6) << huffmanTree[i]->count << ", ";
//    }
//    cout << endl;
//
//    cout << "Printing tree in compressed form: " << endl;
//    for(auto element : compressed) {
//        cout << element;
//    }
//
//    cout << endl << "Printing map of codes" << endl;
//    for(auto elem : codeMap) {
//        cout << elem.first << " ";
//        for(auto x : elem.second) {
//            cout << x;
//        }
//        cout << endl;
//    }

    //build up vector<bool> compressed
    //... using codeMap<T, vector<bool>> and file symbols
    inFile.close();
    inFile.open(inStr);
    while(inFile.get(c)) {
        for(auto elem : codeMap[c]) {
            compressed.push_back(elem);
        }
    }

//    cout << "Printing tree file in bits: " << endl;
//    for(auto element : compressed) {
//        cout << element;
//    }

    inFile.close();

    cout << endl << "Printing tree size: " << compressed.size() << " Including offset bits: " << compressed.size()+3
         << " Additional bits: " << ((compressed.size()+3)%8) << " Size in bytes: " << ((compressed.size()+3)/8) << endl;

    //create compressed file
    createCompressed();
}

// creates compressed file using vector<bool> compressed
template<class T>
void Huffman<T>::createCompressed() const {

    ofstream compressedFile("../alice29.huffCode");

    const int HEADER_BITS = 3; // number of bits used in compressed file to represent extra bits
    const int HEADER_AND = 7; // used with bitwise & to get header bits from compressed file
    const int BYTE_BITS = 8; // number of bits in a byte
    auto extraBits = (unsigned char)((compressed.size() + HEADER_BITS) % BYTE_BITS);
    auto builtChar = (unsigned char)(extraBits & HEADER_AND); // adding header bits to front of compressed file
    builtChar = builtChar << (BYTE_BITS-HEADER_BITS); // shift header bits to correct position

    int shift = BYTE_BITS-HEADER_BITS-1; // where to place the first bit for the compressed file after header bits
    const unsigned char one = 1;
    for(auto bit : compressed) {
        if(bit) { builtChar = builtChar | (one << shift); } // place bit in compressed file if set
        if(shift == 0) { // once a full byte is built add it to file and start building next byte
            compressedFile << builtChar;
            shift = 7;
            builtChar = 0;
        } else { shift--; }
    }
    // deal with extra bits
    if(extraBits) { compressedFile << builtChar; }

    compressedFile.close();
}

// builds Huffman tree, continues until there is a single node
template<class T>
void Huffman<T>::buildTree() {
    while(huffmanTree.size() > 1) {
        //grab first node
        symbolNode<T>* firstNode = deleteHuffmanNode();
        //grab second node
        symbolNode<T>* secondNode = deleteHuffmanNode();
        //create new internal node
        auto newNode = new symbolNode<T>;
        newNode->count = firstNode->count + secondNode->count;
        newNode->leftPtr = firstNode;
        newNode->rightPtr = secondNode;
        newNode->isInternalNode = true;
        insertHuffmanTree(newNode);
    }
}

// inserts an element into Huffman tree (minheap)
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

// returns root element of Huffman tree minheap
// ... removes element from minheap and then fixes minheap
template<class T>
symbolNode<T> *Huffman<T>::deleteHuffmanNode() {
    // root element is the element to return
    symbolNode<T>* toReturn = huffmanTree[0];
    if(toReturn == nullptr) { throw "Error deleting Huffman tree node"; }

    // proceed to delete root node from tree
    long lastIndex = huffmanTree.size()-1;
    huffmanTree[0] = huffmanTree[lastIndex];
    huffmanTree.erase(huffmanTree.begin() + lastIndex);
    lastIndex--;

    //start to repair minheap after a delete
    long parentIndex = 0;
    long leftChildIndex;
    long rightChildIndex;
    long smallestChildIndex;

    while(true) {
        // find index of left and right child nodes
        leftChildIndex = parentIndex*2+1;
        rightChildIndex = parentIndex*2+2;

        // if child nodes element is in correct position
        if(leftChildIndex > lastIndex) { break; }

        // find smallest node out of left and right child nodes
        if(rightChildIndex > lastIndex) { smallestChildIndex = leftChildIndex; } //if no right node, left is smallest
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

// recursively traverses Huffman tree to generate codes
// ... building compressed version of tree for vector<bool> compressed
// ... and building map of symbols and their codes for next pass of file to be compressed: map<T, vector<bool>> codeMap
template<class T>
void Huffman<T>::outputTree(symbolNode<T>* node, vector<bool> code) {
    // if node is a leaf output encoding
    if(!node->isInternalNode) {
        compressed.push_back(true); // 1 (true) symbolizes the following is a symbol
        convertToBits(node->symbol); // appends the bit representation of nodes symbol to compressed
        codeMap[node->symbol] = code; // code is now correct for this leaf, add to map of codes for symbols
        return;
    } else { compressed.push_back(false); } // 0 (false) symbolizes an internal node
    // if node is not a leaf go left then right
    if(node->leftPtr != nullptr) {
        vector<bool> left = code;
        left.push_back(false); // 0 (false) representing left
        outputTree(node->leftPtr, left);
    }
    if(node->rightPtr != nullptr) {
        vector<bool> right = code;
        right.push_back(true); // 1 (true) representing right
        outputTree(node->rightPtr, right);
    }
}

//converts a symbol to individual bits to be appended to vector<bool> compressed
//... doesn't work with bool elements
template<class T>
void Huffman<T>::convertToBits(T element) {
    int bits = sizeof(T)*8;
    T currentBit;
    for(int i = 0; i < bits; ++i) {
        currentBit = 1 << (bits-i-1);
        if(element & currentBit) { compressed.push_back(true); }
        else { compressed.push_back(false); }
    }
}

// decode an encoded file
template<class T>
void Huffman<T>::decode() {
    ifstream encoded("../alice29.huffCode");
    if(!encoded.is_open()) { exit(EXIT_FAILURE); }

    compressed.clear();
    codeMap.clear();

    // build vector compressed<bool> using convertToBits(T x)
    char x;
    while(true) {
        encoded.get(x);
        if (encoded.eof()) { break; }
        convertToBits(x);
    }
    encoded.close();

    //calculate extra bits from first 3 bits
    int extraBits = 0;
    if(compressed[0]) { extraBits += 4; }
    if(compressed[1]) { extraBits += 2; }
    if(compressed[2]) { extraBits += 1; }
    //remove extra bits from vector of bits (bool) compressed
    if(extraBits) { compressed.erase(compressed.end()-(8-extraBits),compressed.end()); }

    cout << "Printing read in file after being compressed";
    for(auto elem : compressed) { cout << elem; }
    cout << endl;

    int encodingStarts = 3; //starting at index 3 after the initial header bits find where tree ends and encoding begins
    symbolNode<T>* root = decodeTree(encodingStarts);
    cout << endl << "Encoding starts at: " << encodingStarts << endl;

    //start building decoded file
    ofstream decoded("../alice29.decoded");
    if(!decoded.is_open()) { exit(EXIT_FAILURE); }
    int i = encodingStarts;
    symbolNode<T>* current = root;

    //go through encoded file and decode using Huffman tree in encoded file
    while(i < compressed.size()) {
        if(compressed[i] == false) { current = current->leftPtr; } // false representing left
        else { current = current->rightPtr; } // go right
        ++i;
        if(!current->isInternalNode) {
            decoded << current->symbol;
            current = root;
        }
    }
    decoded.close();
}

// builds prebuilt tree from encoded file
template<class T>
symbolNode<T>* Huffman<T>::decodeTree(int& i) {
    auto node = new symbolNode<T>;
    bool isLeaf = compressed[i];
    if(isLeaf) {
        T symbol = 0;
        int shift = sizeof(T) * 8 - 1;
        while(shift >= 0) {
            i++;
            symbol = symbol | ((T)compressed[i] << shift);
            shift--;
        }
        i++;
        node->symbol = symbol;
        return node;
    }
    //otherwise node is internal node that points to other nodes
    node->isInternalNode = true;
    i++;
    node->leftPtr = decodeTree(i);
    node->rightPtr = decodeTree(i);
}

template<class T>
int Huffman<T>::bitsInSymbol(int bytes) {
    const int numBits = 8 * bytes;
    int result {1};
    for(int i {}; i < numBits; ++i) { result *= 2; }
    return result;
}

template class Huffman<char>;
template class Huffman<int>;
template class Huffman<long>;
template class Huffman<long long>;