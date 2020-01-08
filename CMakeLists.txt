cmake_minimum_required(VERSION 3.15)
project(untitled6)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled6 main.cpp ClientHandler.h Server.cpp Server.h MySerialServer.cpp MySerialServer.h Solver.cpp Solver.h)