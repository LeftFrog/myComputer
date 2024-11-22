//
// Created by Leonov Oleksandr on 11/22/24.
//

#ifndef MC_WINDOW_H
#define MC_WINDOW_H

struct mc_window {
    int x;
    int y;
    int width;
    int height;
};

int mc_drawWindow(struct mc_window* window);

#endif //MC_WINDOW_H
