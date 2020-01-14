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

    vector<vector<string>> clientData;
    while (true) {
      bzero(buffer, 1024);
      vector<string> line;

      int valread = read(client_socket, buffer, 1024);
      line = fromBufferToString(buffer);
      vector<string>::iterator it = line.begin();
      for (it; it < line.end(); it++) {
        cout << "Message from client: " << *it << endl;
      }

      it = line.begin();
      if (*it == "end") {
        cout << "End the communication with the client" << endl;
        break;
      } else {
        clientData.push_back(line);
        const char *readConfirm = "line has beed read successfully";
        int is_send = send(client_socket, readConfirm, strlen(readConfirm), 0);

      }

    }

    string problom_transformed_to_string = createStringOfProblomFromVectorOfVectorOfStrings(clientData);



    P myProblem = solver->createProblem(clientData);
//function that deals with all diffrent cases: is in cache,not in cache but in
    string soultion  = getSolution(problom_transformed_to_string,myProblem);

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

  string createStringOfProblomFromVectorOfVectorOfStrings(vector<vector<string>> client_data) {

    int i = 0;
    int j = 0;
    vector<string> line;
    string string_of_problom;

    int rowNum = client_data.size();
    vector<vector<string>>::iterator itRow = client_data.begin();
    vector<string>::iterator itCol;

    for (i = 0; i < rowNum; i++) {
      line = *itRow;
      itCol = line.begin();
      int numCol = line.size();
      for (j = 0; j < numCol; j++) {
        string temp_str = *itCol;
        string_of_problom+=temp_str;
        itCol++;
      }
      string_of_problom+="\n";
      itRow++;
    }

    return string_of_problom;

  }





  string getSolution(string problom_string,P problom) {
    string solution;
    if (cache_manager->isThereASolution(problom_string)) {
       solution = cache_manager->getSolution(problom_string);
    } else {
      solution= solver->solve(problom);
      cache_manager->save(problom_string, solution);
    }
    return solution;
  }

};

#endif //EX4_SEARCHCLIENTHANDLER_H
