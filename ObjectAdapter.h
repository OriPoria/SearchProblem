//
// Created by ori on 12/01/2020.
//

#ifndef EX4_OBJECTADAPTER_H
#define EX4_OBJECTADAPTER_H


#include "Solver.h"
#include "Searchable.h"
#include <string>
#include "Searcher.h"

using namespace std;

template <typename T,typename P,typename S>
class ObjectAdapter : public Solver<Searchable<T>*, S> {
private:
    Searcher<T,S>* searcher;
    Searchable<T>* searchable;

public:
    ObjectAdapter(Searcher<T,S>* s) {
        this->searcher = s;
    }


    virtual S solve(P p) override {
       //z) setSearchable(p);

      S s = searcher->search(p);
              //  string result_string = fromProblomToString(s)

        return s;

    }

    Searchable<T>* searchableCreator(string);



    void setSearchable(Searchable<T>* searchable1) {
        this->searchable = searchable1;
    }

    string fromProblomToString(P p);
};


#endif //EX4_OBJECTADAPTER_H
