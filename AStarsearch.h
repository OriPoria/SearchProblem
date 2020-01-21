//
// Created by shmuelsuna on 17/01/2020.
//

#ifndef EX4__ASTARSEARCH_H_
#define EX4__ASTARSEARCH_H_


#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "MySearcher.h"
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>
#include <mutex>

template<class T>
class ComparatorByCost2 {
public:
    bool operator()(State<T> *leftSide, State<T> *rightSide) {
        return leftSide->getCost() + leftSide->GetHCost() < rightSide->getCost() + rightSide->GetHCost();
    }
};

template<typename T>
class AStarsearch : public MySearcher<T> {
private:
    multiset<State<square *> *, ComparatorByCost2<square *>> multiset_openList;
    // multiset<State<T>*> multiset_openList;

    vector<State<T> *> vector_closeList;
    vector<State<T> *> neighborsVector;


public:

    string search(Searchable<T> *mySearchable) override {
        //set up before running algorethim
        State<T> *first_node = mySearchable->getInitialState();

        multiset_openList.insert(first_node);



//starting algo
        while (!multiset_openList.empty()) {
            State<T> *node = *multiset_openList.begin();
            multiset_openList.erase(multiset_openList.begin());
            vector_closeList.push_back(node);

            if (mySearchable->isGoalState(node)) {
                return this->backTrace2(node, mySearchable);
            } else {

                //create nodes neighbors
                neighborsVector = mySearchable->getAllPossibleStates(node);

                //iterate over all neighbors
                typename vector<State<T> *>::iterator it_over_neighborsVector = neighborsVector.begin();
                for (it_over_neighborsVector;
                     it_over_neighborsVector < neighborsVector.end(); it_over_neighborsVector++) {
                    State<T> *neighbor = *it_over_neighborsVector;

                    //if neighbor node's cost is -1:
                    if (neighbor->getCost() == -1) {
                        neighborsVector.erase(it_over_neighborsVector);
                        it_over_neighborsVector--;
                        continue;
                    }


                    if (!hasNodeInClosedList(neighbor) && !hasNodeInOpenList(neighbor)) {

                        neighbor->setCamefrom(node);
                        //update new cost
                        neighbor->setCost(neighbor->getCost() + node->getCost());
                        multiset_openList.insert(neighbor);
                    } else if (hasNodeInClosedList(neighbor)) { // neighbor is in ClosedList
                        continue;
                    } else {
                        //if we have this neighbor in openList, so we need to check his cost and maybe
                        // update it if the cost of neighbour is lower then the node we
                        //already have in openList
                        this->updateStatePriority(neighbor);
                    }
                }
                this->nodesEvaluated++;
            }

        }
        string tempstring = "Impossible to solve the problem";
        return tempstring;
    }


    //update openList - add current to the list or update his cost in openList if there it is needed
    void updateStatePriority(State<T> *current) {
        bool wasFound = false;
        for (auto item : multiset_openList) {
            if (item == current) {
                wasFound = true;
                updateCostItemInOpenList(item, current);
                break;
            }
        }
        if (!wasFound) {
            multiset_openList.insert(current);
        }
    }


    //update cost and h cost item that is in openList if his cost is bigger than cost and h cost of current
    void updateCostItemInOpenList(State<T> *item, State<T> *current) {
        if (item->getCost() + item->GetHCost() > current->getCost() + current->GetHCost()) {
            multiset_openList.erase(item);
            delete item;
            multiset_openList.insert(current);
        }
    }


    string backTrace2(State<square *> *node, Searchable<square *> *mySearchable) {
        string solution;
        stack<State<square *> *> path;
        State<square *> *temp1 = node;
        double cost;
        mutex m;


        while (temp1 != mySearchable->getInitialState()) {
            path.push(temp1);
            temp1 = temp1->getCamefrom();

        }



        cout << "in MySearcher: total cost of the path: " << node->getCost() << " number of nodes evaluated: "
             << this->getNumOfNodesEvaluated() << endl;
        while (!path.empty()) {
            State<square *> *temp2;
            temp2 = path.top();
            ostringstream sCost;
            sCost << temp2->getCost();
            string sCost2 = sCost.str();
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

    bool hasNodeInOpenList(State<T> *node) {
        //if neighbor node is not in open/closed list
        auto it2 = multiset_openList.find(node);
        if ((it2 == multiset_openList.end())) {
            return false;
        } else {
            return true;
        }

    }

    bool hasNodeInClosedList(State<T> *node) {
        if (std::find(vector_closeList.begin(), vector_closeList.end(), node) != vector_closeList.end()) {
            return true;
        } else {
            return false;
        }

    }

    AStarsearch<T>* clone() override {
        return new AStarsearch<T>();
    }


};

#endif //EX4__ASTARSEARCH_H_
