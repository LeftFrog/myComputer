//
// Created by Leonov Oleksandr on 9/5/24.
//

#ifndef MC_TERMINAL_H
#define MC_TERMINAL_H

#include "mc_colors.h"

int mc_clrscr();
int mc_goto(int x, int y);
int mc_getScreenSize(int *rows, int *cols);
int mc_setForegroundColor(enum mc_colors color);
int mc_setBackgroundColor(enum mc_colors color);
int mc_resetColors();

#endif //MC_TERMINAL_H
