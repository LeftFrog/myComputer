//
// Created by Leonov Oleksandr on 11/22/24.
//

#include "../include/mc_window.h"

#include <stdio.h>

#include "../include/mc_terminal.h"

int mc_drawWindow(struct mc_window* window) {

    mc_clrscr();

    int screenRows, screenCols;
    mc_getScreenSize(&screenRows, &screenCols);

    if (window->x + window->width > screenCols || window->y + window->height > screenRows) {
        return -1;
    }
    // Draw top border
    mc_goto(window->x, window->y);
    printf("┌");
    for (int i = 0; i < window->width - 2; i++) {
        printf("─");
    }
    printf("┐");

    mc_goto(window->x,window->y + 1);
    printf("f");

    // Draw sides
    for (int i = 1; i < window->height - 1; i++) {
        mc_goto(window->x, window->y + i);
        printf("│");
        mc_goto(window->x + window->width - 1, window->y + i);
        printf("│");
    }

    // Draw bottom border
    mc_goto(window->x, window->y + window->height - 1);
    printf("└");
    for (int i = 0; i < window->width - 2; i++) {
        printf("─");
    }
    printf("┘");

    return 0;
}