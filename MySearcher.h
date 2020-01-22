//
// Created by ori on 15/01/2020.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H

#include "Searcher.h"
#include <stack>
#include <sstream>

using namespace std;

template<typename T>
class MySearcher : public Searcher<square *, string> {
protected:
    int nodesEvaluated;
    double totalCost;
public:



    int getNumOfNodesEvaluated() {
        return this->nodesEvaluated;
    }

    virtual string backTrace(State<square *> *node, Searchable<square *> *mySearchable) {
        string solution = "";
        stack<State<square *> *> path;
        State<square *> *temp1 = node;

        totalCost += temp1->getCost();
        while (temp1 != mySearchable->getInitialState()) {
            State<square *> *temp2 = mySearchable->getInitialState();

            path.push(temp1);
            temp1 = temp1->getCamefrom();
            totalCost += temp1->getCost();

        }

        double cost;
        cost = temp1->getCost();
        while (!path.empty()) {
            State<square *> *temp2;
            temp2 = path.top();
            cost += temp2->getCost();
            ostringstream sCost;
            sCost << cost;
            string sCost2 = sCost.str();
            const char *costStr = (char *) &cost;
            path.pop();
            if (temp1->getState()->getRow() > temp2->getState()->getRow()) {
                solution.append("Up ").append("(").append(sCost2).append("), ");
            } else if (temp1->getState()->getRow() < temp2->getState()->getRow()) {
                solution.append("Down ").append("(").append(sCost2).append("), ");
            } else if (temp1->getState()->getColumn() > temp2->getState()->getColumn()) {
                solution.append("Left ").append("(").append(sCost2).append("), ");
            } else if (temp1->getState()->getColumn() < temp2->getState()->getColumn()) {
                solution.append("Right ").append("(").append(sCost2).append("), ");
            }
            temp1 = temp2;


        }

        solution.erase(solution.end() - 2);
        return solution;
    }


};


#endif //EX4_MYSEARCHER_H
