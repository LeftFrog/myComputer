#ifndef MY_COMPUTER_H
#define MY_COMPUTER_H
#include <stdint.h>

#define MC_MEMORY_SIZE 100

int16_t mc_memory[MC_MEMORY_SIZE];

uint8_t mc_register;   // 8-bit register
#define MC_STACK_OVERFLOW_FLAG 0b00000001
#define MC_DIVISION_BY_ZERO_FLAG 0b00000010
#define MC_MEMORY_OUT_OF_BOUNDS_FLAG 0b00000100
#define MC_CLOCK_PULSE_IGNORED_FLAG 0b00001000
#define MC_INVALID_INSTRUCTION_FLAG 0b00010000

int mc_memoryInit();
int mc_memorySet(uint8_t address, int16_t value);

#endif // MY_COMPUTER_H
