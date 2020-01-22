//
// Created by ori on 16/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "MySearcher.h"
#include <stack>
#include <iterator>

template <typename T>
class DFS : public MySearcher<T> {
private:
    stack<State<T>*> myStack;
    vector<State<T>*> myVec;
public:
    virtual string search(Searchable<T>* mySearchable) override {
        State<T>* node = mySearchable->getInitialState();
        node->setColor('g');
        myStack.push(node);
        while (!myStack.empty()) {
            myStack.pop();
            if (node->getCost() == -1) {
                node->setColor('b');
                node = myStack.top();
                continue;
            }
            myVec = mySearchable->getAllPossibleStates(node);
            typename vector<State<T>*>::iterator it = myVec.begin();
            for (it; it < myVec.end(); it++) {
                State<T> *adj = *it;
                if (adj->getColor() == 'w' && adj->getCost() != -1) {
                    adj->setColor('g');
                    adj->setCamefrom(node);
                    myStack.push(adj);
                }
            }
            this->nodesEvaluated++;
            node->setColor('b');
            node = myStack.top();
            if (mySearchable->isGoalState(node)) {
                return this->backTrace(node, mySearchable);
            }


        }
    }

    DFS<T>* clone() override {
        return new DFS<T>();
    }


};


#endif //EX4_DFS_H
