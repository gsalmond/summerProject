#include <iostream>
#include <fstream>

#include "test.h"

using namespace std;

int main () {
    ifstream inFile("../main.cpp");
    ofstream outFile("../main.huffCode");
    if(!inFile.is_open()) { cout<< "Error"; exit(EXIT_FAILURE); }

    char c;
    outFile << "This is different" << endl;
    while(inFile.get(c)) {
        outFile << c;
        cout << c;
    }


    inFile.close();
    outFile.close();

    system("diff ../main.cpp ../main.huffCode");

    test blah;
    cout << "Hello World" << endl;
    cout << blah.f();
}
