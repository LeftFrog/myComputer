#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "../include/mc_terminal.h"

#define ESC "\033"
#define CSI ESC "["
#define CLEAR_SCREEN CSI "2J"
#define RETURN_CURSOR CSI "H"
#define SET_FOREGROUND_COLOR CSI "38;5;%dm"
#define SET_BACKGROUND_COLOR CSI "48;5;%dm"

int mc_clrscr() {
    printf("%s", CLEAR_SCREEN);
    printf("%s", RETURN_CURSOR);
    fflush(stdout);
    return 0;
}

int mc_goto(int x, int y) {
    printf(CSI "%d;%dH", y, x);
    return 0;
}

int mc_getScreenSize(int* rows, int* cols) {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
        return -1;
    }
    *rows = w.ws_row;
    *cols = w.ws_col;
    return 0;
}

int mc_setForegroundColor(enum mc_colors color) {
    printf(CSI "38;5;%dm", color);
    return 0;
}

int mc_setBackgroundColor(enum mc_colors color) {
    printf(SET_BACKGROUND_COLOR, color);
    return 0;
}

int mc_resetColors() {
    printf("%s", CSI "0m");
    return 0;
}
