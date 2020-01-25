//
// Created by ori on 22/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H


#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Searchable.h"
#include "ObjectAdapter.h"
#include "SearchClientHandler.h"
#include "BFS.h"
#include "DFS.h"
#include "FileCacheManager.h"
#include "BestFirstSearch.h"
#include "AStarsearch.h"
#include "MyParallelServer.h"

namespace boot {
    class Main;
}

class boot::Main {

public:
    Main() {};

    ~Main() {};

    int main(int port) {

        server_side::Server *s = new MyParallelServer();

        //here we can call any searcher we want
        Searcher<square *, string> *searcher = new AStarsearch<square *>();

        Solver<Searchable<square *> *, string> *solver = new ObjectAdapter<square *, string>(searcher);

        CacheManager<string, string> *cache_manager = new FileCacheManager();

        ClientHandler *ch = new SearchClientHandler<Searchable<square *> *, string>(solver, cache_manager);

        s->open(port, ch);


        return 0;
    }
};


#endif //EX4_BOOT_H
