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

    //TODO add each character to the heap tallying up occurrences of each character

    //an array of number of tallies a symbol appears in a file
    long tallies[256];
    //initialise tallies
    for (auto &&item : tallies) {
        item = 0;
    }

    //copying file into output file
    outFile.open(outStr);
    char c;
    outFile << "This is different" << endl;
    while(inFile.get(c)) {
        outFile << c;
        ++tallies[(int)c];
    }

    //display tallies
    for (int i = 0; i < 256; ++i) {
        cout << i << ": " << tallies[i] << ", ";
        if(i % 10 == 0 && i != 0) { cout << endl; }
    }

    //close files when finished
    inFile.close();
    outFile.close();
}
