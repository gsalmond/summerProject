# 159.333 Programming Project Makefile for File Compressor based on 
# Huffman's code Author: Gray Salmond <graysalmond@hotmail.com>

huffCode: main.o
	g++ main.o -o huffCode

main.o: main.cpp
	g++ -c main.cpp

