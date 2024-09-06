#include <stdio.h>
#include <unistd.h>
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

int mc_goto(int x, int y) {
    char buffer[30];
    int length = snprintf(buffer, sizeof(buffer), CSI "%d;%dH", y, x);
    write(STDOUT_FILENO, buffer, length);
    return 0;
}
