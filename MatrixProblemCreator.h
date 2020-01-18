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

        State<square*>*** finalOutput = new State<square*>**;


        int i = 0;
        int j = 0;

        int rowNum = input.size() - 2;

        int colNum;

        finalOutput = new State<square *> **[rowNum];


        vector<vector<string>>::iterator itRow = input.begin();


        for (i = 0; i < rowNum; i++) {
            line = *itRow;

            vector<string>::iterator itCol = line.begin();
            colNum = line.size();


            State<square*>** outLine = new State<square*>*[colNum];


            finalOutput[i] = outLine;


            for (j = 0; j < colNum; j++) {
                square* square1 = new square(i, j);

                double cost;
                string str = *itCol;
                cost = stod(str, &sz);


                //set up for h cost
                int rows1 = getNumOfRows(input1);
              int cols1 = getNumOfCols(input1);
                double h_cost = calculateHCostOfNode(square1->row,square1->column,rows1,cols1);
                State<square*> *state1 = new State<square*>(square1, cost,h_cost);
                //TODO put h cost

                outLine[j] = state1;


                itCol++;
            }
            itRow++;


        }

        line = *itRow;
        vector<string>::iterator itCol = line.begin();
        i = stod(*itCol, &sz);
        itCol++;
        j = stod(*itCol, &sz);
        itRow++;
        line = *itRow;
        itCol = line.begin();
        int k, l;
        k = stod(*itCol, &sz);
        itCol++;
        l = stod(*itCol, &sz);
        MatrixProblem *matrix = new MatrixProblem(finalOutput, i, j,k,l, rowNum, colNum);
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

    double calculateHCostOfNode(double row,double col, double rows, double cols){
      double x = rows- row -1;
      double y = cols- col-1;

      if (x<0) {
        x*=-1;
      }
      if (y<0) {
        y*=-1;
      }

      return x+y;
    }

    double getNumOfRows(vector<string> input1){
      vector<string>::iterator it = input1.begin();
      string first_row = *it;
      double length =  (first_row.length() /2) +1;
      return length;
    }

  double getNumOfCols(vector<string> input1){
    return input1.size() - 2;
  }



};


#endif //EX4_MATRIXPROBLEMCREATOR_H
