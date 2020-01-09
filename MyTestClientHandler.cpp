//
// Created by shmuelsuna on 08/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(int protocol_,Solver* solver_){
  this->protocol = protocol_;
  this->solver = solver_;
}

void MyTestClientHandler::handleClient(istream istream1, ostream ostream1) {
  
}

int MyTestClientHandler::GetProtocol() const {
  return this->protocol;
}
