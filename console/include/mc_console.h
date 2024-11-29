//
// Created by Leonov Oleksandr on 11/28/24.
//

#ifndef MY_CONSOLE_H
#define MY_CONSOLE_H

#include "../../terminal/include/mc_window.h"

extern struct mc_window mc_memoryWidnow;
extern struct mc_window mc_accumulatorWindow;
extern struct mc_window mc_instructionCounterWindow;
extern struct mc_window mc_operationWindow;
extern struct mc_window mc_flagsWindow;

int mc_drawMemory();
int mc_drawConsole();
#endif // MY_CONSOLE_H