//
// Created by shmuelsuna on 08/01/2020.
//

#include <sys/socket.h>
#include "MyTestClientHandler.h"
/*
MyTestClientHandler::MyTestClientHandler(int protocol_,Solver* solver_)
MyTestClientHandler::~MyTestClientHandler() {

}

void MyTestClientHandler::handleClient(int client_socket) {
    char buffer[1024] = {0};

    while (true) {
        bzero(buffer, 1024);
        string s;

        int valread = read(client_socket, buffer, 1024);
        s = fromBufferToString(buffer);
        cout<<"Message from client: "<<s<<endl;

        if (s.compare("end") == 0) {
            cout<<"End the communication with the client"<<endl;
            break;
        }
        string solution = solver->solve(s);
        cout<<solution<<endl;
        const char* csolution = solution.c_str();

        int is_send = send(client_socket, csolution, strlen(csolution), 0 );



    }
    close(client_socket);
    return;

}
*/




