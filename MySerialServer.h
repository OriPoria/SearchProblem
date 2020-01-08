//
// Created by ori on 08/01/2020.
//

#ifndef UNTITLED6_MYSERIALSERVER_H
#define UNTITLED6_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server {
public:


    void open(int i, ClientHandler handler) override;

    void stop() override;
};


#endif //UNTITLED6_MYSERIALSERVER_H
