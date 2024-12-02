//
// Created by Leonov Oleksandr on 11/28/24.
//

#include "../include/mc_console.h"
#include "../../terminal/include/mc_terminal.h"
#include "../../include/mc_computer.h"
#include "../../bigchar/include/mc_bigchar.h"
#include <stdio.h>

struct mc_window mc_memoryWidnow = { 0, 0, 61, 12, "Memory" };
struct mc_window mc_accumulatorWindow = { 62, 0, 20, 3, "Accumulator" };
struct mc_window mc_instructionCounterWindow = { 62, 3, 20, 3, "InstructionCounter" };
struct mc_window mc_operationWindow = { 62, 6, 20,  3, "Operation" };
struct mc_window mc_flagsWindow = { 62, 9, 20, 3, "Flags" };
struct mc_window mc_currentMemoryItemWindow = { 0, 12, 46, 10, ""};
struct mc_window mc_keysWindow = { 46, 12, 35, 10, "" };

struct mc_bigChar chars[18];

typedef struct {
    const char ch;
    const struct mc_bigChar;
} CharMap;

CharMap charMap[18];

int loadChars() {
    FILE* file = fopen("bigChar.bin", "rb");
    if (file == NULL) {
        return -1;
    }
    mc_bigCharsRead(fileno(file), chars, 1, NULL);
    fclose(file);
    return 0;
}

int initConsole() {
    mc_clrscr();
    loadChars();
    charMap[0] = (CharMap){ '+', chars[0].value };
    charMap[1] = (CharMap){ '-', chars[1].value };
    charMap[2] = (CharMap){ '0', chars[2].value };
    charMap[3] = (CharMap){ '1', chars[3].value };
    charMap[4] = (CharMap){ '2', chars[4].value };
    charMap[5] = (CharMap){ '3', chars[5].value };
    charMap[6] = (CharMap){ '4', chars[6].value };
    charMap[7] = (CharMap){ '5', chars[7].value };
    charMap[8] = (CharMap){ '6', chars[8].value };
    charMap[9] = (CharMap){ '7', chars[9].value };
    charMap[10] = (CharMap){ '8', chars[10].value };
    charMap[11] = (CharMap){ '9', chars[11].value };
    charMap[12] = (CharMap){ 'A', chars[12].value };
    charMap[13] = (CharMap){ 'B', chars[13].value };
    charMap[14] = (CharMap){ 'C', chars[14].value };
    charMap[15] = (CharMap){ 'D', chars[15].value };
    charMap[16] = (CharMap){ 'E', chars[16].value };
    charMap[17] = (CharMap){ 'F', chars[17].value };
    mc_drawConsole();
    return 0;
}

int mc_drawMemory() {
    mc_drawWindow(&mc_memoryWidnow);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mc_goto(mc_memoryWidnow.x + 1 + j*6 , mc_memoryWidnow.y + 1 + i);
            int16_t value = mc_memory[i*10 + j];
            if (value < 0) {
                printf("-%04X", -value);
            } else {
                printf("+%04X", value);
            }
        }
    }
    return 0;
}

int mc_drawAccumulator() {
    mc_drawWindow(&mc_accumulatorWindow);
    int startx = mc_accumulatorWindow.x + mc_accumulatorWindow.width / 2 - 3;
    mc_goto(startx , mc_accumulatorWindow.y + 1);
    if (mc_accumulator < 0) {
        printf("-%04X", -mc_accumulator);
    } else {
        printf("+%04X", mc_accumulator);
    }
    return 0;
}

int mc_drawKeys() {
    mc_drawWindow(&mc_keysWindow);

    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y);
    printf(" Keys: ");

    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 1);
    printf("l  - load");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 2);
    printf("s  - save");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 3);
    printf("r  - run");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 4);
    printf("t  - step");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 5);
    printf("i  - reset");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 6);
    printf("F5 - accumulator");
    mc_goto(mc_keysWindow.x + 1, mc_keysWindow.y + 7);
    printf("F6 - instruction counter");
}

int mc_drawConsole() {
    mc_drawMemory();
    mc_drawAccumulator();
    mc_drawWindow(&mc_instructionCounterWindow);
    mc_drawWindow(&mc_operationWindow);
    mc_drawWindow(&mc_flagsWindow);
    mc_drawWindow(&mc_currentMemoryItemWindow);
    mc_drawKeys();
    return 0;
}
