// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>
#include <fstream>

#include "test.h"

using namespace std;

int main () {

    //TODO eventually grab file(s) to compress from command line arguments
    //     possibly extend to allow various compression algorithms and options
    string inStr = "../cantCorpus/alice29.txt";
    string outStr = "../cantCorpus/alice29.huffCode";

    //TODO call Huffman's code compression passing file(s) to be compressed
    ifstream inFile(inStr);
    ofstream outFile(outStr);
    if(!inFile.is_open()) { cout<< "Error"; exit(EXIT_FAILURE); }

    //TODO remove this segment
    char c;
    outFile << "This is different" << endl;
    while(inFile.get(c)) {
        outFile << c;
        //cout << c;
    }

    //TODO move file operations into compression related class
    inFile.close();
    outFile.close();

    //TODO display statistics for compressed and decompressed file, perform check to see decoded file matches original
    system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

    //just testing multiple files
    test blah;
    cout << blah.f();
}
