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
    ifstream inFile(inStr);
    if(!inFile.is_open()) {
        cout << "Error opening passed filename: " + inStr;
        exit(EXIT_FAILURE);
    }

    //copying file into output file
    ofstream outFile(outStr);
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
