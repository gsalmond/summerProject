//
// Created by gray on 11/12/17.
//

#ifndef SUMMERPROJECT_SYMBOL_H
#define SUMMERPROJECT_SYMBOL_H

template <class T>
class Symbol {
public:
    Symbol(T sym, long long int count);
    T getSym() const;
    long long int getCount() const;
private:
    T sym;
    long long int count;
};


#endif //SUMMERPROJECT_SYMBOL_H
