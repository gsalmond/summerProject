//
// Created by gray on 11/12/17.
//

#include "Symbol.h"

template<class T>
Symbol<T>::Symbol(T sym, long long int count):sym(sym), count(count) {}

template<class T>
T Symbol<T>::getSym() const {
    return sym;
}

template<class T>
long long int Symbol<T>::getCount() const {
    return count;
}

template class Symbol<char>;
template class Symbol<int>;
template class Symbol<long int>;
template class Symbol<long long int>;