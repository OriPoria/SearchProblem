#include "Server.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include <iostream>

int main() {

    MySerialServer* m = new MySerialServer();
    ClientHandler* ha = new MyTestClientHandler(2, new StringReverser());
    m->open(5400, ha);
    return 0;
}