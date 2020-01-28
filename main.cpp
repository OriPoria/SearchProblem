#include "Boot.h"


int main(int argc, char* argv[]) {
    boot::Main m;

    //default port is 5600, if we got the port as an argument, it will be the port
    int port = 5600;
    if (argc > 1) {
        port = atoi(argv[1]);
    }
    m.main(port);
}