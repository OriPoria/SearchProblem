//
// Created by shmuelsuna on 16/01/2020.
//

#ifndef EX4__BestFirstSearch_H_
#define EX4__BestFirstSearch_H_

#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "MySearcher.h"
#include <set>
#include <iterator>
#include <algorithm>
#include <vector>

template<class T>
class ComparatorByCost {
 public:
  bool operator()(State<T> *leftSide, State<T> *rightSide) {
    return leftSide->getCost() < rightSide->getCost();
  }
};

template<typename T>
class BestFirstSearch : public MySearcher<T> {
 private:
  multiset<State<T> *, ComparatorByCost<T>> multiset_openList;
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
        for (it_over_neighborsVector; it_over_neighborsVector < neighborsVector.end(); it_over_neighborsVector++) {
          State<T> *neighbor = *it_over_neighborsVector;

          //if neighbor node's cost is -1:
          if (neighbor->getCost() == -1) {
            neighborsVector.erase(it_over_neighborsVector);
            it_over_neighborsVector--;
            continue;
          }

          if (!hasNodeInClosedList(neighbor) && !hasNodeInOpenList(neighbor)){

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
    string tempstring = "testing in BESTFIRSTSEARCH";
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

  //update cost item that is in openList if his cost is bigger than cost of current
  void updateCostItemInOpenList(State<T> *item, State<T> *current) {
    if (item->getCost() > current->getCost()) {
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
    while (temp1 != mySearchable->getInitialState()) {
      path.push(temp1);
      temp1 = temp1->getCamefrom();
      //  totalCost+=temp1->getCost();

    }
    cout << "in MySearcher: total cost of the path: " << node->getCost() << endl;

    while (!path.empty()) {
      State<square *> *temp2;
      temp2 = path.top();
      ostringstream os_string_cost;
      os_string_cost<<temp2->getCost();
      string string_cost = os_string_cost.str();
      path.pop();
      if (temp1->getState()->getRow() > temp2->getState()->getRow()) {
        solution.append("Up ").append("(").append(string_cost).append("),");
      } else if (temp1->getState()->getRow() < temp2->getState()->getRow()) {
        solution.append("Down ").append("(").append(string_cost).append("),");
      } else if (temp1->getState()->getColumn() > temp2->getState()->getColumn()) {
        solution.append("Left ").append("(").append(string_cost).append("),");
      } else if (temp1->getState()->getColumn() < temp2->getState()->getColumn()) {
        solution.append("Right ").append("(").append(string_cost).append("),");
      }
      temp1 = temp2;

    }
    solution.erase(solution.end() - 2);
    return solution;
  }

  bool hasNodeInOpenList(State<T> *node) {
    for (auto item : multiset_openList) {
      //we have current in openList
      if (node == item) {
        return true;
      }
    }
    //we do not have current in openList
    return false;
  }

  bool hasNodeInClosedList(State<T> *node) {
    if ( std::find(vector_closeList.begin(), vector_closeList.end(), node) != vector_closeList.end()){
      return true;
    } else {
      return false;
    }

  }


  //check if we have current in openList
  virtual bool doWeHaveThisNodeInOpenList(State<T> *current) {
    for (auto item : multiset_openList) {
      //we have current in openList
      if (current == item) {
        return true;
      }
    }
    //we do not have current in openList
    return false;
  }

};

#endif //EX4__BESTFIRSTSEARCH_H_
