//
// Created by ori on 17/01/2020.
//

#include "MyParallelServer.h"

int MyParallelServer::open(int port, ClientHandler *handler) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }


    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address_; //in means IP4
    address_.sin_family = AF_INET;
    address_.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address_.sin_port = htons(port);


    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address_, sizeof(address_)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }
    thread handle([this, socketfd, handler, address_] { start(socketfd, handler, address_); });
    handle.join();
    return 0;
}


//close the server in case we have got 10 clients or there were no connections to the server
void MyParallelServer::stop() {
    cout << "Close the server..." << endl;
    for (int j = 0; j < i; j++) {
        client[j].join();
    }
    this->stop_server = true;

}

void MyParallelServer::start(int socketfd, ClientHandler *handler, sockaddr_in address_) {

    while (!stop_server) {

        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;

        } else {
            cout << "Server is now listening ...\n" << endl;

            //time-out for listening
            struct timeval tv;
            tv.tv_sec = 120;
            setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));


            // accepting a client
            int client_socket = accept(socketfd, (struct sockaddr *) &address_, (socklen_t *) &address_);

            if (client_socket == -1) {
                cout << "Error accepting a client" << endl;
                stop();
                continue;
            }
            cout << "waiting for message" << endl;

            client[i] = thread(&ClientHandler::handleClient, handler->clone(), client_socket);
            i++;
            if (i == 10) {
                stop();
            }

        }


    }
    close(socketfd);
    return;
}
