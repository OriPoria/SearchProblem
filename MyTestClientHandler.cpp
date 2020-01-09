//
// Created by shmuelsuna on 08/01/2020.
//

#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(int protocol_,Solver* solver_){
  this->protocol = protocol_;
  this->solver = solver_;
}
//MyTestClientHandler::~MyTestClientHandler() {
    
//}

void MyTestClientHandler::handleClient(int client_socket) {


  //reading from client
  char buffer[1024] = {0};

  //server is always on
  while (true) {
    int valread = read(client_socket, buffer, 1024);

}

int MyTestClientHandler::GetProtocol() const {
  return this->protocol;
}
MyTestClientHandler::MyTestClientHandler() {

}
