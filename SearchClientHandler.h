//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHCLIENTHANDLER_H
#define EX4_SEARCHCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Searchable.h"
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <vector>


template <typename T,typename P, typename S>
class SearchClientHandler : public ClientHandler {
private:
    Solver<P,S> *solver;


public:
    ~SearchClientHandler() {

    }

    SearchClientHandler(Solver<P,S> *solver_) {
        this->solver = solver_;

    }

    void handleClient(int client_socket) override {
        char buffer[1024] = {0};

        vector<vector<string>> clientData;
        while (true) {
            bzero(buffer, 1024);
            vector<string> line;

            int valread = read(client_socket, buffer, 1024);
            line = fromBufferToString(buffer);
            vector<string>::iterator it = line.begin();
            for (it; it <line.end() ; it++) {
                cout << "Message from client: " << *it << endl;
            }

            it = line.begin();
            if (*it == "end") {
                cout << "End the communication with the client" << endl;
                break;
            } else {
                clientData.push_back(line);
                const char* readConfirm = "line has beed read successfully";
                int is_send = send(client_socket, readConfirm, strlen(readConfirm), 0);


            }


        }





        //create searchable: Searchable<T>* mySearchable = solver_.createSearchable
        //look for a solution in the cache
        //if not found:
        //look for a solution in files
        //if not found:


        //solution to string

        //const char *csolution = solution to string.c_str();

        //)int is_send = send(client_socket, csolution, strlen(csolution), 0);
        close(client_socket);
        return;

    }


    vector<string> fromBufferToString(char buffer[]) {
        string s;
        vector<string> line;
        int i = 0;
        while (buffer[i] != '\0') {
            while (buffer[i] != ',') {
                if (buffer[i] == '\0') {
                    line.push_back(s);
                    return line;
                }
                s.push_back(buffer[i]);
                i++;
            }
        line.push_back(s);
        s = "";
        i++;
    }

    return line;
    }





};


#endif //EX4_SEARCHCLIENTHANDLER_H
