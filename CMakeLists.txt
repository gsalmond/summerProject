cmake_minimum_required(VERSION 3.8)
project(summerProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp Huffman.cpp Huffman.h)

add_executable(summerProject ${SOURCE_FILES})