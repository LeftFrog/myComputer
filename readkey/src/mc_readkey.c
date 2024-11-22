//
// Created by Leonov Oleksandr on 11/19/24.
//

#include "../include/mc_readkey.h"
#include <string.h>
#include <unistd.h>
#include <termios.h>

struct termios oldt, newt;

typedef struct {
    const char* seq;
    enum mc_keys key;
} KeyMap;

static KeyMap keyMap[] = {
    {"\033[A", MC_KEY_UP},
    {"\033[B", MC_KEY_DOWN},
    {"\033[C", MC_KEY_RIGHT},
    {"\033[D", MC_KEY_LEFT},
    {"\033OP", MC_KEY_F1},
    {"\033OQ", MC_KEY_F2},
    {"\033OR", MC_KEY_F3},
    {"\033OS", MC_KEY_F4},
    {"\033[15~", MC_KEY_F5},
    {"\033[17~", MC_KEY_F6},
    {"\033[18~", MC_KEY_F7},
    {"\033[19~", MC_KEY_F8},
    {"\033[20~", MC_KEY_F9},
    {"\033[21~", MC_KEY_F10},
    {"\033[23~", MC_KEY_F11},
    {"\033[24~", MC_KEY_F12},
    {"\n", KEY_ENTER},
    {"\b", KEY_BACKSPACE},
    {"\t", KEY_TAB},
    {"\033", KEY_ESC},
};

int mc_readkey(enum mc_keys* key) {
    char buf[8] = {0};
    ssize_t bytesRead = read(STDIN_FILENO, buf, sizeof(buf));

    if (bytesRead <= 0) {
        return -1;
    }

    buf[bytesRead] ='\0';

    for (size_t i = 0; i < sizeof(keyMap) / sizeof(keyMap[0]); ++i) {
        if (strcmp(buf, keyMap[i].seq) == 0) {
            *key = keyMap[i].key;
            return 0;
        }
    }

    if (buf[0] >= 'A' && buf[0] <= 'Z') {
        *key = buf[0];
        return 0;
    }
    if (buf[0] >= '0' && buf[0] <= '9') {
        *key = buf[0];
        return 0;
    }

    *key = KEY_UNKNOWN;
    return 0;
}

int mc_mytermsave() {
    if (tcgetattr(STDIN_FILENO, &oldt) != 0) {
        return -1;
    }

    return 0;
}

int mc_mytermrestore() {
    if (tcsetattr(STDIN_FILENO, TCSANOW, &oldt) != 0) {
        return -1;
    }
}

int mc_mytermregime(int regime, int vtime, int vmin, int echo, int sigint) {
    newt = oldt;

    if (tcgetattr(0, &newt) != 0) {
        return -1;
    }

    if (regime) {
        newt.c_lflag |= ICANON;
    } else {
        newt.c_lflag &= ~ICANON;
    }

    if (echo) {
        newt.c_lflag |= ECHO;
    } else {
        newt.c_lflag &= ~ECHO;
    }

    if (sigint) {
        newt.c_lflag |= ISIG;
    } else {
        newt.c_lflag &= ~ISIG;
    }

    newt.c_cc[VTIME] = vtime;
    newt.c_cc[VMIN] = vmin;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) != 0) {
        return -1;
    }

    return 0;
}

