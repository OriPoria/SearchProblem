//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template <typename T>
class Searchable {
     virtual State<T> getInitialState() = 0;
     virtual bool isGoalState(State<T> state) = 0;
     virtual vector<State<T>> getAllPossibleStates(State<T>) = 0;

};




template <typename T>
class Matrix : public Searchable<square> {
private:
    vector<vector<State<square>>> matrix;
    State<square>* initialState;
    State<square>* goalState;

public:
    Matrix(vector<vector<State<square>>> m, State<square> ini, State<square> goal) {

    }

    State<square> getInitialState() {

    }
    bool isGoalState(State<square> state) {


    }
    vector<State<square>> getAllPossibleStates(State<square>) {

    }
};


#endif //EX4_SEARCHABLE_H
