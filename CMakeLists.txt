cmake_minimum_required(VERSION 3.28)
project(myComputer LANGUAGES C VERSION 0.0.3)

set(CMAKE_C_STANDARD 11)

add_library(myComputer STATIC src/computer.c
        include/computer.h
        include/mc_assembly.h)

add_library(myTerminal STATIC terminal/src/mc_terminal.c
        terminal/include/mc_terminal.h)