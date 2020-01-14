//
// Created by ori on 13/01/2020.
//

#ifndef EX4_SEARCHABLECREATOR_H
#define EX4_SEARCHABLECREATOR_H

#include "Searchable.h"
#include <string>
#include <vector>

template<typename T>
class SearchableCreator {
public:
    virtual Searchable<T> *create(vector<vector<string>>) = 0;

};




#endif //EX4_SEARCHABLECREATOR_H
