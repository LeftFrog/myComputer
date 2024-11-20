//
// Created by Leonov Oleksandr on 11/19/24.
//

#ifndef MC_READKEY_H
#define MC_READKEY_H

enum mc_keys {
    // Letters
    MC_KEY_A = 'A', MC_KEY_B = 'B', MC_KEY_C = 'C', MC_KEY_D = 'D', MC_KEY_E = 'E', MC_KEY_F = 'F', MC_KEY_G = 'G',
    MC_KEY_H = 'H', MC_KEY_I = 'I', MC_KEY_J = 'J', MC_KEY_K = 'K', MC_KEY_L = 'L', MC_KEY_M = 'M', MC_KEY_N = 'N',
    MC_KEY_O = 'O', MC_KEY_P = 'P', MC_KEY_Q = 'Q', MC_KEY_R = 'R', MC_KEY_S = 'S', MC_KEY_T = 'T', MC_KEY_U = 'U',
    MC_KEY_V = 'V', MC_KEY_W = 'W', MC_KEY_X = 'X', MC_KEY_Y = 'Y', MC_KEY_Z = 'Z',

    // Numbers
    MC_KEY_0 = '0', MC_KEY_1 = '1', MC_KEY_2 = '2', MC_KEY_3 = '3', MC_KEY_4 = '4', MC_KEY_5 = '5', MC_KEY_6 = '6',
    MC_KEY_7 = '7', MC_KEY_8 = '8', MC_KEY_9 = '9',

    // Arrow keys
    MC_KEY_UP, MC_KEY_DOWN, MC_KEY_RIGHT, MC_KEY_LEFT,

    // Function keys
    MC_KEY_F1, MC_KEY_F2, MC_KEY_F3, MC_KEY_F4, MC_KEY_F5, MC_KEY_F6, MC_KEY_F7, MC_KEY_F8, MC_KEY_F9, MC_KEY_F10,
    MC_KEY_F11, MC_KEY_F12,

    // Control keys
    KEY_ENTER, KEY_BACKSPACE, KEY_TAB, KEY_ESC,

    KEY_UNKNOWN
};

int mc_readkey(enum mc_keys *);
int mc_mytermsave();
int mc_mytermrestore();
int mc_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif //MC_READKEY_H
