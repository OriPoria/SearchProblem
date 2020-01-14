//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include <string>

template <typename T>
class Searcher {
public:
    virtual string search(Searchable<T>*) = 0;
};


template <typename T>
class BFS : public Searcher<T> {
public:
    virtual string search(Searchable<T>*) {

        string s = "in searcher solution";
        return s;
    }
};


#endif //EX4_SEARCHER_H
