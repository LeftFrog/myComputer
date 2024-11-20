//
// Created by Leonov Oleksandr on 11/19/24.
//

#include "../include/mc_readkey.h"

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