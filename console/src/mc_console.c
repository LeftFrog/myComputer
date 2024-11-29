//
// Created by Leonov Oleksandr on 11/28/24.
//

#include "../include/mc_console.h"

struct mc_window mc_memoryWidnow = { 0, 0, 61, 12, "Memory" };
struct mc_window mc_accumulatorWindow = { 62, 0, 20, 3, "Accumulator" };
struct mc_window mc_instructionCounterWindow = { 62, 3, 20, 3, "InstructionCounter" };
struct mc_window mc_operationWindow = { 62, 6, 20,  3, "Operation" };
struct mc_window mc_flagsWindow = { 62, 9, 20, 3, "Flags" };

int mc_drawConsole() {
    mc_drawWindow(&mc_memoryWidnow);
    mc_drawWindow(&mc_accumulatorWindow);
    mc_drawWindow(&mc_instructionCounterWindow);
    mc_drawWindow(&mc_operationWindow);
    mc_drawWindow(&mc_flagsWindow);
    return 0;
}