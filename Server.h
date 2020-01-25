//
// Created by ori on 08/01/2020.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H

#include "ClientHandler.h"


namespace server_side {

    class Server {

    public:
        virtual int open(int, ClientHandler *) = 0;

        virtual void stop() = 0;

    };
}


#endif //EX4_SERVER_H
