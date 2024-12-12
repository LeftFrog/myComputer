//
// Created by Leonov Oleksandr on 11/28/24.
//

#ifndef MY_CONSOLE_H
#define MY_CONSOLE_H

#include "../../terminal/include/mc_window.h"
#include <stdint.h>

extern struct mc_window mc_memoryWidnow;
extern struct mc_window mc_accumulatorWindow;
extern struct mc_window mc_instructionCounterWindow;
extern struct mc_window mc_operationWindow;
extern struct mc_window mc_flagsWindow;
extern struct mc_window mc_currentMemoryCellWindow;
extern struct mc_window mc_keysWindow;

extern uint8_t mc_currentCell;

char* mc_getFormattedMemoryValue(int16_t value);

int mc_initConsole();
int mc_drawMemory();
int mc_drawAccumulator();
int mc_drawKeys();
int mc_drawCurrentMemoryCell();
int mc_drawFlags();
int mc_drawConsole();
#endif // MY_CONSOLE_H