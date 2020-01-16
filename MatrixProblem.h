//
// Created by ori on 14/01/2020.
//

#ifndef EX4_MATRIXPROBLEM_H
#define EX4_MATRIXPROBLEM_H

#include <vector>
#include "State.h"
#include "Searchable.h"
#include <iterator>


class MatrixProblem : public Searchable<square*> {
private:
    State<square*>*** matrix;
    State<square*>* initialState;
    State<square*>* goalState;
    int height;
    int width;





public:

    MatrixProblem(State<square*>*** m, square* ini, square* goal, int h, int w) {
        this->matrix = m;
        this->initialState = this->matrix[ini->row][ini->column];
        this->goalState = this->matrix[goal->row][goal->column];
        this->height = h;
        this->width = w;


    }


    State< square*> * getInitialState() override {
        return initialState;
    }
    bool isGoalState(State<square*>* state) {
        if (state->getState()->row == goalState->getState()->row && state->getState()->column == goalState->getState()->column) {
            return true;
        }
        return false;


    }
    vector<State<square*>*> getAllPossibleStates(State<square*>* currentState) {
        vector<State<square*> *> neighbors;

        int i = currentState->getState()->row;
        int j = currentState->getState()->column;
        if (i + 1 < height) { neighbors.push_back(matrix[i + 1][j]);}
        if (j + 1 < width) { neighbors.push_back(matrix[i][j + 1]);}
        if (i > 0) { neighbors.push_back(matrix[i - 1][j]);}
        if (j > 0) { neighbors.push_back(matrix[i][j - 1]);}

        return neighbors;
    }




};


#endif //EX4_MATRIXPROBLEM_H
