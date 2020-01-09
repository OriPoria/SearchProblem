//
// Created by shmuelsuna on 08/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include <unistd.h>
#include <string.h>

class MyTestClientHandler: public ClientHandler {
 private:
  Solver* solver;
  int protocol;


 public:
    ~MyTestClientHandler();
  MyTestClientHandler(int,Solver*);//protocol and solver
  void handleClient(int) override;
  int GetProtocol() const override;

};

string fromBufferToString(char[]);

#endif //EX4__MYTESTCLIENTHANDLER_H_
