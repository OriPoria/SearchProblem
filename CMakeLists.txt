cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(ex4 main.cpp ClientHandler.h  Server.h MySerialServer.cpp MySerialServer.h Solver.h MyTestClientHandler.h StringReverser.cpp StringReverser.h ObjectAdapter.h Searchable.h State.h SearchClientHandler.h Searcher.h CacheManager.h FileCacheManager.cpp FileCacheManager.h BFS.h MatrixProblem.h MatrixProblemCreator.h MySearcher.h BestFirstSearch.h)