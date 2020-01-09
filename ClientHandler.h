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
  virtual void handleClient(istream,ostream);
  virtual  int GetProtocol() const;
};


#endif //UNTITLED6_CLIENTHANDLER_H
