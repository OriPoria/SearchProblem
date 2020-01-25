#include "Boot.h"


int main(int argc, char* argv[]) {
    boot::Main m;
    m.main(atoi(argv[1]));
}