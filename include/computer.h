#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H
#include <stdint.h>

#define MEMORY_SIZE 256

int16_t memory[MEMORY_SIZE];

uint8_t computerRegister;   // 8-bit register
#define STACK_OVERFLOW_FLAG 0b00000001
#define DIVISION_BY_ZERO_FLAG 0b00000010
#define MEMORY_OUT_OF_BOUNDS_FLAG 0b00000100
#define CLOCK_PULSE_IGNORED_FLAG 0b00001000
#define INVALID_INSTRUCTION_FLAG 0b00010000

int memoryInit();
int memorySet(uint8_t address, int16_t value);

#endif //UNTITLED_LIBRARY_H
