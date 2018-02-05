// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>

#include "Huffman.h"

using namespace std;

int main (int argc, char* argv[]) {

        string fileArgument {};
    bool both = false;
    if(argc == 2) {
        fileArgument = string(argv[1]);
    } else if (argc == 3 && string(argv[1]) == "-b") { // allow both encoding and decoding for demonstration
        fileArgument = string(argv[2]);
        both = true;
    } else {
        cout << "Arguments not valid, enter a single file name or option and a file name" << endl;
        exit(EXIT_FAILURE);
    }
//    fileArgument = "../a.out";
//    both = true;

    //calling compression algorithm on file(s) to be compressed
    Huffman<unsigned char> huffCompress;
    if(fileArgument.find(".huffCode") == string::npos) {
        cout << "Encoding file: " + fileArgument << endl;
        huffCompress.encode(fileArgument);
        if(both) {
            cout << "Decoding file: " + fileArgument + ".huffCode" << endl;
            huffCompress.decode(fileArgument + ".huffCode");
        }
    } else {
        cout << "Decoding file: " + fileArgument << endl;
        huffCompress.decode(fileArgument);
    }
    cout << endl;
}
