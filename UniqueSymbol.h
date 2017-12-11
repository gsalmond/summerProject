//
// Created by gray on 11/12/17.
//

#ifndef SUMMERPROJECT_UNIQUESYMBOL_H
#define SUMMERPROJECT_UNIQUESYMBOL_H

template <class T>
class UniqueSymbol {
public:
    UniqueSymbol<T>(T sym, long long int count);
    T sym;
    long long int count;
};


#endif //SUMMERPROJECT_UNIQUESYMBOL_H
