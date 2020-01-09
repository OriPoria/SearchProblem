//
// Created by ori on 08/01/2020.
//

#ifndef UNTITLED6_CLIENTHANDLER_H
#define UNTITLED6_CLIENTHANDLER_H

#include <iostream>
#include "Solver.h"


using namespace std;
class ClientHandler {

public:
   // virtual ~ClientHandler() = 0;
  virtual void handleClient(int)=0;
  virtual  int GetProtocol() const=0;
};


#endif //UNTITLED6_CLIENTHANDLER_H
