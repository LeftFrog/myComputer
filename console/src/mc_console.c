//
// Created by Leonov Oleksandr on 11/28/24.
//

#include "../include/mc_console.h"
#include "../../terminal/include/mc_terminal.h"
#include "../../include/mc_computer.h"
#include <stdio.h>

struct mc_window mc_memoryWidnow = { 0, 0, 61, 12, "Memory" };
struct mc_window mc_accumulatorWindow = { 62, 0, 20, 3, "Accumulator" };
struct mc_window mc_instructionCounterWindow = { 62, 3, 20, 3, "InstructionCounter" };
struct mc_window mc_operationWindow = { 62, 6, 20,  3, "Operation" };
struct mc_window mc_flagsWindow = { 62, 9, 20, 3, "Flags" };

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
}

int mc_drawConsole() {
    mc_drawMemory();
    mc_drawAccumulator();
    mc_drawWindow(&mc_instructionCounterWindow);
    mc_drawWindow(&mc_operationWindow);
    mc_drawWindow(&mc_flagsWindow);
    return 0;
}
