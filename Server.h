//
// Created by ori on 08/01/2020.
//

#ifndef UNTITLED6_SERVER_H
#define UNTITLED6_SERVER_H

#include "ClientHandler.h"



namespace server_side {

    class Server {

    public:
        virtual void open(int, ClientHandler) = 0;

        virtual void stop() = 0;

    };
}


#endif //UNTITLED6_SERVER_H
