//
// Created by ori on 14/01/2020.
//

#ifndef EX4_MATRIXPROBLEMCREATOR_H
#define EX4_MATRIXPROBLEMCREATOR_H

#include "SearchableCreator.h"
#include "State.h"
#include "MatrixProblem.h"
#include <string>
#include <vector>


class MatrixProblemCreator : public SearchableCreator<square> {

public:


    virtual Matrix<square> *create(vector<vector<string>> input) {


        vector<vector<State<struct square> *>> finalOutput;

        string::size_type sz;

        square square1;

        vector<string> line;


        int i = 0;
        int j = 0;

        int rowNum = input.size() - 2;
        vector<vector<string>>::iterator itRow = input.begin();
        vector<string>::iterator itCol;

        for (i = 0; i < rowNum; i++) {
            vector<State<square> *> outputLine;
            line = *itRow;

            itCol = line.begin();


            int numCol = line.size();
            for (j = 0; j < numCol; j++) {
                square1.row = i;
                square1.column = j;

                double cost;
                string str = *itCol;
                cost = stod(str, &sz);

                State<square> *state1 = new State<square>(square1, cost);

                outputLine.push_back(state1);
                itCol++;
            }
            finalOutput.push_back(outputLine);
            itRow++;


        }
        line = *itRow;
        itCol = line.begin();

        square1.row = stod(*itCol, &sz);
        itCol++;
        square1.column = stod(*itCol, &sz);
        State<square> *init = new State<square>(square1, 0);
        itRow++;
        line = *itRow;
        itCol = line.begin();
        square1.row = stod(*itCol, &sz);
        itCol++;
        square1.column = stod(*itCol, &sz);
        State<square> *goal = new State<square>(square1, 0);


        Matrix<square> *matrix = new Matrix<square>(finalOutput, init, goal);
        return matrix;
    }
};


#endif //EX4_MATRIXPROBLEMCREATOR_H
