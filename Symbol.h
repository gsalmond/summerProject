//
// Created by gray on 11/12/17.
//

#ifndef SUMMERPROJECT_SYMBOL_H
#define SUMMERPROJECT_SYMBOL_H

//Defines a unique symbol for data compression purposes
//... Contains the symbol and number of occurrences in a file for the symbol
template <class T>
class Symbol {
public:
    //Symbol initialised with the symbol of type T and the occurrence of the symbol
    explicit Symbol(T sym);
    //Returns the symbol
    T getSym() const;
    //Returns the count of the symbol
    long long int getCount() const;
    //Pre increment operator for the count of the symbol
    long long int& operator++();
private:
    //Represents a unique symbol of a file
    T sym;
    //Occurrence of the symbol in a file
    long long int count;
};


#endif //SUMMERPROJECT_SYMBOL_H