#include <stdio.h>
#include "../include/mc_terminal.h"

#define ESC "\033"
#define CSI ESC "["
#define CLEAR_SCREEN CSI "2J"

int mc_clrscr() {
    printf("%s", CLEAR_SCREEN);
    fflush(stdout);
    return 0;
}
