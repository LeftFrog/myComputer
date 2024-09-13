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

int mc_printBigChar(int arr[2], int x, int y, enum mc_colors fg, enum mc_colors bg) {
    mc_setBackgroundColor(bg);
    mc_setForegroundColor(fg);
    for (int row = 0; row < 8; ++row) {
        mc_goto(x, y + row);
        for (int col = 0; col < 8; ++col) {
            int bitPos = row * 8 + col; // Bit position in the integer array
            int intIndex = bitPos / 32; // Index of the integer in the array
            int bitIndex = bitPos % 32; // Bit position within the integer
            int bit = (arr[intIndex] >> (31 - bitIndex)) & 1; // Extract the bit

            if (bit) {
                printf("▒");
            } else {
                printf(" ");
            }
        }
        printf("\n"); // Move to the next row
    }
    mc_resetColors();
}

int mc_setBigCharPos(int *big, int x, int y, int value) {
    if (x < 0 || x > 7 || y < 0 || y > 7 || value < 0 || value > 1) {
        return -1;
    }

    int bigPos = y * 8 + x; // Position in the array
    int intIndex = bigPos / 32; // Index of the integer in the array
    int bitIndex = bigPos % 32; // Bit position within the integer

    if (value) {
        big[intIndex] |= 1 << (31 - bitIndex); // Set the bit
    } else {
        big[intIndex] &= ~(1 << (31 - bitIndex));
    }
}

int mc_getBigCharPos(int* big, int x, int y, int* value) {
    if (x < 0 || x > 7 || y < 0 || y > 7) {
        return -1;
    }

    int bigPos = y * 8 + x;
    int intIndex = bigPos / 32;
    int bitIndex = bigPos % 32;

    *value = (big[intIndex] >> (31 - bitIndex) & 1);
    return 0;
}
