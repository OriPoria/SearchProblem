#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Searchable.h"
#include "ObjectAdapter.h"
#include "SearchClientHandler.h"
#include "BFS.h"
#include <iostream>
#include "FileCacheManager.h"
#include "BestFirstSearch.h"
#include "AStarsearch.h"
#include "MyParallelServer.h"

int main() {

    server_side::Server *s = new MyParallelServer();
    //Searcher<square*, string> *searcher = new DFS<square*>();


  // Searcher<square*, string> *searcher = new BFS<square*>();

 Searcher<square*, string> *searcher = new BestFirstSearch<square*>();

// Searcher<square*, string> *searcher = new AStarsearch<square*>();

    Solver<Searchable<square*> *, string> *solver = new ObjectAdapter<square*, string>(searcher);

    CacheManager<string,string>*cache_manager = new FileCacheManager();

    ClientHandler *ch = new SearchClientHandler<Searchable<square*> *, string>(solver,cache_manager);

    s->open(5400, ch);


    return 0;
}