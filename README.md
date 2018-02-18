# summerProject

Command line file compressor based on Huffman's code.
For Massey University 159.333 - Programming Project Summer School 2017
Author: Gray Salmond <graysalmond@hotmail.com>

To build project

    First install required packages

        sudo apt install g++

    Build the project

        g++ -o huffman.out main.cpp huffman.h huffman.cpp

To run project (Linux/OSX)

        ./huffman.out [-b] <file to compress>

        -b flag will perform both encoding and decoding
        otherwise a file without .huffCode suffix will be encoded
        a file with .huffCode suffix will be decoded