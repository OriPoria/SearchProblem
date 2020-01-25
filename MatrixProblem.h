//
// Created by ori on 14/01/2020.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include <vector>
#include "State.h"
#include "Searchable.h"
#include <iterator>


class MatrixProblem : public Searchable<square *> {
private:
    State<square *> ***matrix;
    State<square *> *initialState;
    State<square *> *goalState;
    int height;
    int width;


public:

    MatrixProblem(State<square *> ***m, int i, int j, int k, int l, int h, int w) {
        this->matrix = m;
        this->initialState = this->matrix[i][j];
        this->goalState = this->matrix[k][l];
        this->height = h;
        this->width = w;
        //throw exception in case the initial state or the goal state are blocked
        if (this->initialState->getCost() == -1 || this->goalState->getCost() == -1) {
            throw "invalid input";
        }


    }


    State<square *> *getInitialState() override {
        return initialState;
    }

    bool isGoalState(State<square *> *state) {
        if (state->getState()->getRow() == goalState->getState()->getRow() &&
            state->getState()->getColumn() == goalState->getState()->getColumn()) {
            return true;
        }
        return false;


    }

    vector<State<square *> *> getAllPossibleStates(State<square *> *currentState) {
        vector<State<square *> *> neighbors;


        int i = currentState->getState()->getRow();
        int j = currentState->getState()->getColumn();
        if (i + 1 < height) { neighbors.push_back(matrix[i + 1][j]); }
        if (j + 1 < width) { neighbors.push_back(matrix[i][j + 1]); }
        if (i > 0) { neighbors.push_back(matrix[i - 1][j]); }
        if (j > 0) { neighbors.push_back(matrix[i][j - 1]); }

        return neighbors;
    }


};


#endif //EX4_MATRIXPROBLEM_H
