cmake_minimum_required(VERSION 3.17)
project(btree)

set(CMAKE_CXX_STANDARD 14)

add_executable(btree main.cpp Node.cpp Node.h Btree.cpp Btree.h)