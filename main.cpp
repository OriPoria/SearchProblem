#include "Server.h"
#include "MySerialServer.h"
#include <iostream>

int main() {

    MySerialServer* m = new MySerialServer();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}