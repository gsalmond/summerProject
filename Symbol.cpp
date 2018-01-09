//
// Created by gray on 11/12/17.
//

#include "Symbol.h"

//Symbol initialised with the symbol of type T and the occurrence of the symbol
template<class T>
Symbol<T>::Symbol(T sym):sym(sym) { count = 0; internalNode = false; }


//Internal node initialised to counts of the symbols/nodes it's pointing to

//Returns the symbol
template<class T>
T Symbol<T>::getSym() const {
    return sym;
}

//Returns occurrences of the symbol
template<class T>
long long Symbol<T>::getCount() const {
    return count;
}

//Pre increment operator for the count of the symbol
template<class T>
long long& Symbol<T>::operator++() {
    ++count;
    return count;
}

template<class T>
Symbol<T>::Symbol(bool isNode, long long count) {

}

template class Symbol<char>;
template class Symbol<int>;
template class Symbol<long>;
template class Symbol<long long>;