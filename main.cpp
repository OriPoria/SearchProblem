#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Searchable.h"
#include "ObjectAdapter.h"
#include "SearchClientHandler.h"
#include <iostream>

int main() {

    server_side::Server *s = new MySerialServer();

    Searcher<square, string> *searcher = new BFS<square, string>();

    Solver<Searchable<square>*, string> *solver = new ObjectAdapter<square, string>(searcher);

    ClientHandler *ch = new SearchClientHandler<Searchable<square>*, string>(solver);

    s->open(5400, ch);

    return 0;
}