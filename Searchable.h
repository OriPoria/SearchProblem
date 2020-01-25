//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template<typename T>
class Searchable {
public:
    virtual State<T> *getInitialState() = 0;

    virtual bool isGoalState(State<T> *state) = 0;

    virtual vector<State<T> *> getAllPossibleStates(State<T> *) = 0;

};


#endif //EX4_SEARCHABLE_H
