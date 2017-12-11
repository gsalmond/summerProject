//
// Created by gray on 7/12/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>

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

    cout << setw(6);
    //display tallies
    for (int i = 0; i < 256; i++) {
        if(i % 10 == 0 && i != 0) { cout << endl; }
        cout << setw(4) << i << ": " << setw(6) << tallies[i] << ", ";

    }
    cout << endl;

    //TODO create Huffman tree

    //TODO create output file

    //closing files when finished
    inFile.close();
    outFile.close();
}
