//
// Created by shmuelsuna on 08/01/2020.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include "iostream"
#include "Solver.h"

using namespace std;


class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string problem) override {
        // Function to reverse a string
        string solution;

        int n = problem.length();

        // Swap character starting from two corners
        for (int i = 0; i < n / 2; i++) {
            swap(problem[i], problem[n - i - 1]);
        }
        solution = problem;
        return solution;
    }
};


#endif //EX4__STRINGREVERSER_H_
