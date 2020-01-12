#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include <iostream>

int main() {

    server_side::Server* s = new MySerialServer();
    Solver<string, string>* solver = new StringReverser();
    ClientHandler* ch = new MyTestClientHandler<string ,string>(2, solver);
    s->open(5400, ch);

    return 0;
}