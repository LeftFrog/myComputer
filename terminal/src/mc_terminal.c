#include <stdio.h>
#include "../include/mc_terminal.h"

#define ESC "\033"
#define CSI ESC "["
#define CLEAR_SCREEN CSI "2J"
#define RETURN_CURSOR CSI "H"

int mc_clrscr() {
    printf("%s", CLEAR_SCREEN);
    printf("%s", RETURN_CURSOR);
    fflush(stdout);
    return 0;
}
