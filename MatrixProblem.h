//
// Created by ori on 14/01/2020.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include <vector>
#include "State.h"
#include "Searchable.h"

template <typename T>
class Matrix : public Searchable<T> {
private:
    vector<vector<State<T>*>> matrix;
    State<T>* initialState;
    State<T>* goalState;

public:

    Matrix(vector<vector<State<T>*>> m, State<T>* ini, State<T>* goal) {
        this->matrix = m;
        this->initialState = ini;
        this->goalState = goal;
    }


    State<T> getInitialState() {

    }
    bool isGoalState(State<T> state) {


    }
    vector<State<T>> getAllPossibleStates(State<T>) {

    }
};


#endif //EX4_MATRIXPROBLEM_H
