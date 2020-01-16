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


class MatrixProblemCreator : public SearchableCreator<square*> {

public:


    virtual Searchable<square*>* create(vector<string> input1) override {

        string::size_type sz;

        vector<vector<string>> input;
        vector<string>::iterator it = input1.begin();
        for (; it < input1.end(); it++) {
            input.push_back(fromBufferToString(*it));
        }

        vector<string> line;

        State<square*>*** finalOutput;


        int i = 0;
        int j = 0;

        int rowNum = input.size() - 2;

        int colNum;
        finalOutput = new State<square*>**[rowNum];

        vector<vector<string>>::iterator itRow = input.begin();


        for (i = 0; i < rowNum; i++) {
            line = *itRow;

            vector<string>::iterator itCol = line.begin();

            State<square*>** outLine = new State<square*>*;


            finalOutput[i] = outLine;

            colNum = line.size();

            for (j = 0; j < colNum; j++) {
                square* square1 = new square();
                square1->row = i;
                square1->column = j;



                double cost;
                string str = *itCol;
                cost = stod(str, &sz);

                State<square*> *state1 = new State<square*>(square1, cost);

                outLine[j] = state1;


                itCol++;
            }
            itRow++;

        }
        line = *itRow;
        vector<string>::iterator itCol = line.begin();
        square* square2 = new square();
        square2->row = stod(*itCol, &sz);
        itCol++;
        square2->column = stod(*itCol, &sz);
        itRow++;
        line = *itRow;
        itCol = line.begin();
        square* square3 = new square();
        square3->row = stod(*itCol, &sz);
        itCol++;
        square3->column = stod(*itCol, &sz);


        MatrixProblem *matrix = new MatrixProblem(finalOutput, square2, square3, rowNum, colNum);
        return matrix;
    }
    vector<string> fromBufferToString(string string1) {
        string s;
        vector<string> line;
        int i = 0;
        while (string1[i] != '\0') {
            while (string1[i] != ',') {
                if (string1[i] == '\0') {
                    line.push_back(s);
                    return line;
                }
                s.push_back(string1[i]);
                i++;
            }
            line.push_back(s);
            s = "";
            i++;
        }

        return line;
    }
};


#endif //EX4_MATRIXPROBLEMCREATOR_H
