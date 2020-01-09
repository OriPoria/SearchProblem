//
// Created by ori on 08/01/2020.
//

#ifndef UNTITLED6_MYSERIALSERVER_H
#define UNTITLED6_MYSERIALSERVER_H


#include "Server.h"
using namespace std;
#include <map>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <unordered_map>
#include <vector>
#include <mutex>

class MySerialServer : public server_side::Server {
 private:
  int socketfd;
  sockaddr_in address;

 public:


    int open(int, ClientHandler*) override;

    void stop() override;

  void start(int, ClientHandler* handler);//gets socketfd
  void SetAddress(const sockaddr_in &address);
};


#endif //UNTITLED6_MYSERIALSERVER_H
