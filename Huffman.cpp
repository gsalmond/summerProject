//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>

#include "Huffman.h"

using namespace std;

//performs Huffman compression coding on a file and creates a .huffCode file of the same name
Huffman::Huffman(const string &inStr, const string &outStr) {

    //open file, check exists
    inFile.open(inStr);
    if(!inFile.is_open()) {
        cout << "Error opening file: " + inStr;
        exit(EXIT_FAILURE);
    }

    //TODO create a heap of symbols comprised of 8 bits each (chars)

    //TODO add each character to the heap tallying up occurrences of each character

    //copying file into output file
    outFile.open(outStr);
    char c;
    outFile << "This is different" << endl;
    while(inFile.get(c)) {
        outFile << c;
        //cout << c;
    }

    //close files when finished
    inFile.close();
    outFile.close();
}
