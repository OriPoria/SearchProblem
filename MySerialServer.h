//
// Created by ori on 08/01/2020.
//

#ifndef UNTITLED6_MYSERIALSERVER_H
#define UNTITLED6_MYSERIALSERVER_H


#include "Server.h"
using namespace std;
#include <map>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>
#include <unordered_map>
#include <vector>
#include <mutex>
#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sstream>

#include <map>
#include <sys/socket.h>
#include <string.h>
#include <iostream>

#include <netinet/in.h>
#include <thread>
#include <unordered_map>

#include <vector>

#include <mutex>

using namespace std;

class MySerialServer : public server_side::Server {
 private:
  int socketfd;
 // sockaddr_in address;

 public:


    int open(int, ClientHandler*) override;

    void stop() override;

  void start(int, ClientHandler* handler, sockaddr_in);//gets socketfd
};


#endif //UNTITLED6_MYSERIALSERVER_H
