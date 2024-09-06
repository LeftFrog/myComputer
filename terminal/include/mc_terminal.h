//
// Created by Leonov Oleksandr on 9/5/24.
//

#ifndef MC_TERMINAL_H
#define MC_TERMINAL_H

enum mc_colors {
    MC_BLACK = 0,
    MC_RED = 1,
    MC_GREEN = 2,
    MC_YELLOW = 3,
    MC_BLUE = 4,
    MC_MAGENTA = 5,
    MC_CYAN = 6,
    MC_WHITE = 7
};

int mc_clrscr();
int mc_goto(int x, int y);
int mc_getScreenSize(int *rows, int *cols);
int mc_setForegroundColor(enum mc_colors color);
int mc_setBackgroundColor(enum mc_colors color);

#endif //MC_TERMINAL_H
