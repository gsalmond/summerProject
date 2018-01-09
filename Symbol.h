//
// Created by gray on 11/12/17.
//

#ifndef SUMMERPROJECT_SYMBOL_H
#define SUMMERPROJECT_SYMBOL_H


//Defines a unique symbol or node for data compression purposes
//... Contains the symbol and number of occurrences in a file for the symbol
template <class T>
class Symbol {
public:
    //Symbol initialised with the symbol of type T and the occurrence of the symbol
    explicit Symbol(T sym);
    //Internal node initialised to counts of the symbols/nodes it's pointing to
    explicit Symbol(bool isNode, long long count);
    //Returns the symbol
    T getSym() const;
    //Returns the count of the symbol
    long long getCount() const;
    //Pre increment operator for the count of the symbol
    long long & operator++();
private:
    //True if represents an internal node and not an actual symbol
    bool internalNode;
    //Represents a unique symbol of a file
    T sym;
    //Occurrence of the symbol in a file
    long long count;
};


#endif //SUMMERPROJECT_SYMBOL_H