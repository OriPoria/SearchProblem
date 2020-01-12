//
// Created by ori on 08/01/2020.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <unordered_map>
#include <iostream>
#include <thread>
#include <unistd.h>





using namespace std;

class MySerialServer : public server_side::Server {
 private:
  int socketfd;
 // sockaddr_in address;

 volatile bool stop_server = false;

 public:


    int open(int, ClientHandler*) override;

    void stop() override;

    void start(int, ClientHandler* handler, sockaddr_in);//gets socketfd
};


#endif //EX4_MYSERIALSERVER_H
