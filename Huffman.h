//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <string>

#ifndef SUMMERPROJECT_HUFFMAN_H
#define SUMMERPROJECT_HUFFMAN_H

//performs Huffman compression coding on a file and creates a .huffCode file of the same name
class Huffman {
public:
    Huffman(const std::string &inStr, const std::string &outStr);

private:
    std::ifstream inFile;
    std::ofstream outFile;
};


#endif //SUMMERPROJECT_HUFFMAN_H
