//
// Created by shmuelsuna on 08/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(int protocol_,Solver* solver_){
  this->protocol = protocol_;
  this->solver = solver_;
}
MyTestClientHandler::~MyTestClientHandler() {
    
}

void MyTestClientHandler::handleClient(int client_socket) {
  
}

int MyTestClientHandler::GetProtocol() const {
  return this->protocol;
}
