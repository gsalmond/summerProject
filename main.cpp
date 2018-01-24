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
        return 0;
    } else {
        fileArgument = string(argv[1]);
    }

    string outStr = "../alice29.txt.huffCode";

    //calling compression algorithm on file(s) to be compressed
    Huffman<char> huffCompress;
    if(fileArgument.find(".huffCode") == string::npos) {
        cout << "This";
        huffCompress.encode(fileArgument);
        huffCompress.decode(outStr);
    } else {
        cout << "Not this";
        huffCompress.decode(fileArgument);
    }
    cout << endl;
}
