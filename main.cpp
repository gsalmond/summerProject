// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>

#include "Huffman.h"

using namespace std;

int main (int argc, char* argv[]) {

    // parse command line arguments
    cout << "argc: " << argc << endl;
    for(int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }
    //TODO eventually grab file(s) to compress from command line arguments
    //     possibly extend to allow various compression algorithms and options
//    string inStr = "alice29.txt";
//    string outStr = "alice29.huffCode";
    string inStr = "../alice29.txt";
    string outStr = "../alice29.huffCode";

    //TODO allow selection of different compression algorithms

    //calling compression algorithm on file(s) to be compressed
    Huffman<char> huffCompress;
    huffCompress.encode(inStr, outStr);
    huffCompress.decode();

    //TODO display statistics for compressed and decompressed file, perform check to see decoded file matches original
    //... push this functionality into compression classes
    //system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

    cout << endl << endl;
}
