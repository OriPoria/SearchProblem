//
// Created by ori on 14/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <string>
#include "Searchable.h"
#include "Searcher.h"


template <typename T,typename S>
class BFS : public Searcher<T,S> {
public:
    virtual S search(Searchable<T>*) {

        string s = "in searcher solution";
        return s;
    }
};


#endif //EX4_BFS_H
