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
#include "CacheManager.h"

template<typename P, typename S>
class SearchClientHandler : public ClientHandler {
 private:
  Solver<P, S> *solver;
  CacheManager<string, string> *cache_manager;

 public:
  ~SearchClientHandler() {

  }

  SearchClientHandler(Solver<P, S> *solver_, CacheManager<string, string> *cache_manager_) {
    this->solver = solver_;
    this->cache_manager = cache_manager_;
  }

  void handleClient(int client_socket) override {
    char buffer[1024] = {0};

    vector<string> clientData;
    while (true) {
      bzero(buffer, 1024);
      string line;

      int valread = read(client_socket, buffer, 1024);
      line = fromBufferToString(buffer);

      if (line.size() == 0) {
        continue;
      }

      if (line.compare("end") == 0) {
        cout << "End the communication with the client... solving the problem" << endl;
        break;
      } else {
        clientData.push_back(line);
        const char *readConfirm = "line has beed read successfully";
        int is_send = send(client_socket, readConfirm, strlen(readConfirm), 0);

      }

    }
    if (clientData.size() == 0) {
        close(client_socket);
        return;
    }

    string string_of_problom = clientsDataToStringOfProblom(clientData);

    P t = solver->createProblem(clientData);

    //function that deals with all things with cache(checks if solution is in cache/if not solves and saves
    string solution = solver->solve(t);

    const char *csolution = solution.c_str();

    int is_send = send(client_socket, csolution, strlen(csolution), 0);
    close(client_socket);

    return;

  }



  string fromBufferToString(char buffer[]) {
    int i = 0;
    string s = "";
    while (buffer[i] != '\0') {
      s.push_back(buffer[i]);
      i++;
    }
    return s;
  }

  string activatingCache(string problom_in_string, P problom) {
    string solution;

    if (this->cache_manager->isThereASolution(problom_in_string)) {
      solution = this->cache_manager->getSolution(problom_in_string);
    } else {
      solution = solver->solve(problom);
      //save to files
      this->cache_manager->save(problom_in_string, solution);
    }
    return solution;
  }

  string clientsDataToStringOfProblom(vector<string> clientData) {
    vector<string>::iterator it = clientData.begin();


    std::string delimiter1 = ",";
    string srting_of_line;
    string string_of_problom;

    for (it; it != clientData.end(); ++it) {

      std::string s = *it;

      /*
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter1)) != std::string::npos) {
          token = s.substr(0, pos);
          srting_of_line+=token;
          s.erase(0, pos + delimiter1.length());
        }
        */

      for (int i = 0; i < s.length(); ++i) {
        if (s[i]==',') {
          continue;
        } else {
          srting_of_line+=s[i];
        }
      }

      srting_of_line +="\n";
    }

    string_of_problom = srting_of_line;
    return string_of_problom;
  }

/*

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



 */


};

#endif //EX4_SEARCHCLIENTHANDLER_H
