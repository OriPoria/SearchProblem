//
// Created by ori on 12/01/2020.
//

#ifndef EX4_OBJECTADAPTER_H
#define EX4_OBJECTADAPTER_H


#include "Solver.h"
#include "Searchable.h"
#include <string>
#include "Searcher.h"
#include "SearchableCreator.h"
#include "MatrixProblemCreator.h"

using namespace std;


template<typename T, typename S>
class ObjectAdapter : public Solver<Searchable<T> *, S> {
private:
    Searcher<T, S> *searcher;

public:
    ObjectAdapter(Searcher<T, S> *s) {
        this->searcher = s;
    }


    virtual S solve(Searchable<T> *p) override {
        //z) setSearchable(p);

        S s = searcher->search(p);
        //  string result_string = fromProblomToString(s)

        return s;

    }

    Searchable<T> *createProblem(vector<vector<string>> input) override {

        //going forward we can make a creator according to the input
        SearchableCreator<square> *sc = new MatrixProblemCreator();

        Searchable<T> *mySearchable = sc->create(input);


        return mySearchable;


    }


    void setSearchable(Searchable<T> *searchable1) {
        this->searchable = searchable1;
    }

};


#endif //EX4_OBJECTADAPTER_H
