//
// Created by ori on 15/01/2020.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H

#include "Searcher.h"
#include <stack>

using namespace std;
template <typename T>
class MySearcher : public Searcher<square*,string> {
protected:
    int nodesEvaluated;
    double totalCost;
public:

  int setTotalCost(int total_cost) {
     totalCost = total_cost;
  }


    int getNumOfNodesEvaluated() {
        return this->nodesEvaluated;
    }

    string backTrace(State<square*>* node, Searchable<square*>* mySearchable) {
        string solution;
        stack<State<square*>*> path;
        State<square*>* temp1 = node;
        double cost;
        while (temp1 != mySearchable->getInitialState()) {
            path.push(temp1);
            temp1 = temp1->getCamefrom();
            totalCost+=temp1->getCost();

        }
        cout<<"in MySearcher: total cost of the path: "<<totalCost<<" number of nodes evaluated: "<<this->getNumOfNodesEvaluated()<<endl;

        while (!path.empty()) {
            State<square*>* temp2;
            temp2 = path.top();
            path.pop();
            if (temp1->getState()->getRow() > temp2->getState()->getRow()) {
                solution.append("Up, ");
            } else if (temp1->getState()->getRow() < temp2->getState()->getRow()) {
                solution.append("Down, ");
            } else if (temp1->getState()->getColumn() > temp2->getState()->getColumn()) {
                solution.append("Left, ");
            } else if (temp1->getState()->getColumn() < temp2->getState()->getColumn()) {
                solution.append("Right, ");
            }
            temp1 = temp2;



        }
        solution.erase(solution.end()-2);
        return solution;
    }

};


#endif //EX4_MYSEARCHER_H
