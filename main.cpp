// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>

#include "Huffman.h"

using namespace std;

int main () {

    //TODO eventually grab file(s) to compress from command line arguments
    //     possibly extend to allow various compression algorithms and options
    string inStr = "../cantCorpus/alice29.txt";
    string outStr = "../cantCorpus/alice29.huffCode";

    //calling compression algorithm on file(s) to be compressed
    Huffman compressor(inStr, outStr);

    //TODO display statistics for compressed and decompressed file, perform check to see decoded file matches original
    system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

}
