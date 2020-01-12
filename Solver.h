//
// Created by ori on 08/01/2020.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H

#include <string.h>

using namespace std;
template <typename P, typename S>
class Solver {
public:
    virtual S solve(P) = 0;//Problom,Solver

};


class StringReverser : public Solver<string,string> {
public:
    virtual string solve(string problem) override {
        // Function to reverse a string
        string solution;

        int n = problem.length();

        // Swap character starting from two
        // corners
        for (int i = 0; i < n / 2; i++) {
            swap(problem[i], problem[n - i - 1]);
        }
        solution = problem;
        return solution;
    }
};



#endif //EX4_SOLVER_H
