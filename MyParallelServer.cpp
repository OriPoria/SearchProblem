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
    start(socketfd, handler, address_);
    return 0;
}

void MyParallelServer::stop() {
    cout<<"No new clients, close the server...";
    for (int i = 0; i < 10; i++ ) {
        client[i].join();
        i--;
    }
    this->stop_server = true;

}

void MyParallelServer::start(int socketfd, ClientHandler *handler, sockaddr_in address_) {
    //making socket listen to the port


    while (!stop_server || i < 5) {

        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;

        } else {
            cout << "Server is now listening ...\n" << endl;

            //time-out for listening
            struct timeval tv;
            tv.tv_sec = 20;
            setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof(tv));


            // accepting a client
            int client_socket = accept(socketfd, (struct sockaddr *) &address_, (socklen_t *) &address_);

            if (client_socket == -1) {
                cout << "Error accepting a client" << endl;
                stop();
                continue;
            }
            cout<<"in main: client socket: "<< client_socket<<endl;
                cout << "waiting for message from client number " << i << "\n\n"<< endl;

            client[i] = thread(&ClientHandler::handleClient,handler->clone(), client_socket);
            i++;

        }


    }
    stop();
    return;
}