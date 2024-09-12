//
// Created by Leonov Oleksandr on 9/11/24.
//

#ifndef MC_BIGCHAR_H
#define MC_BIGCHAR_H

int mc_printA(char *str);
int mc_box(int x1, int y1, int x2, int y2);
int mc_printBigChar(int [2], int x, int y, enum mc_colors fg, enum mc_colors bg);
int mc_setBigCharPos(int *big, int x, int y, int value);
int mc_getBigCharPos(int *big, int x, int y, int *value);
int mc_bigCharWrite(int fd, int *big, int count);
int mc_bigCharRead(int fd, int *big, int need_count, int *count);

#endif //MC_BIGCHAR_H