//
// Created by Leonov Oleksandr on 9/11/24.
//

#include <stdio.h>
#include "../../terminal/include/mc_terminal.h"
#include "../include/mc_bigchar.h"

int mc_printA(char *str) {
    printf("%s\n", str);
    return 0;
}

int mc_box(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) {
        return -1;
    }

    mc_goto(x1, y1);
    for(int y = y1; y <= y2; y++) {
        for(int x = x1; x <= x2; x++) {
            if (x == x1 && y == y1) {
                printf("┌");
            } else if (x == x2 && y == y1) {
                printf("┐");
            } else if (x == x1 && y == y2) {
                printf("└");
            } else if (x == x2 && y == y2) {
                printf("┘");
            } else if (x > x1 && x < x2 && (y == y1 || y == y2)) {
                printf("─");
            } else if (y > y1 && y < y2 && (x == x1 || x == x2)) {
                printf("│");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        mc_goto(x1, y + 1);
    }
    return 0;
}
