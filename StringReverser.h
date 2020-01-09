//
// Created by shmuelsuna on 08/01/2020.
//

#ifndef EX4__STRINGREVERSER_H_
#define EX4__STRINGREVERSER_H_

#include "Solver.h"
#include <string.h>
using namespace std;
//template <typename T,typename S>
class StringReverser :public Solver<string, string>{
  string solve(string,string) override;
};

#endif //EX4__STRINGREVERSER_H_
