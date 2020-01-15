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


    virtual Searchable<square>* create(vector<vector<string>> input) override {

        string::size_type sz;

        square square1;

        vector<string> line;

        State<square>*** finalOutput;


        int i = 0;
        int j = 0;

        int rowNum = input.size() - 2;

        int colNum;


        vector<vector<string>>::iterator itRow = input.begin();


        for (i = 0; i < rowNum; i++) {
            line = *itRow;

            vector<string>::iterator itCol = line.begin();

            State<square>** outLine = new State<square>*;


            finalOutput[i] = outLine;

            colNum = line.size();

            for (j = 0; j < colNum; j++) {
                square1.row = i;
                square1.column = j;



                double cost;
                string str = *itCol;
                cost = stod(str, &sz);

                State<square> *state1 = new State<square>(square1, cost);

                outLine[j] = state1;


                itCol++;
            }
            itRow++;

        }
        line = *itRow;
        vector<string>::iterator itCol = line.begin();

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


        MatrixProblem *matrix = new MatrixProblem(finalOutput, init, goal, rowNum, colNum);
        return matrix;
    }
};


#endif //EX4_MATRIXPROBLEMCREATOR_H
