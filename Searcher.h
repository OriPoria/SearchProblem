//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
#include <string>

template<typename T, typename S>
class Searcher {
public:
    virtual S search(Searchable<T> *) = 0;

    virtual int getNumOfNodesEvaluated() = 0;

    virtual Searcher<T, S> *clone() = 0;
};


#endif //EX4_SEARCHER_H
