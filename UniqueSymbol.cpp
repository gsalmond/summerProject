//
// Created by gray on 11/12/17.
//

#include "UniqueSymbol.h"

template<class T>
UniqueSymbol<T>::UniqueSymbol(T sym, long long int count):sym(sym), count(count) {}

template class UniqueSymbol<char>;
template class UniqueSymbol<int>;
template class UniqueSymbol<long int>;
template class UniqueSymbol<long long int>;