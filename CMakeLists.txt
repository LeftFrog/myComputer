cmake_minimum_required(VERSION 3.28)
project(myComputer LANGUAGES C VERSION 0.0.6)

set(CMAKE_C_STANDARD 11)

add_library(myComputer STATIC src/mc_computer.c
        include/mc_computer.h
        include/mc_assembly.h)

add_library(myTerminal STATIC terminal/src/mc_terminal.c
        terminal/include/mc_terminal.h
        terminal/include/mc_colors.h
        terminal/include/mc_window.h
        terminal/src/mc_window.c)

add_library(myBigChar STATIC bigchar/include/mc_bigchar.h
        bigchar/src/mc_bigchar.c
        console/include/mc_console.h)

add_library(myReadkey STATIC readkey/include/mc_readkey.h
        readkey/src/mc_readkey.c)

add_library(myConsole STATIC console/include/mc_console.h
        console/src/mc_console.c)

add_executable(myComputerProgram main.c)
target_link_libraries(myComputerProgram myConsole)
target_link_libraries(myComputerProgram myTerminal)