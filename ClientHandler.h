//
// Created by ori on 08/01/2020.
//

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"


using namespace std;

class ClientHandler {

public:
  virtual void handleClient(int) = 0;

};


#endif //EX4_CLIENTHANDLER_H
