//
// Created by gray on 11/12/17.
//

#include "Symbol.h"

template<class T>
Symbol<T>::Symbol(T sym):sym(sym) { count = 0; }

template<class T>
T Symbol<T>::getSym() const {
    return sym;
}

template<class T>
long long int Symbol<T>::getCount() const {
    return count;
}

template<class T>
long long int& Symbol<T>::operator++() {
    ++count;
    return count;
}


template class Symbol<char>;
template class Symbol<int>;
template class Symbol<long int>;
template class Symbol<long long int>;