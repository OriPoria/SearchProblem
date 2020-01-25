//
// Created by shmuelsuna on 08/01/2020.
//

#ifndef EX4__MYTESTCLIENTHANDLER_H_
#define EX4__MYTESTCLIENTHANDLER_H_

#include "ClientHandler.h"
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

//template <typename P, typename S>
class MyTestClientHandler : public ClientHandler {
private:
    // Solver<P,S>* solver;
    Solver<string, string> *solver;
    int protocol;

public:
    ~MyTestClientHandler() {

    }

    MyTestClientHandler(int protocol_, Solver<string, string> *solver_) {
        this->protocol = protocol_;
        this->solver = solver_;

    }

    void handleClient(int client_socket) override {
        char buffer[1024] = {0};

        while (true) {
            bzero(buffer, 1024);
            string s;

            int valread = read(client_socket, buffer, 1024);
            s = fromBufferToString(buffer);
            cout << "Message from client: " << s << endl;

            if (s.compare("end") == 0) {
                cout << "End the communication with the client" << endl;
                break;
            }


            string solution = solver->solve(s);
            cout << solution << endl;
            const char *csolution = solution.c_str();

            int is_send = send(client_socket, csolution, strlen(csolution), 0);

        }
        close(client_socket);
        return;

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

};

#endif //EX4__MYTESTCLIENTHANDLER_H_
