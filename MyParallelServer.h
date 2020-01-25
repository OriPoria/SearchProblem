//
// Created by ori on 17/01/2020.

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "Server.h"
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <netinet/in.h>
#include <unordered_map>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <queue>


using namespace std;

class MyParallelServer : public server_side::Server {
private:
    volatile bool stop_server = false;
    thread client[10];
    volatile int i;
public:
    int open(int i, ClientHandler *handler) override;

    void stop() override;

    void start(int, ClientHandler *handler, sockaddr_in);

};


#endif //EX4_MYPARALLELSERVER_H
