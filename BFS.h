//
// Created by ori on 14/01/2020.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H


#include <string>
#include "Searchable.h"
#include "Searcher.h"
#include "MySearcher.h"
#include <queue>
#include <iterator>

template <typename T>
class BFS : public MySearcher<T> {
private:
    queue<State<T>*> myQueue;
    vector<State<T>*> myVec;
public:

    virtual string search(Searchable<T>* mySearchable) override {
        State<T>* node = mySearchable->getInitialState();
        node->setColor('g');
        myQueue.push(node);
        while (!myQueue.empty()) {
            node = myQueue.front();
            if (mySearchable->isGoalState(node)) {
                return this->backTrace(node, mySearchable);
            }
            myQueue.pop();
            if (node->getCost() == -1) {
                node->setColor('b');
                continue;
            }
            myVec = mySearchable->getAllPossibleStates(node);
            typename vector<State<T>*>::iterator it = myVec.begin();
            for (it ; it < myVec.end(); it++) {
                State<T>* adj = *it;
                if (adj->getColor() == 'w') {
                    adj->setColor('g');
                    adj->setCamefrom(node);
                    myQueue.push(adj);
                }
            }
            this->nodesEvaluated++;
            node->setColor('b');
        }




    }


    BFS<T>* clone() override {
        return new BFS<T>();
    }
};


#endif //EX4_BFS_H
