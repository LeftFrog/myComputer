#ifndef MY_COMPUTER_H
#define MY_COMPUTER_H
#include <stdint.h>

#define MC_MEMORY_SIZE 100

int16_t mc_memory[MC_MEMORY_SIZE];

int16_t mc_accumulator; // 16-bit register
uint8_t mc_register;   // 8-bit register

// Register flags
#define MC_STACK_OVERFLOW_FLAG 0b00000001
#define MC_DIVISION_BY_ZERO_FLAG 0b00000010
#define MC_MEMORY_OUT_OF_BOUNDS_FLAG 0b00000100
#define MC_CLOCK_PULSE_IGNORED_FLAG 0b00001000
#define MC_INVALID_INSTRUCTION_FLAG 0b00010000

int mc_initComputer();

// Memory operations
int mc_memoryInit();
int mc_memorySet(uint8_t address, int16_t value);
int mc_memoryGet(uint8_t address, int16_t *value);
int mc_memorySave(char *filename);
int mc_memoryLoad(char *filename);

// Register operations
int mc_registerInit();
int mc_registerSet(uint8_t registerNumber, uint8_t value);
int mc_registerGet(uint8_t registerNumber, uint8_t *value);

// Command operations
int mc_commandEncode(uint8_t command, uint8_t operand, uint16_t *value);
int mc_commandDecode(uint16_t value, uint8_t *command, uint8_t *operand);
#endif // MY_COMPUTER_H
