//
// Created by Leonov Oleksandr on 11/22/24.
//

#include "../include/mc_window.h"
#include <stdio.h>
#include "../include/mc_terminal.h"
#include <string.h>

int mc_drawWindow(struct mc_window* window) {
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

int mc_drawTitle(struct mc_window* window) {
    if (strlen(window->title) == 0 || strlen(window->title) > window->width - 2) {
        return -1;
    }
    int startx = window->x + window->width / 2 - strlen(window->title) / 2;
    mc_goto(startx, window->y);
    printf("%s", window->title);
    return 0;
}
