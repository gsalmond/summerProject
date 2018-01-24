// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>

#include "Huffman.h"

using namespace std;

int main (int argc, char* argv[]) {

    string fileArgument {};
    if(argc != 2) {
        cout << "Filename not included as argument." << endl;
        fileArgument = "../alice29.txt"; // remove this eventually
        //return 0;
    } else {
        fileArgument = string(argv[1]);
    }

    //    string inStr = "alice29.txt";
    //    string outStr = "alice29.huffCode";
    string inStr = "../alice29.txt";
    string outStr = "../alice29.huffCode";

    //calling compression algorithm on file(s) to be compressed
    Huffman<char> huffCompress;
    if(fileArgument.find(".huffCode") == string::npos) {
        cout << "This";
        huffCompress.encode(inStr);
        huffCompress.decode(outStr);
    } else {
        cout << "Not this";
        huffCompress.decode(fileArgument);
    }

    //TODO display statistics for compressed and decompressed file, perform check to see decoded file matches original
    //... push this functionality into compression classes
    //system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

    cout << endl << endl;
}
