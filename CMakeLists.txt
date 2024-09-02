cmake_minimum_required(VERSION 3.28)
project(myComputer LANGUAGES C VERSION 0.0.2)

set(CMAKE_C_STANDARD 11)

add_library(myComputer STATIC src/computer.c
        include/computer.h
        include/mc_assembly.h)
