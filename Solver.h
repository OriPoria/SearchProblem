//
// Created by ori on 08/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include <string.h>
#include <vector>

using namespace std;
template <typename P, typename S>
class Solver {
public:
    virtual S solve(P) = 0;//Problom,Solver

    //
    virtual P createProblem(vector<string>) = 0;


};




#endif //EX4_SOLVER_H
