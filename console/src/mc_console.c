//
// Created by Leonov Oleksandr on 11/28/24.
//

#include "../include/mc_console.h"
#include "../../terminal/include/mc_terminal.h"
#include "../../include/mc_computer.h"
#include "../../bigchar/include/mc_bigchar.h"
#include <stdio.h>
#include <stdlib.h>

#define MC_CHARMAP_SIZE 18

struct mc_window mc_memoryWidnow = { 0, 0, 61, 12, "Memory" };
struct mc_window mc_accumulatorWindow = { 62, 0, 20, 3, "Accumulator" };
struct mc_window mc_instructionCounterWindow = { 62, 3, 20, 3, "InstructionCounter" };
struct mc_window mc_operationWindow = { 62, 6, 20,  3, "Operation" };
struct mc_window mc_flagsWindow = { 62, 9, 20, 3, "Flags" };
struct mc_window mc_currentMemoryCellWindow = { 0, 12, 46, 10, ""};
struct mc_window mc_keysWindow = { 46, 12, 35, 10, "" };

uint8_t mc_currentCell = 0;

struct mc_bigChar chars[18];

typedef struct {
    char ch;
    struct mc_bigChar bigChar;
} CharMap;

CharMap charMap[MC_CHARMAP_SIZE];

int loadChars() {
    FILE* file = fopen("bigChar.bin", "rb");
    if (file == NULL) {
        return -1;
    }
    mc_bigCharsRead(fileno(file), chars, MC_CHARMAP_SIZE, NULL);
    fclose(file);
    return 0;
}

char* mc_getFormattedMemoryValue(int16_t value) {
    char* string = malloc(6);
    if (value < 0) {
        sprintf(string, "-%04X", (value & 0x7FFF));
    } else {
        sprintf(string, "+%04X", value);
    }
    return string;
}

int mc_initConsole() {
    mc_clrscr();
    loadChars();
    charMap[0] = (CharMap){ '+', chars[0] };
    charMap[1] = (CharMap){ '-', chars[1] };
    charMap[2] = (CharMap){ '0', chars[2] };
    charMap[3] = (CharMap){ '1', chars[3] };
    charMap[4] = (CharMap){ '2', chars[4] };
    charMap[5] = (CharMap){ '3', chars[5] };
    charMap[6] = (CharMap){ '4', chars[6] };
    charMap[7] = (CharMap){ '5', chars[7] };
    charMap[8] = (CharMap){ '6', chars[8] };
    charMap[9] = (CharMap){ '7', chars[9] };
    charMap[10] = (CharMap){ '8', chars[10] };
    charMap[11] = (CharMap){ '9', chars[11] };
    charMap[12] = (CharMap){ 'A', chars[12] };
    charMap[13] = (CharMap){ 'B', chars[13] };
    charMap[14] = (CharMap){ 'C', chars[14] };
    charMap[15] = (CharMap){ 'D', chars[15] };
    charMap[16] = (CharMap){ 'E', chars[16] };
    charMap[17] = (CharMap){ 'F', chars[17] };
    mc_registerSet(MC_STACK_OVERFLOW_FLAG, 1);
    return 0;
}

int mc_drawMemory() {
    mc_drawWindow(&mc_memoryWidnow);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            mc_goto(mc_memoryWidnow.x + 1 + j*6 , mc_memoryWidnow.y + 1 + i);
            int16_t value = mc_memory[i*10 + j];
            printf(mc_getFormattedMemoryValue(value));
        }
    }
    return 0;
}

int mc_drawAccumulator() {
    mc_drawWindow(&mc_accumulatorWindow);
    int startx = mc_accumulatorWindow.x + mc_accumulatorWindow.width / 2 - 3;
    mc_goto(startx , mc_accumulatorWindow.y + 1);
    printf(mc_getFormattedMemoryValue(mc_accumulator));
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

int mc_drawCurrentMemoryCell() {
    mc_drawWindow(&mc_currentMemoryCellWindow);
    int16_t value = mc_memory[mc_currentCell];
    mc_memoryGet(mc_currentCell, &value);
    char* string = mc_getFormattedMemoryValue(value);
    int startx = mc_currentMemoryCellWindow.x + 1;
    int starty = mc_currentMemoryCellWindow.y + 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < MC_CHARMAP_SIZE; j++) {
            if (string[i] == charMap[j].ch) {
                mc_printBigCharNoColor(charMap[j].bigChar.value, startx + i*9, starty);
                break;
            }

        }
    }
    free(string);
    return 0;
}

int mc_drawFlags() {
    mc_drawWindow(&mc_flagsWindow);
    int x = mc_flagsWindow.x + 6;
    mc_goto(x, mc_flagsWindow.y + 1);
    uint8_t value;

    mc_registerGet(MC_STACK_OVERFLOW_FLAG, &value);
    if (value) {
        mc_setBackgroundColor(MC_COLOR_144);
    }
    printf("S");
    mc_resetColors();


    x += 2;
    mc_goto(x, mc_flagsWindow.y + 1);
    mc_registerGet(MC_DIVISION_BY_ZERO_FLAG, &value);
    if (value) {
        mc_setBackgroundColor(MC_COLOR_144);
    }
    printf("D");
    mc_resetColors();

    x += 2;
    mc_goto(x, mc_flagsWindow.y + 1);
    mc_registerGet(MC_MEMORY_OUT_OF_BOUNDS_FLAG, &value);
    if (value) {
        mc_setBackgroundColor(MC_COLOR_144);
    }
    printf("M");
    mc_resetColors();

    x += 2;
    mc_goto(x, mc_flagsWindow.y + 1);
    mc_registerGet(MC_CLOCK_PULSE_IGNORED_FLAG, &value);
    if (value) {
        mc_setBackgroundColor(MC_COLOR_144);
    }
    printf("C");
    mc_resetColors();

    x += 2;
    mc_goto(x, mc_flagsWindow.y + 1);
    mc_registerGet(MC_INVALID_INSTRUCTION_FLAG, &value);
    if (value) {
        mc_setBackgroundColor(MC_COLOR_144);
    }
    printf("I");
    mc_resetColors();

    return 0;
}

int mc_drawConsole() {
    mc_drawMemory();
    mc_drawAccumulator();
    mc_drawWindow(&mc_instructionCounterWindow);
    mc_drawWindow(&mc_operationWindow);
    mc_drawFlags();
    mc_drawCurrentMemoryCell();
    mc_drawKeys();
    return 0;
}
