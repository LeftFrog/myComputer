cmake_minimum_required(VERSION 3.28)
project(myComputer C VERSION 0.0.1)

set(CMAKE_C_STANDARD 11)

add_library(myComputer STATIC library.c)
