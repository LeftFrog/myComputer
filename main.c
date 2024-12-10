//
// Created by Leonov Oleksandr on 11/19/24.
//

#include <stdio.h>

#include "console/include/mc_console.h"
#include "terminal/include/mc_terminal.h"

int main(void) {
    mc_clrscr();
    mc_initConsole();
    printf(mc_getFormattedMemoryValue(0x43FF));
    int rows, cols;
    mc_getScreenSize(&rows, &cols);
    mc_goto(cols, 25);

    return 0;
}