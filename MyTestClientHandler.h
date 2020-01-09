//
// Created by shmuelsuna on 08/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include <unistd.h>
#include <string.h>
template <typename T,typename S>
class MyTestClientHandler: public ClientHandler {
 private:
  Solver<T,S>* solver;
  int protocol;


 public:
    ~MyTestClientHandler();
  MyTestClientHandler(int,Solver<T,S>*);//protocol and solver
  void handleClient(int) override;


};

string fromBufferToString(char[]);

#endif //EX4__MYTESTCLIENTHANDLER_H_
