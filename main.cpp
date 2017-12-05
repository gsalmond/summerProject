#include <iostream>
#include <fstream>

#include "test.h"

using namespace std;

int main () {
    ifstream inFile("../cantCorpus/alice29.txt");
    ofstream outFile("../cantCorpus/alice29.huffCode");
    if(!inFile.is_open()) { cout<< "Error"; exit(EXIT_FAILURE); }

    char c;
    outFile << "This is different" << endl;
    while(inFile.get(c)) {
        outFile << c;
        //cout << c;
    }


    inFile.close();
    outFile.close();

    system("diff ../cantCorpus/alice29.txt ../cantCorpus/alice29.huffCode");

    test blah;
    cout << "Hello World" << endl;
    cout << blah.f();
}
