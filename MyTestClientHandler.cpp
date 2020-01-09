//
// Created by shmuelsuna on 08/01/2020.
//

#include <strings.h>
#include "MyTestClientHandler.h"

MyTestClientHandler::MyTestClientHandler(int protocol_,Solver* solver_){
  this->protocol = protocol_;
  this->solver = solver_;
}
MyTestClientHandler::~MyTestClientHandler() {
    
}

void MyTestClientHandler::handleClient(int client_socket) {
    char buffer[1024] = {0};

    while (true) {
        bzero(buffer, 1024);
        string s;

        int valread = read(client_socket, buffer, 1024);
        s = fromBufferToString(buffer);
        if (s.compare("end")) {
            cout<<"we need to out"<<endl;
        }


        cout<<"in handle client: "<<buffer<<endl;


    }
    close(client_socket);
  
}

int MyTestClientHandler::GetProtocol() const {
  return this->protocol;
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