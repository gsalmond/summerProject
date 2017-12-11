// 159.333 Programming Project Summer School 2017
// File compressor based on Huffman's code
// Author: Gray Salmond <graysalmond@hotmail.com>

#include <iostream>
#include <vector>

#include "Huffman.h"
#include "Symbol.h"
#include "MinHeap.h"

using namespace std;

int main () {

    //TODO eventually grab file(s) to compress from command line arguments
    //     possibly extend to allow various compression algorithms and options
    string inStr = "../cantCorpus/alice29.txt";
    string outStr = "../cantCorpus/alice29.huffCode";

    //TODO allow selection of different compression algorithms

    //calling compression algorithm on file(s) to be compressed
    Huffman huffCompress(inStr, outStr);

    //TODO display statistics for compressed and decompressed file, perform check to see decoded file matches original
    //... push this functionality into compression classes
    //system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

    Symbol <char> x('4', 44);
    vector<Symbol <char>> thingy;
    thingy.push_back(x);
    MinHeap<char> test(thingy);

    cout << x.getSym() << " " << x.getCount() << " " << thingy[0].getCount() << " " << test.data[0].getCount();

    cout << endl << endl;

    //test.printHeap();
}
