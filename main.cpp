#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Searchable.h"
#include "ObjectAdapter.h"
#include "SearchClientHandler.h"
#include "BFS.h"
#include <iostream>
#include "CacheManager.h"
#include "FileCacheManager.h"

int main() {

    server_side::Server *s = new MySerialServer();

    Searcher<square, string> *searcher = new BFS<square, string>();

    Solver<Searchable<square>*, string> *solver = new ObjectAdapter<square, string>(searcher);

    CacheManager<string,string>*cache_manager = new FileCacheManager();

    ClientHandler *ch = new SearchClientHandler<Searchable<square>*, string>(solver,cache_manager);

    s->open(5400, ch);

    return 0;
}