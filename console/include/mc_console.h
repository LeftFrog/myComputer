//
// Created by Leonov Oleksandr on 11/28/24.
//

#ifndef MY_CONSOLE_H
#define MY_CONSOLE_H

#include "../../terminal/include/mc_window.h"

struct mc_window mc_memoryWidnow = { 0, 0, 61, 12, "Memory" };
struct mc_window mc_accumulatorWindow = { 62, 0, 20, 3, "Accumulator" };
struct mc_window mc_instructionCounterWindow = { 62, 3, 20, 3, "InstructionCounter" };
struct mc_window mc_operationWindow = { 62, 6, 20,  3, "Operation" };
struct mc_window mc_flags = { 62, 9, 20, 3, "Flags" };

#endif // MY_CONSOLE_H