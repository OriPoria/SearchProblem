//
// Created by shmuelsuna on 08/01/2020.
//

#include <strings.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(int protocol_, Solver<T ,S > *solver_) {
  this->protocol = protocol_;
  this->solver = solver_;
}
MyTestClientHandler::~MyTestClientHandler() {

}

void MyTestClientHandler::handleClient(int client_socket) {
  char buffer[1024] = {0};
  char sendData[1024];
  while (true) {
    bzero(buffer, 1024);
    string s;

    int valread = read(client_socket, buffer, 1024);
    s = fromBufferToString(buffer);
    if (s.compare("end") == 0) {
      break;
    }
    string answer;
    string answer2= this->solver->solve(s, answer);

    strcpy(sendData,  (answer2.c_str());
    int is_sent2 = send(client_socket, (char *) &sendData, strlen(sendData), 0);
    if (is_sent2 == -1) {
      std::cout << "Error sending message" << std::endl;
    }

  }
  close(client_socket);

}

string fromBufferToString(char buffer[]) {
  string s;
  int i = 0;
  while (buffer[i] != '\0') {
    s.push_back(buffer[i]);
    i++;
  }
  return s;
}