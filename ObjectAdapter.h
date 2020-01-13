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
    Searchable<T>* createSearchable(vector<vector<string>> input) {
        vector<vector<State<T>*>> output;

        string::size_type sz;

        int i = 0;
        int j = 0;
        int rowNum = input.size() - 2;
        vector<vector<string>>::iterator itRow = input.begin();
        for (i = 0 ; i < rowNum; i++ ) {
            vector<State<T>*> outputLine;
            vector<string> col = *itRow;
            vector<string>::iterator itCol = col.begin();
            int numCol = col.size();
            for (j = 0; j < numCol; j++) {
                double cost;
                square s;
                s.row = i;
                s.column = j;
                string str = *itCol;
                cost = stod(str, &sz);
                State<T>* state = new State<T>(s, cost);
                cout<<state<<endl;



            }
            //output.insert(outputLine);



        }

    }




    void setSearchable(Searchable<T>* searchable1) {
        this->searchable = searchable1;
    }

    string fromProblomToString(P p);
};


#endif //EX4_OBJECTADAPTER_H
